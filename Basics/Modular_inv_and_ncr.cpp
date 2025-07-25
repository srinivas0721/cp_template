#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
vector<int>fact(100);
int mod_mul(int a,int b,int m){
    return ((a%m)*(b%m))%m;
}
int mod_exponentiation(int a ,int b,int m){
    if(b==0){
        return 1;
    }
    int half = mod_exponentiation(a,b/2,m);
    half = mod_mul(half,half,m);
    if(b%2==1){
        half = mod_mul(half,a,m);
    }
    return half;
}
int mod_inv(int a,int m){
    return mod_exponentiation(a,m-2,m);
}
int mod_div(int a,int b,int m){
    return mod_mul(a,mod_inv(b,m),m);
}
int nCr(int n,int r){
    return mod_div(fact[n],mod_mul(fact[r],fact[n-r],MOD),MOD);
}
signed main (){
ios::sync_with_stdio(false);cin.tie(NULL);
cout<<mod_div(100,20,3)<<endl;
fact[0]=1;
for(int i =1;i<100;i++){
    fact[i]= mod_mul(fact[i-1],i,MOD);
}
cout<<nCr(5,2)<<endl;
return 0;
}