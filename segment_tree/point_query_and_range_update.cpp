#include <bits/stdc++.h>
using namespace std;

//https://cses.fi/problemset/task/1651
// thiz iz not point update range query but range query and point update


struct FenwickTree {
    int n;
    vector<long long> bit;

    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void upd(int i, long long x) {
        for (++i; i <= n; i += i & (-i))
            bit[i] += x;
    }

    long long sum(int i) {
        long long s = 0;
        for (++i; i > 0; i -= i & (-i))
            s += bit[i];
        return s;
    }

    void range_upd(int l, int r, long long x) {
        upd(l, x);
        if (r + 1 < n)
            upd(r + 1, -x);
    }

    long long point_query(int i) {
        return sum(i);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    FenwickTree fenw(n);

    // Initialize Fenwick Tree with initial values using point updates (range update [i,i])
    for (int i = 0; i < n; i++) {
        fenw.range_upd(i, i, arr[i]);
    }

    while (q--) {
        int t; 
        cin >> t;
        if (t == 1) {
            int a, b; long long u;
            cin >> a >> b >> u;
            a--; b--;
            fenw.range_upd(a, b, u);
        } else {
            int k;
            cin >> k;
            k--;
            cout << fenw.point_query(k) << "\n";
        }
    }

    return 0;
}
