#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
const int INF = LLONG_MAX >> 1;
const int MOD = 1e9 + 7;

vector<int> segTree, lazy;

int merge(int a, int b) {
    return min(a, b);
}

void build(vector<int>& arr, int start, int end, int index) {
    if (start == end) {
        segTree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(arr, start, mid, 2 * index);
    build(arr, mid + 1, end, 2 * index + 1);
    segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
}

void propagate(int start, int end, int index) {
    if (lazy[index] != 0) {
        segTree[index] += lazy[index];
        if (start != end) { // not a leaf node
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
}

void update(int start, int end, int index, int l, int r, int value) {
    propagate(start, end, index);
    if (start > r || end < l) return; // no overlap
    if (start >= l && end <= r) {
        lazy[index] += value;
        propagate(start, end, index);
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, 2 * index, l, r, value);
    update(mid + 1, end, 2 * index + 1, l, r, value);
    segTree[index] = merge(segTree[2 * index], segTree[2 * index + 1]);
}

int query(int start, int end, int index, int l, int r) {
    propagate(start, end, index);
    if (start > r || end < l) return INF; // no overlap
    if (start >= l && end <= r) return segTree[index];
    int mid = (start + end) / 2;
    int leftAnswer = query(start, mid, 2 * index, l, r);
    int rightAnswer = query(mid + 1, end, 2 * index + 1, l, r);
    return merge(leftAnswer, rightAnswer);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        segTree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(arr, 0, n - 1, 1);
        while (q--) {
            int type; cin >> type;
            if (type == 1) {
                int l, r, x; cin >> l >> r >> x;
                // assuming 0-based indexing
                update(0, n - 1, 1, l, r, x);
            } else {
                int l, r; cin >> l >> r;
                cout << query(0, n - 1, 1, l, r) << endl;
            }
        }
    }
    return 0;
}
// Range updates: Add a value x to every element in a subrange [l, r] of the array efficiently (in O(log n) time).

// Range minimum queries: Find the minimum element in a subrange [l, r] efficiently (in O(log n) time).