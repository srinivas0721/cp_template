#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 +7;

// ---------------- DFS for connected graph ----------------
void dfs(int curr, vector<vector<int>>& edges, vector<int>& visited) {
    visited[curr] = true;  // Mark current node as visited
    for (auto it : edges[curr]) {
        if (!visited[it]) {
            dfs(it, edges, visited); // Recursively visit neighbors
        }
    }
}

// ---------------- DFS for disconnected graph (mark components) ----------------
void dfs_disconnected_graph(int curr, vector<vector<int>>& edges, vector<int>& visited1, int cnt, vector<int>& component) {
    visited1[curr] = true;          
    component[curr] = cnt; // mark this node as belonging to component 'cnt'
    for (auto it : edges[curr]) {
        if (!visited1[it]) {
            dfs_disconnected_graph(it, edges, visited1, cnt, component);
        }
    }
}

// ---------------- DFS for cycle detection ----------------
bool dfs_cycle_detection(int curr, vector<vector<int>>& edges, vector<int>& visited2, int parent) {
    visited2[curr] = true;          
    for (auto it : edges[curr]) {
        if (it == parent) continue; // ignore edge to parent
        if (!visited2[it]) {
            if (dfs_cycle_detection(it, edges, visited2, curr)) 
                return true; // cycle found
        }
        else {
            return true; // back edge found => cycle detected
        }
    }
    return false;
}

// ---------------- DFS for path (parent vector method) ----------------
void dfs_with_parent(int curr, vector<vector<int>>& edges, vector<int>& visited, vector<int>& parent) {
    visited[curr] = true;
    for (auto it : edges[curr]) {
        if (!visited[it]) {
            parent[it] = curr;        // record parent relation
            dfs_with_parent(it, edges, visited, parent);
        }
    }
}

// ---------------- DFS for Bipartite Check (your style) ----------------
void dfs_bipartite(int curr, vector<vector<int>>& edges, vector<int>& color, bool& isBipartite) {
    for (int neighbor : edges[curr]) {
        if (color[neighbor] == 0) {         // unvisited neighbor
            color[neighbor] = 3 - color[curr]; // assign opposite color
            dfs_bipartite(neighbor, edges, color, isBipartite); // recursive call
        } else if (color[neighbor] == color[curr]) { 
            isBipartite = false; // same color neighbor => not bipartite
        }
    }
}

signed main () {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m; // number of nodes, number of edges

    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // edge between u and v
        edges[u].push_back(v);
        edges[v].push_back(u); // undirected graph
    }

    // ---------------- Simple DFS from node 0 ----------------
    vector<int> visited(n, false);
    dfs(0, edges, visited);

    // ---------------- BFS for graph traversal ----------------
    queue<int> q;
    vector<int> parent(n, -1); // keep track of parents
    vector<int> visited_bfs(n, false);

    q.push(0);
    visited_bfs[0] = true;
    while (!q.empty()) {
        int top = q.front();
        cout << top << " "; // print traversal order
        q.pop();
        for (int it : edges[top]) {
            if (it == parent[top]) continue; // ignore parent edge
            if (!visited_bfs[it]) {
                visited_bfs[it] = true;
                parent[it] = top;
                q.push(it);
            }
            else {
                cout << "Cycle Detected" << endl;
            }
        }
    }
    cout << endl;

    // ---------------- Disconnected Graph Components ----------------
    vector<int> component(n);
    int cnt = 0;
    vector<int> visited1(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited1[i]) {
            dfs_disconnected_graph(i, edges, visited1, cnt, component);
            cnt++;
        }
    }

    cout << "Total Components = " << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " in Component " << component[i] << endl;
    }

    // ---------------- Cycle Detection ----------------
    vector<int> visited2(n, false);
    bool cycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited2[i]) {
            if (dfs_cycle_detection(i, edges, visited2, -1)) {
                cycle = true;
                break;
            }
        }
    }
    if (cycle) cout << "Cycle Detected in Graph" << endl;
    else cout << "No Cycle Found" << endl;

    // ---------------- Path Printing (DFS with parent) ----------------
    int a, b;
    cout << "Enter source and destination to print path: ";
    cin >> a >> b;

    vector<int> parent_path(n, -1);
    vector<int> visited_path(n, false);

    dfs_with_parent(a, edges, visited_path, parent_path);

    if (parent_path[b] == -1 && a != b) {
        cout << "No Path Exists between " << a << " and " << b << endl;
    } else {
        vector<int> path;
        for (int v = b; v != -1; v = parent_path[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        cout << "Path from " << a << " to " << b << ": ";
        for (auto node : path) cout << node << " ";
        cout << endl;
    }

    // ---------------- Bipartite Check ----------------
    vector<int> color(n, 0); // 0 = unvisited, 1 = color1, 2 = color2
    bool isBipartite = true;

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            color[i] = 1; // start with color 1
            dfs_bipartite(i, edges, color, isBipartite);
        }
    }

    if (isBipartite) cout << "Graph is Bipartite" << endl;
    else cout << "Graph is Not Bipartite" << endl;

    return 0;
}
