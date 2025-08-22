#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF (LLONG_MAX >> 1)
const int MOD = 1e9 + 7;

// ================= DEBUG SYSTEM =================
template <typename T>
typename enable_if<is_arithmetic<T>::value>::type
_print(const T &x) { cerr << x; }
void _print(const string &s) { cerr << '"' << s << '"'; }
void _print(const char &c) { cerr << '\'' << c << '\''; }
void _print(const bool &b) { cerr << (b ? "true" : "false"); }
template <typename T1, typename T2>
void _print(const pair<T1, T2> &p) {
    cerr << "[";
    _print(p.first); cerr << ", "; _print(p.second);
    cerr << "]";
}
template <typename... Ts, size_t... Is>
void _print_tuple_impl(const tuple<Ts...> &t, index_sequence<Is...>) {
    ((cerr << (Is ? ", " : ""), _print(get<Is>(t))), ...);
}
template <typename... Ts>
void _print(const tuple<Ts...> &t) {
    cerr << "[";
    _print_tuple_impl(t, index_sequence_for<Ts...>{});
    cerr << "]";
}
template <typename K, typename V>
void _print(const map<K, V> &m) {
    cerr << "[";
    bool first = true;
    for (auto &kv : m) {
        if (!first) cerr << ", ";
        cerr << "{";
        _print(kv.first);
        cerr << ": ";
        _print(kv.second);
        cerr << "}";
        first = false;
    }
    cerr << "]";
}
template <typename T>
typename enable_if<
    !is_same<decay_t<T>, string>::value &&
    !is_arithmetic<decay_t<T>>::value &&
    !is_same<decay_t<T>, map<typename T::key_type, typename T::mapped_type>>::value
>::type
_print(const T &x) {
    cerr << "[";
    bool first = true;
    for (auto &i : x) {
        if (!first) cerr << ", ";
        _print(i);
        first = false;
    }
    cerr << "]";
}
#define debug(x) cerr << #x << " = ", _print(x), cerr << "\n"

// ================= GLOBALS =================
map<int, pair<int, int>> time1;
map<int,int> parent_map;
int t = 0;

void dfs(int node, vector<vector<int>> &adj, int parent) {
    parent_map[node] = parent; // store parent
    time1[node].first = t++; // entry time
    cout << node << " ";
    for (auto child : adj[node]) {
        if (child == parent) continue;
        dfs(child, adj, node);
    }
    time1[node].second = t++; // exit time
}

void dfs_height(int node, vector<vector<int>> &adj, int parent, vector<int> &level, int l=0) {
    level[node]=l;
    for (auto child : adj[node]) {
        if (child == parent) continue;
        dfs_height(child, adj, node, level, l+1);
    }
}

bool isAncestor(int u, int v) {
    return (time1[u].first < time1[v].first && time1[v].second < time1[u].second);
}

void bfs(int root, vector<vector<int>> adj) {
    queue<pair<int,int>>q;
    q.push({root,0});
    while(!q.empty()) {
        int node = q.front().first;
        cout<<node<<" ";
        int parent = q.front().second;
        q.pop();
        for(auto child :adj[node]) {
            if(child == parent) continue;
            q.push({child,node});
        }
    }
}

void bfs_height(int root, vector<vector<int>> adj) {
    queue<pair<int,int>>q;
    q.push({root,0});
    int level=0;
    while(!q.empty()) {
        int k = q.size();
        for(int i=0;i<k;i++) {
            int node = q.front().first;
            cout<<node<<" ";
            int parent = q.front().second;
            q.pop();
            for(auto child :adj[node]) {
                if(child == parent) continue;
                q.push({child,node});
            }
        }
        level++;
        cout<<endl;
    }
    cout<<level<<endl;
}
//zubtree code
void dp_on_tree(int node, vector<vector<int>> &adj, int parent, vector<int> &dp) {
    dp[node]=1; 
    for(auto it:adj[node]) {
        if(it==parent) continue;
        dp_on_tree(it, adj, node, dp);
        dp[node]+=dp[it];
    }
}

// Function to get path from u to x using parent_map If x is an ancestor of u
vector<int> get_path(int u, int x) {
    vector<int> path;
    while (u != -1) {
        path.push_back(u);
        if (u == x) break;
        u = parent_map[u];
    }
    return path;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, adj, -1);
    cout << endl;
    debug(time1);

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (isAncestor(u, v) ? "YES" : "NO") << endl;
    }
    bfs(1, adj);
    cout<<endl;

    vector<int>level(n+1,0);
    dfs_height(1, adj, -1, level); 
    int maxi = *max_element(level.begin(), level.end());
    cout<<maxi<<endl;

    vector<int>dp(n+1,0);
    dp_on_tree(1, adj, -1, dp);
    for(int i=1;i<=n;i++){
        cout<<"Subtree size of "<<i<<" = "<<dp[i]<<endl;
    }

    // Path printing part
    int start, end;
    cin >> start >> end;
    vector<int> path = get_path(start, end);
    cout << "Path from " << start << " to " << end << ": ";
    for (int node : path) cout << node << " ";
    cout << endl;
}
 