#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i =0;i<n;i++){
    	cin>>v[i];
    }
    int sum =0,maxi = LLONG_MIN;
    for(int i =0;i<n;i++){
    	sum += v[i];
    	maxi = max(sum,maxi);
    	if(sum<0)
    		sum =0;
    }
    cout<<maxi<<endl;
    return 0;
}