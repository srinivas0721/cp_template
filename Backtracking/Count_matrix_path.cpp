//Count paths in a matrix.
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

int count(int i,int j,int n,int m,vector<vector<int>>&arr){
    if(i>=n||j>=m||arr[i][j]==1){
        return 0;
    }
    if(i==n-1&&j==n-1){
        return 1;
    }
    //right --> col. shift --> j to j+1
    //down --> row. shift --> i to i+1
    int right = count(i,j+1,n,m,arr);
    int left = count(i+1,j,n,m,arr);      //tc = 2^(n*m)

    return right+left;
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