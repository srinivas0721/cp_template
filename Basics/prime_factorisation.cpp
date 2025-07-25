#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n' 
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;
 
// N = 2^x * 3^y * 5^z * 7^w.........   compoite no. can be expressed as a product of primes less than or equal to it

void factorise(int n){
    for(int i =2;i*i<=n;i++){//why i*i becoz smallest divisor of any no. N will be prime and it will be less than sqrt(n)
        while(n%i==0){        //eg : 2^3*3^2*7  (i = 2) ->N =3^2*7 (i=3)-->(N=7) i <= sqrt(7) but i =4 so break 
            cout<<i<<endl;    // but we have 7 as a factor remaining to be printed so we use if statement
            n/=i;
        }
    }
    if(n!=1){
        cout<<n<<endl;       //necessay in case of eg 10 
    }
    return ;
}
signed main (){
ios::sync_with_stdio(false);cin.tie(NULL);
int n;
cin>>n;
factorise(n);
return 0;
}