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
    vector<int>v = {1,2,3,4};
    int n =4;
    int p = 1<<n;
    vector<int>dp(p);
    for(int mask=0;mask<p;mask++){
        // for(int bit =0;bit<n;bit++){
            // if(mask & (1LL << bit)) s[mask]+=v[bit]; //subset sum
        // Tc = o(2^n* n) here the * n is redundentwe want to remove * n so we do it using dp
        // }
        dp[mask]=dp[mask&(mask-1)]+v[__builtin_ctz(mask)]; //mask&(mask-1) is where rightmost bit of mask is turned off
        //110010 = 110000 + 000010
        //TC=O(2^n)
    }
    cout<<p<<endl;

    //submask of mask
    for(int mask =0;mask<p;mask++){
        for(int sub=0;sub<p;sub++){ //A mask with k set bits (i.e., bits that are 1) has exactly 2^k submasks.
            if((mask&sub)==sub)
                cout<<sub<<" ";//tc = o(4^n) 
        }
        cout<<endl;
    }
    for(int mask =0;mask<p;mask++){
        for(int sub=mask;sub>0;sub= (sub-1)&mask){
            if((mask&sub)==sub)
                cout<<sub<<" ";//tc = o(3^n)
        }
        cout<<endl;
    }

    // for(auto i:dp)
    //     cout<<i<<" ";
    return 0;
}

