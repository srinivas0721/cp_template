#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF (LLONG_MAX >> 1)
const int MOD = 1e9 + 7;

struct SparseTable {
    int n, LOG;
    vector<vector<int>> table;

    SparseTable(const vector<int> &a) {
        n = a.size();
        LOG = __lg(n) + 1;
        table.assign(n, vector<int>(LOG));
        for (int i = 0; i < n; i++)
            table[i][0] = a[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[i][j] = min(table[i][j - 1],
                                  table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int j = __lg(r - l + 1);
        return min(table[l][j], table[r - (1 << j) + 1][j]);
    }
};

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        SparseTable st(a);

        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << endl;
        }
    }

    return 0;
}
