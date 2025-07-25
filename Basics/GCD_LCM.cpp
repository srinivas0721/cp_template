#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

int gcd(int a ,int b){
    if(a ==0){
        return b;
    }
    return gcd(b%a,a);
}
//TC = log(n)  worst tc for fibbonacci number  1 1 2 3 5 8 13 21 34 ...
//gcd(21,34)== gcd(34-21,21)== gcd(13,21)==gcd(8,13)==gcd(8,5).....
signed main (){
ios::sync_with_stdio(false);cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
}
return 0;
}