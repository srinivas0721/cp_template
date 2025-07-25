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
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,int>m;
    for(auto i : v){
        m[i]++;
    }
    int maxi =0;
    for(auto i:m){
        maxi = max({maxi,i.second});
    }
    int diff = m.size();
    if(diff==maxi){
        cout<<diff-1<<endl;
    }
    else if(diff>maxi){
        cout<<maxi<<endl;
    }
    else if(diff<maxi){
        cout<<diff<<endl;
    }
}
return 0;
}