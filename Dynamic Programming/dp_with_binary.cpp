#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;


//https://cses.fi/problemset/task/1140

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<n;i++){
        int a,b,p;
        cin>>a>>b>>p;
        v.push_back({b,{a,p}});
    }
    sort(v.begin(),v.end());
    vector<int>dp(n,0);
    for(int i=0;i<n;i++){
        int a=v[i].second.first,p=v[i].second.second;
        int l =0,r=i-1,ans=0;
        while(l<=r){
            int mid =(l+r)/2;
            if(v[mid].first<a){
                l=mid+1;
                ans=dp[mid];
            }
            else r=mid-1;
        }
        dp[i]=max((i?dp[i-1]:0),ans+p);
    }
    cout<<dp[n-1]<<endl;
    return 0;
}