#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF = LLONG_MAX>>1
const int MOD = 1e9 +7;

signed main (){
    ios::sync_with_stdio(false);cin.tie(NULL);
    //MAKE subset using bitwise
    int n; 
    cin>>n;
    vector<int>v(n,0);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }

    //2^x <= 10^7              x<=23

    /*0000
      0001
      0010
      0011
      0100
      ....*/
    //Total number of subset = 2^n -1 i.e (1<<N) = 1*2^N
     for(int i =0;i<(1<<n);i++){     //same as (A&(1<<j)) in i,the xth bit represent whether xth index is taken or not 
         for(int j =0;j<n;j++){      //j represent jth index   
            if((i>>j)&1)            
               cout<<v[j]<<" ";
        }
        cout<<endl;
     }
     cout<<endl;
     while(true){
         int n ;
         cin>>n;
         int l  =0;
         while(n>>l){     //Length of binary digit present in 32 or 64 bit to clip it
             l++;
         }
         cout<<((~n)&((1<<l)-1));
     }
    return 0;
}