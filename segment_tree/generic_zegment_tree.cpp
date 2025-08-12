// Credits to HealthyUG for the inspiration.
// Segment Tree with Point Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree;
	vector<ll> arr; // type may change
	int n;
	int s;
	SegTree(int a_len, vector<ll> &a) { // change if type updated
		arr = a;
		n = a_len;
		s = 1; //size of segment tree
		//size of segment tree should be power of 2 and it should be at  least 2n-1
		while(s < 2 * n){
			s = s << 1;
		}
		tree.resize(s); fill(all(tree), Node());
		build(0, n - 1, 1);
	}
	void build(int start, int end, int index)  // Never change this
	{
		if (start == end)	{
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
	{
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
	Node query(int start, int end, int index, int left, int right) { // Never change this
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
	void make_update(int index, ll val) {  // pass in as many parameters as required
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, index, new_update);     //we write it because user dont need to geive start end , node index every time so this function does it for us
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};
// change will start from here 

// segment  tree will take input of a node1 and input of update1 below


//what will you store in seg tree node for range min queries -->range min
//what will you vtore in seg tree node for range sum queries -->range sum 

//what will you store in vegment tree node for range min + index of that range minimum query -->  we cant do it using one parameter we want 2 parameter
struct Node1 {
	ll val; // may change
	// ll val,val1;    If i want to store 2 paameter in segment t ree
	Node1() { // Identity element use to output for disjoint case
	//identity element I --> oeration between X an I --> X
	//X + I ---> X means I =0;
	//min(X,I) --> X means I = infinity 
		val = 0;	// may change
	}
	Node1(ll p1) {  // Actual Node
		val = p1; // may change
		//here i am telling what will be the value at leaf node 
		//line 26 void build there check 
		//range sum for sum of squares of all values in a range then it will be squared val = p1*p1 
	}
	void merge(Node1 &l, Node1 &r) { // Merge two child nodes
		val = l.val + r.val;  // may change
	}
};
// exampe on how to ztore 2 valuez like the range minimun + index of that minimum queztion 

// struct Node {
//     ll val;
//     int idx;
//     Node() {
//         val = LLONG_MAX; // identity for min
//         idx = -1;        // invalid index
//     }
//     Node(ll v, int i) {
//         val = v;
//         idx = i;
//     }
//     void merge(const Node &l, const Node &r) {
//         if (l.val < r.val) {
//             val = l.val;
//             idx = l.idx;
//         } else {
//             val = r.val; 
//             idx = r.idx;
//         }
//     }
// };
 

struct Update1 {
	ll val; // may change
	
	Update1(ll p1) { // Actual Update
		val = p1; // may change  we store the value given to you and when we reach the leaf node below code void apply we need to apply this stored value
	}
	void apply(Node1 &a) { // apply update to given node
		a.val = val; // may change we reach the leaf node here and make the update
	}
};

int main() {
	vector<ll> arr = {1, 2, 3, 4, 5};
	i nt n = (int)arr.size();

	SegTree<Node1, Update1> seg(n, arr);

	cout << "Initial sum of entire array: " << seg.make_query(0, n - 1).val << "\n"; // Expect 15

	// Update index 2 (0-based) to 10
	seg.make_update(2, 10);
	cout << "After updating index 2 to 10, sum(0..4): " << seg.make_query(0, n - 1).val << "\n"; // Expect 22

	// Query sum range [1..3]
	cout << "Sum of range [1..3]: " << seg.make_query(1, 3).val << "\n"; // Expect 2 + 10 + 4 = 16

	// Update index 0 to 7
	seg.make_update(0, 7);
	cout << "After updating index 0 to 7, sum(0..2): " << seg.make_query(0, 2).val << "\n"; // Expect 7 + 2 + 10 = 19

	return 0;
}