#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;
int n =3,m=3;
vector<vector<int>>grid(3,vector<int>(3));
vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(m,{-1,0}));
//0 means down direction
// 1 means right direction
int f(int i,int j){
	if(i==n||j==m)
		return 1e9;
	if(i==n-1&&j==m-1)
		return grid[n-1][m-1];
	if(dp[i][j].first!=-1)  //
		return dp[i][j].first;
	int ans1 = f(i+1,j);
	int ans2= f(i,j+1);
	if(ans1<ans2)
		dp[i][j].second =0;   //.second is the choice .first is the value
	else
		dp[i][j].second =1;

	return dp[i][j].first = grid[i][j]+min(ans1,ans2);
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        for(int i=0;i<3;i++)
        	for(int j=0;j<3;j++)
        	cin>>grid[i][j];

        cout<<f(0,0)<<endl;
        pait<int,int>current = {0,0};
        while(current != make_pair{n-1,m-1}){
        	cout<<current.first<<" "<<current.second<<endl;
        	if(dp[current.first][current.second].second==0)
        		current.first++;
        	else
        		current.second++;
        }
        cout<<current.first<<" "<<current.second<<endl;
    return 0;
}