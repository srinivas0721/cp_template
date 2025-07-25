// In a path, no cell can be visited more than one time. 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

int count(int i,int j,int n,int m,vector<vector<int>>&arr){
    if(i>=n||j>=m||i<0||j<0||arr[i][j]==1){
        return 0;
    }
    if(i==n-1&&j==n-1){
        return 1;
    }
    arr[i][j]=1;         //when i move to a certain block i will mark it as trap(1) then move forward 
    //right --> col. shift --> j to j+1
    //down --> row. shift --> i to i+1
    //same for up and down
    int right = count(i,j+1,n,m,arr);
    int down = count(i+1,j,n,m,arr);      //tc = 4^(n*m) total 4 option up down left and right each option pich or not pick
    int up = count(i-1,j,n,m,arr);       //mark it do all the work and then unmark it
    int left = count(i,j-1,n,m,arr);
    //i will unmark it 
    arr[i][j]=0;

    return right+down+left+up;
}

signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<count(0,0,n,m,arr)<<endl;
return 0;
}