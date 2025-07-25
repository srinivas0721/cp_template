#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;
// ND == NO DP
int gridNoDP(vector<vector<int>>grid,int i,int j){
	int n = v.size();
	int m = v[0].size();
	if(i==n-1 && j==m-1){
		return grid[n-1][m-1];
	}
	if(i==n||j==n){
		return INF;
	}
	return grid[i][j] + min(gridNoDP(grid[i+1][j],i+1,j),gridNoDP(grid[i][j+1],i,j+1));
}
int dp1[n+1][m+1];
// int gridwithDP(vector<vector<int>>grid,int i,int j){
// 	int n = v.size();
// 	int m = v[0].size();
// 	if(i==n-1 && j==m-1){
// 		return grid[n-1][m-1];
// 	}
// 	if(i==n||j==n){
// 		return INF;
// 	}
// 	if(dp1[i][j]!=-1){
// 		return dp1[i][j];
// 	}
// 	dp1[i][j]= grid[i][j] + min(gridwithDP(grid,i+1,j),gridwithDP(grid,i,j+1));
// 	return dp1[i][j];
// }

//without return 

int gridwithDP(vector<vector<int>>grid,int i,int j){
	int n = v.size();
	int m = v[0].size();
	if(i==n-1 && j==m-1){
		dp1[i][j]=grid[i][j];
		return;
	}
	if(i==n||j==n){
		dp1[i][j]= INF;
		return;
	}
	if(dp1[i][j]!=-1){
		return;
	}
	gridwithDP(grid,i+1,j);
	gridwithDP(grid,i,j+1);
	dp1[i][j]= grid[i][j] + min(dp1[i+1,j],dp1[i,j+1]);
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    //Problem 1(grid):
    //Given 2d matrix find shortestpath between top left and bottom right
    memset(dp1,-1,sizeof(dp1));
    cout<<gridwithDP(0,0)<<endl;
    cout<<dp1[0][0]<<endl;
    return 0;
}