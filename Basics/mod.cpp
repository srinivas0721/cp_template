
//https://codeforces.com/problemset/problem/1374/A


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
    int x,y,N;
    cin>>x>>y>>N;
    int rem = N%x;
    int diff=0;
    if(rem>=y){
        diff = -y+rem;
        cout<<N-diff<<endl;
        continue;
    }
    N= N-(rem+1);
    rem = N%x;
    if(rem>=y){
        diff = -y+rem;
        cout<<N-diff<<endl;
    }
   
    }
return 0;
}