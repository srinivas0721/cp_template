#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

//perform 2 queries on an array:
//1 l r x : add x to all the elment form l to r
//2 l r : return min. of all elment from l to r


vector<int>segTree,lazy;
int merge (int a,int b){
  return min(a,b);
}
void build(vector<int>&arr,int start,int end,int index){
  if(start ==end){
    segTree[index]=arr[start];
    return ;
  }
  int mid = (start + end)/2;
  int left = 2*index,right = 2*index +1;
  build(arr,start,mid,left);
  build (arr,mid+1,end,right);
  segTree[index]=merge(segTree[left]+segTree[right]);
}
void propogate(int start,int end,int index){
  if(start==end){
    lazy [index]=0;
    return;
  }
  left[2*index] += lazy[index];
  left[2*index +1]+=lazy[index];
  lazy[index]=0;
}
void update(int start,int end,int index,int l,int r,int value){
  //check for pending updates in lazy
  if(lazy[index]!=0){
    segTree+=lazy[index];
    propogate(start,end,index);
  }
  if(start>=l&&end<=r){
    segTree[index]+=value;
    lazy[index]=value;
    propogate(start,end,index);
    return;
  }
  if(start>r||end<l){
    return;
  }
  int mid = (start+end)/2;
  update(start,mid,2*index,l,r,value);
  update(mid+1,end,2*index+1,l,r,value);
  segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
}
int query(int start,int end,int index,int l,int r){
  if(lazy[index]!=0){
    segTree[index]+=lazy[index];
    propogate(start,end,index);
  }
  if(start>=l&&end<=r){
    return segTree[index];
  }
  if(l>end||r<start){
    return LLONG_MAX;
  }
  int mid = (start+end)/2;
  int leftAnswer = query(start,mid,2*index,l,r);
  int rightAnswer = query(mid+1,end,2*index+1,l,r);
  return merge(leftAnswer,rightAnswer);
}

signed main (){
ios::sync_with_stdio(false);cin.tie(NULL);
int t;
cin>>t;
while(t--){
  
}
return 0;
}