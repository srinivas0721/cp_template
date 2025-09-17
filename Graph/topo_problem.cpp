#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

// https://codeforces.com/problemset/problem/510/C



// DFS with cycle detection
bool dfs(int node, vector<int>& visited, stack<int>& st, vector<vector<int>>& adj) {
    visited[node] = 1; // visiting
    for (auto it : adj[node]) {
        if (visited[it] == 1) return false; // cycle
        if (visited[it] == 0) {
            if (!dfs(it, visited, st, adj)) return false;
        }
    }
    visited[node] = 2; // done
    st.push(node);
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    vector<vector<int>> adj(26);

    // Build constraints
    for (int i = 0; i + 1 < n; i++) {
        string &a = words[i], &b = words[i + 1];
        int len = min(a.size(), b.size());
        bool found = false;
        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                found = true;
                break;
            }
        }
        if (!found && a.size() > b.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    vector<int> visited(26, 0);
    stack<int> st;

    // run topo DFS in reverse alphabet order
    for (int i = 0; i < 26; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, visited, st, adj)) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }


    while (!st.empty()) {
        cout << (char)('a' + st.top());
        st.pop();
    }
    cout << endl;

    return 0;
}
