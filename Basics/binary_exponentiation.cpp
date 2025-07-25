#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int half_power = power(a, b / 2) % MOD;
    half_power = (half_power * half_power) % MOD; // Take modulo here to avoid overflow
    if (b % 2 == 0) {
        return half_power;
    } else {
        return (half_power * a) % MOD; // Take modulo here to avoid overflow
    }
}

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
signed main (){
ios::sync_with_stdio(false);cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int a,b; //a^b
    cin>>a>>b;
    cout<<power(a,b)<<endl;
}
return 0;
}