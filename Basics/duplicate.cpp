#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
 
signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector <int> v(3*n,0);
    for(int i =0;i<n;i++){
        cin>>v[i];
        v[2*n+i]=v[n+i]=v[i];
    }
    for(int i =n;i<2*n;i++){
        if(v[i]!=v[i+1]&&v[i-1]==v[i+1]){
            cout<<i-n+1<<endl;
            break;
        }
    }

    }
return 0;
}