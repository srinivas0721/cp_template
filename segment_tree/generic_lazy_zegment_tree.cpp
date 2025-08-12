#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

// Credits to HealthyUG for the inspiration.
// Lazy Segment Tree with Range Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template<typename Node, typename Update>
struct LazySGT {
    vector<Node> tree; //actual segment tree
    vector<bool> lazy; // booleann segment tree that tell if there exist any update on a node or not 
    vector<Update> updates;  //willl actually contain those updates
    vector<ll> arr; // type may change
    int n;
    int s;
    LazySGT(int a_len, vector<ll> &a) { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n){
            s = s << 1;
        }
        tree.resize(s); fill(all(tree), Node());
        lazy.resize(s); fill(all(lazy), false);
        updates.resize(s); fill(all(updates), Update());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) { // Never change this
        if (start == end)   {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    //lazy[index]=1 does not means there are some pending changes on my current node but it means some chnages need to be pushed down 
    void pushdown(int index, int start, int end){
        if(lazy[index]){
            //i am not applying the changes to the current node this means that current node is already been updated i only nee to push down the changes
            int mid = (start + end) / 2;
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    void apply(int index, int start, int end, Update& u){
        if(start != end){
            lazy[index] = 1;
            updates[index].combine(u, start, end);
            //if there waz any previouz update combine it with the new update first
        }
        // now we apply it in the actual tree index
        u.apply(tree[index], start, end);
    }
    void update(int start, int end, int index, int left, int right, Update& u) {  // Never Change this
        if(start > right || end < left)
            return;
        if(start >= left && end <= right){
            apply(index, start, end, u);
            return;
        } 
        //here i am assuming that my current node is in the most updated state and then if there are any chnages which need to be pused down i will do them here
        //when i push down my chnages , i dont just push them down i also apply them
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        //when i call the below update i am ensuring that my left and right node after push down are in the most updated state
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, 2 * index + 1, left, right, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) { // Never change this
    //my current node is in the most updates state
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right){
            pushdown(index, start, end);
            return tree[index];
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int left, int right, ll val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

// Range minimum with range increment update
struct Node {
    ll val;
    Node() {
        val = LLONG_MAX;
    }
    Node(ll v) {
        val = v;
    }
    void merge(Node &l, Node &r) {
        val = min(l.val, r.val);
    }
};

struct Update {
    ll val; // increment value
    Update() {
        val = 0; // 0 means no increment
    }
    Update(ll v) {
        val = v;
    }
    void apply(Node &a, int start, int end) {
        if(val == 0) return;
        a.val += val;
    }
    void combine(Update &new_update, int start, int end) {
        val += new_update.val; // increments accumulate
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> arr = {5, 3, 8, 6, 2, 7, 4, 1};
    int n = (int)arr.size();

    LazySGT<Node, Update> seg(n, arr);

    cout << "Initial minimum in [0,7]: " << seg.make_query(0, 7).val << "\n"; // Should print 1

    seg.make_update(2, 5, 3); // Increment elements in [2..5] by 3

    cout << "Minimum in [0,7] after update +3 on [2,5]: " << seg.make_query(0, 7).val << "\n"; // Should print 1 still

    cout << "Minimum in [2,5]: " << seg.make_query(2, 5).val << "\n"; // Should print 5 (2+3=5)

    seg.make_update(0, 7, 1); // Increment entire array by 1

    cout << "Minimum in [0,7] after increment +1 entire: " << seg.make_query(0, 7).val << "\n"; // Should print 2

    cout << "Minimum in [4,7]: " << seg.make_query(4, 7).val << "\n"; // Should print 3 (2+3+1=6 -> actually 2+3+1=6 but careful)

    return 0;
}
