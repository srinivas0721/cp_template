#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

template<typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<ll> arr;
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a) {
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n) s <<= 1;
        tree.resize(s);
        fill(all(tree), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) {
        if (start == end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u) {
        if (start == end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) {
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, ll val) {
        Update new_update = Update(val);
        update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }

    // ===== Added rangeCount method with min/max/cnt pruning =====
    int rangeCountQuery(ll L, ll R) {
        return rangeCount(0, n - 1, 1, L, R);
    }
private:
    int rangeCount(int start, int end, int idx, ll L, ll R) {
        Node &node = tree[idx];
        if (node.mx < L || node.mn > R) return 0; // no overlap
        if (node.mn >= L && node.mx <= R) return node.cnt; // full overlap
        if (start == end) return (node.mn >= L && node.mx <= R) ? 1 : 0;
        int mid = (start + end) / 2;
        return rangeCount(start, mid, idx * 2, L, R) +
               rangeCount(mid + 1, end, idx * 2 + 1, L, R);
    }
};

// ===== Node1 and Update1 for Salary Queries =====
struct Node1 {
    ll mn, mx;
    int cnt;
    Node1() {
        mn = LLONG_MAX;
        mx = LLONG_MIN;
        cnt = 0;
    }
    Node1(ll v) {
        mn = mx = v;
        cnt = 1;
    }
    void merge(Node1 &l, Node1 &r) {
        mn = min(l.mn, r.mn);
        mx = max(l.mx, r.mx);
        cnt = l.cnt + r.cnt;
    }
};

struct Update1 {
    ll val;
    Update1(ll v) { val = v; }
    void apply(Node1 &a) {
        a.mn = a.mx = val;
        a.cnt = 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    SegTree<Node1, Update1> seg(n, v);

    while (q--) {
        char c;
        ll l, r;
        cin >> c >> l >> r;
        if (c == '!') {
            l--;
            seg.make_update(l, r);
        } else {
            cout << seg.rangeCountQuery(l, r) << "\n";
        }
    }
}
