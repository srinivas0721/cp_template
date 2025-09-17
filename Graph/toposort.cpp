#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF (LLONG_MAX >> 1)
const int MOD = 1e9 + 7;

// DFS based topo sort
void dfs(int node, vector<int>& visited, stack<int>& st, vector<vector<int>>& adj) {
    visited[node] = 1;
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, visited, st, adj);
        }
    }
    st.push(node); // push after visiting all children
}
//with cycle detection
bool dfs(int node, vector<int>& visited, stack<int>& st, vector<vector<int>>& adj) {
    visited[node] = 1; // visiting
    for (auto it : adj[node]) {
        if (visited[it] == 1) return false; // cycle detected 🚨
        if (visited[it] == 0) {
            if (!dfs(it, visited, st, adj)) return false;
        }
    }
    visited[node] = 2; // done
    st.push(node);
    return true;
}


// BFS (Kahn's algorithm) topo sort
vector<int> kahnTopo(int n, vector<vector<int>>& adj, vector<int>& indeg) {
    queue<int> q;
    vector<int> topo;

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        topo.push_back(x);

        for (auto it : adj[x]) {
            indeg[it]--;
            if (indeg[it] == 0) {
                q.push(it);
            }
        }
    }

    return topo;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed graph
        indeg[v]++;
    }

    // --- Topo sort using DFS ---
    vector<int> visited(n + 1, 0);
    stack<int> st;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, st, adj);
        }
    }

    cout << "DFS Topo Order: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    // --- Topo sort using BFS (Kahn’s Algo) ---
    vector<int> topo = kahnTopo(n, adj, indeg);

    cout << "BFS Topo Order: ";
    for (auto it : topo) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
