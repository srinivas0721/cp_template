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

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        int R= (n+m),L=max(0ll,(n-m)),ans=0;
        for(int d =33;d>=0;d--){
            if(R&(1ll<<d)){
                if(L&(1ll<<d)){
                    ans += (1ll<<d);
                } 
                else{
                    while(d>=0){
                        ans += (1ll<<d);
                        d--;
                    }
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}