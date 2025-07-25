#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;
vector<int>segTree;//size is 2*n because   there are 2n nodes
//size =2*n if n is power of 2 n + n/2+n/4+n/8 +....<=2*n
//tc = O(n)
//vector<pair<int,int>>segTree;//second minimum
pair<int,int>merge(pair<int,int>l,pair<int,int>r{
	if(l.first<r.first)
		return {l.first,min(r.first.lsecond)};
	else
		return{r.first,min(l.first,r.second)};
}
void build(vector<int>&v,int start,int end,int index){
	if(start==end){
		segTree[index]=v[start];

		return;
	}
	int mid = (start+end)/2;
	int left =2*index;
	int right  = 2*index+1;
	build(v,start,mid,left);//go down left
	build(v,mid+1,end,right);//go down right
	segTree[index]=segTree[left]+segTree[right];
	//segTree[index]=min(segTree[left],segTree[right]);
	//segTree[index]=segTree[left]^segTree[right];
	// segTree[index] = merge(segTree[left],segTree[right]);
}
void update(vector<int>&v,int start,int end,int index,int pos,int value){  //update element at given point in segmene tree
	if(start == end){
		// v[pos]+=value;
		//v[pos] = __gcd(v[pos],value);
		v[pos]=value;
		segTree[index]=v[pos];
		return;
	}
	int mid = (start +end)/2;
	if(mid>=pos){
		update(v,start,mid,2*index,pos,value);
	}
	else
		update(v,mid+1,end,2*index+1,pos,value);
	//tc = log(n)
	segTree[index]= segTree[2*index]+segTree[2*index+1];
	//segTree[index]= min(segTree[2*index],segTree[2*index+1]);
	//segTree[index]= segTree[2*index]^segTree[2*index+1];
	//segTree[index] = merge(segTree[left],segTree[right]);
}
int query(int start,int end,int index,int l,int r){//give sum from l to r //for problemm 2 commented line
	//complete Overlap
	if(l<=start&&end<=r){
		return segTree[index];
	}
	//disjoint
	if(l>end||r<start){
		return 0;
		// return LLONG_MAX;
		// return 0;
	}
	int mid = (start+end)/2;
	int leftAnswer = query(start,mid,2*index,l,r);
	int rightAnswer = query(mid+1,end,2*index+1,l,r);
	return leftAnswer+rightAnswer;
	//return leftAnswer^rightAnswer;
	//return merge(leftAnswer,rightAnswer);
}
signed main() { 
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    segTree.resize(2*n);
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }
    //current=current_node
    //left = left nodeof current
    //same for right
    //left = 2*current,right= 2*current+1;    
    build(v,0,n-1,1); //index of topmost node
    update(v,0,n-1,1,1,3);



    //if n is power of 2 then segmenttree size = 2*n-1;
    //if n is not a power of 2 like [1 2 3 4 5]
    //we convert 5 nodes to 8 nodes -->2*8-1=17
    //like [ 1 2 3 4 5 0 0 0]

    //if n is not a power of 2 -> convert array into the next power of 2
    //5-->8.9-->16,20-->32
    // for any given N, next power of 2 for N will be <= 2*N

    // convert N to next power of 2 --><=2N -->2*(2N)-1<=4*N-1




    //PROBLEM-2
    //update value at pos --> current value + value(query)
    //range minimum



    //PROBLEM-3
    //update value at pos ->gcd(current value,value)
    //give xor of range



    //PROBLEM-4
    //update value at pos ->value
    //give second minimum in the array

    //[1 2 1 2] ---> second minimum is 1
    //left --> min1, second_min1
    //right --> min2,second_min2
    //if(min1<min2)
	    //current.min = min1;
	    //current_secodn_min = min(min2,second_min1)

    // else
    	//current.min = min2;
	    //current_secodn_min = min(min1,second_min2)


    return 0;
}