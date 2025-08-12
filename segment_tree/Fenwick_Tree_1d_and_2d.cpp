#include <bits/stdc++.h>
using namespace std;

// 1D Fenwick Tree (BIT) for prefix sums and point updates
struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(const vector<int> &a) {
        n = (int)a.size();
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            upd(i, a[i]);
        }
    }

    // Add x to element at index i (0-based)
    void upd(int i, int x) {
        for (++i; i <= n; i += i & (-i))
            bit[i] += x;
    }

    // Prefix sum from 0 to i (inclusive)
    int sum(int i) {
        int s = 0;
        for (++i; i > 0; i -= i & (-i))
            s += bit[i];
        return s;
    }

    // Range sum query [l, r]
    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

// 2D Fenwick Tree (BIT) for prefix sums and point updates
struct FenwickTree2D {
    int n, m;
    vector<vector<int>> bit;

    FenwickTree2D(const vector<vector<int>> &a) {
        n = (int)a.size();
        m = (n > 0) ? (int)a[0].size() : 0;
        bit.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                upd(i, j, a[i][j]);
    }

    // Add x to element at (r, c) (0-based)
    void upd(int r, int c, int x) {
        for (int i = r + 1; i <= n; i += i & (-i))
            for (int j = c + 1; j <= m; j += j & (-j))
                bit[i][j] += x;
    }

    // Prefix sum from (0,0) to (r,c) inclusive
    int sum(int r, int c) {
        int s = 0;
        for (int i = r + 1; i > 0; i -= i & (-i))
            for (int j = c + 1; j > 0; j -= j & (-j))
                s += bit[i][j];
        return s;
    }

    // Range sum query from (r1, c1) to (r2, c2) inclusive
    int query(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1);
    }
};

int main() {
    // Example for 1D Fenwick Tree
    vector<int> arr1d = {1, 2, 3, 4, 5};
    FenwickTree fenw1d(arr1d);

    cout << "1D Fenwick Tree Example:\n";
    cout << "Sum of [0..4]: " << fenw1d.query(0, 4) << "\n"; // 15
    cout << "Sum of [1..3]: " << fenw1d.query(1, 3) << "\n"; // 9

    fenw1d.upd(2, 5); // add 5 to index 2 (arr[2] += 5)
    cout << "After adding 5 to index 2:\n";
    cout << "Sum of [0..4]: " << fenw1d.query(0, 4) << "\n"; // 20
    cout << "Value at index 2: " << fenw1d.query(2, 2) << "\n"; // 8 (3+5)

    cout << "\n";

    // Example for 2D Fenwick Tree
    vector<vector<int>> arr2d = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    FenwickTree2D fenw2d(arr2d);

    cout << "2D Fenwick Tree Example:\n";
    cout << "Sum of submatrix [(0,0) to (2,2)]: " << fenw2d.query(0, 0, 2, 2) << "\n"; // 45 (sum all)
    cout << "Sum of submatrix [(1,1) to (2,2)]: " << fenw2d.query(1, 1, 2, 2) << "\n"; // 5+6+8+9 = 28

    fenw2d.upd(1, 1, 10); // add 10 to element at (1,1)
    cout << "After adding 10 to (1,1):\n";
    cout << "Sum of submatrix [(1,1) to (2,2)]: " << fenw2d.query(1, 1, 2, 2) << "\n"; // 38
    cout << "Value at (1,1): " << fenw2d.query(1, 1, 1, 1) << "\n"; // 15 (5+10)

    return 0;
}
