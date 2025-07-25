#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
const int MOD = 1e9 + 7;

// if we dont want to compute only check we can use bool
//if n is not a prime number then it  will have atleast one prime divisor less than it if no divisor less than it then prime
void prime(int n){                //TC = O(NloglogN)
    bool primes[n+1];    //making array primes of bool
    fill(primes,primes+n+1,true);        //sets all value in prime array 
    primes[0]=primes[1]=false;
    for(int i=2;i*i<=n;i++){            //TC = sqrt(N)
        if(primes[i]==true){
        for(int j = i*i;j<=n;j+=i){     // for i =2 ,j = 4 6 8 10 i =3 j = 9 12 15 TC = N/2+N/3+N/5+...+N/sqrt(N) i.e sum N/z z=prime
            primes[j]=false;
        }                                // for i*i becoz for 5 (5*2(two),5*3(three),5*4(four) were alreaady marked by prev element)
    }
}
    if(primes[n]==true){
        cout<<"Yes"<<endl;
    }
    else
    cout<<"No"<<endl;
}  
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector <int> index(1000001,0);
    for(int i =1;i<=1000000;i++){
        for(int j=i;j<= 1000000;j+=i){
            index[j]++;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        cout<<index[x]<<endl;
        prime(x);
}
return 0;
}
