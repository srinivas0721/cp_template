#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;
int N = 1e5;
vector<int>fact(N+1,0);
vector<int>modinv(N+1,0);

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

void precompute(){
    fact[0]=1;
    for(int i=1;i<=N;i++){
        fact[i]= (fact[i-1]*i)%MOD;
        modinv[i] = power(fact[i],MOD-2);
    }
}

int ncr(int n,int r){

    int nume = fact[n];
    // int deno = ((fact[r]%MOD)*(fact[n-r])%MOD)%MOD;
    // int ans = (nume*power(deno,MOD-2))%MOD;   //tc(log(MOD))
    int invdeno = (modinv[r]*modinv[n-r])%MOD ;
    int ans = (nume*invdeno)%MOD;
    return ans;
}

void solve(){
    int q;
    cin>>q;
    precompute();
    //Tc1  = TC(N + Qlog(MOD))
    //if q = 1e7 then it will give tle zo we do it to
    // TC2 = TC(N*log(MOD)+Q)
    while(q--){
        int n,r;
        cin>>n>>r;
        cout<<ncr(n,r)<<endl;
    }
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    solve();
    //different ways to represent n as a sum of k non zero integer
    //if n = 5 k =3;
    // 1 _| 1 _ 1 _| 1 _ 1  (n-1)C(k-1) #Begger's method
    //different ways to represent n as a sum of k non negative integer
    //if n = 5 k =3;
    // _ _ _ _ _ _ _ ==> 1 , 1 1 1 , 1 == 1 + 3 + 1
    //               ==> , , 1 1 1 1 1 == 0 + 0  + 5 
    //" , " acts as the partition 
    //becoz at most k -1 zeros in the ones i.e total space = n + k-1
    //out of those we have to select total of k-1 0's so:
    // answer = (n+k -1)C(k-1)
    return 0;
}