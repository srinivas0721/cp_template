#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const long long INF = LLONG_MAX >> 1;

// ---------------- Set-based Dijkstra ----------------
void dijkstra_set(int src, int n, vector<vector<pair<int,long long>>> &edges, vector<long long> &dist, vector<int> &parent) {
    dist.assign(n, INF);
    parent.assign(n, -1);
    vector<bool> marked(n, false);
    dist[src] = 0;

    set<pair<long long,int>> toExplore; // {distance, node}
    toExplore.insert({0, src});

    while(!toExplore.empty()) {
        auto [distSoFar, poppedNode] = *toExplore.begin();
        toExplore.erase(toExplore.begin());

        if (marked[poppedNode]) continue;
        marked[poppedNode] = true;

        for (auto [node, weight] : edges[poppedNode]) {
            if (dist[node] > distSoFar + weight) {
                dist[node] = distSoFar + weight;
                parent[node] = poppedNode;
                toExplore.insert({dist[node], node});
            }
        }
    }
}

// ---------------- Priority Queue Dijkstra ----------------
void dijkstra_pq(int s, int n, vector<long long> &dist, vector<int> &parent, vector<vector<pair<int, long long>>> &adj) {
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[s] = 0;

    using P = pair<long long,int>; // {distance, node}
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});

    while (!q.empty()) {
        auto [d_v, v] = q.top();
        q.pop();

        if (d_v != dist[v]) continue; // stale entry

        for (auto [to, w] : adj[v]) {
            if (dist[v] + w < dist[to]) {
                dist[to] = dist[v] + w;
                parent[to] = v;
                q.push({dist[to], to});
            }
        }
    }
}

// ---------------- Bellman-Ford (your style, with early break) ----------------
bool bellman_ford(int n, int src, vector<vector<pair<int,long long>>> &adj,
                  vector<long long> &dist, vector<int> &parent, set<int> &negCycle) {
    dist.assign(n, 0);
    parent.assign(n, -1);
    dist[src] = 0;

    // Flatten adjacency into edge list: {weight, {u, v}}
    vector<pair<long long, pair<int,int>>> e;
    for (int u = 0; u < n; u++) {
        for (auto [v, w] : adj[u]) {
            e.push_back({w, {u, v}});
        }
    }

    // Relax edges n-1 times with early break
    for (int i = 0; i < n - 1; i++) {
        bool changed = false;
        for (auto ed : e) {
            int u = ed.second.first;
            int v = ed.second.second;
            long long w = ed.first;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                changed = true;
            }
        }
        if (!changed) break; // 🔥 stop if no update
    }

    // Check negative cycles and collect all nodes in the cycle
    bool hasNeg = false;
    for (auto ed : e) {
        int u = ed.second.first;
        int v = ed.second.second;
        long long w = ed.first;
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            hasNeg = true;

            // move n steps to ensure inside cycle
            int x = v;
            for (int i = 0; i < n; i++) x = parent[x];

            // collect all nodes in the cycle
            int cur = x;
            while (negCycle.find(cur) == negCycle.end()) {
                negCycle.insert(cur);
                cur = parent[cur];
            }
        }
    }

    return hasNeg;
}

// ---------------- Path reconstruction ----------------
vector<int> get_path(int t, vector<int> &parent) {
    vector<int> path;
    for (int v = t; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m; // number of nodes, number of edges
    vector<vector<pair<int,long long>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // assuming 0-indexed nodes
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed graph
    }

    int src;
    cin >> src;

    vector<long long> dist;
    vector<int> parent;

    // ---------- Run set-based Dijkstra ----------
    dijkstra_set(src, n, adj, dist, parent);
    cout << "Set-based Dijkstra distances: ";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;

    // Path reconstruction (Set-based Dijkstra)
    {
        int target = n - 1;
        if (dist[target] == INF) {
            cout << "No path from " << src << " to " << target << " using Set-Dijkstra" << endl;
        } else {
            vector<int> path = get_path(target, parent);
            cout << "Path from " << src << " to " << target << " using Set-Dijkstra: ";
            for (int v : path) cout << v << " ";
            cout << endl;
        }
    }

    // ---------- Run priority-queue Dijkstra ----------
    dijkstra_pq(src, n, dist, parent, adj);
    cout << "PQ-based Dijkstra distances:  ";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;

    // Path reconstruction (PQ-based Dijkstra)
    {
        int target = n - 1;
        if (dist[target] == INF) {
            cout << "No path from " << src << " to " << target << " using PQ-Dijkstra" << endl;
        } else {
            vector<int> path = get_path(target, parent);
            cout << "Path from " << src << " to " << target << " using PQ-Dijkstra: ";
            for (int v : path) cout << v << " ";
            cout << endl;
        }
    }

    // ---------- Run Bellman-Ford ----------
    set<int> negCycle;
    bool hasNeg = bellman_ford(n, src, adj, dist, parent, negCycle);
    cout << "Bellman-Ford distances:       ";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;

    if (hasNeg) {
        cout << "Graph contains a negative cycle involving nodes: ";
        for (int v : negCycle) cout << v << " ";
        cout << endl;
    } else {
        // Path reconstruction only if no negative cycle
        int target = n - 1;
        if (dist[target] == INF) {
            cout << "No path from " << src << " to " << target << " using Bellman-Ford" << endl;
        } else {
            vector<int> path = get_path(target, parent);
            cout << "Path from " << src << " to " << target << " using Bellman-Ford: ";
            for (int v : path) cout << v << " ";
            cout << endl;
        }
    }

    return 0;
}
