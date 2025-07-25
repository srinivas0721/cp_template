#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    int cnt =0;
    for(int i=2;i*i<=n;i++){
    	if(n%i==0){
    		cnt++;
    		if(n/i != i){
    			cnt++;
    		}
    	}
    }
    if(cnt ==2){
    	cout<<"Prime"<<endl;
    }
    else
    	cout<<"Not Prime"<<endl;

    // Given range l to r find prime in range l to r
    //use seive of eratosenes

    //Prime Factorisation
    //If q queries are given find the prime factoristion of each of the q given number
    //n<=1e6 and q<=1e5

    //smallest  Prime Factor seive(spf):

    //spf[i]=x i.e smallest prime factor of i
    int N =100000;
    int spf[N+1];
    for(int i=2;i<=N;i++){
        spf[i]=i;
    }
    for(int i=2;i*i<=N;i++){
        if(spf[i]!=i)
            continue;
        for(int j =i*i;j<=N;j+=i){
            if(spf[j]==j){
                spf[j]=i;
            }
        }
    }
    //TC = o(N*loglogN + q*logn)
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        while(n!=1){
            cout<<spf[n]<<" ";
            n = n/spf[n];
        }

        cout<<endl;
    }
    //we can alzo check prime or not 
    // if spf[i]==i then it is a prime


    //Assume n<=1e6 given q queries every query has a number x.Tell me how many
    //number between 1 to 1e6 have minimum prime factor as x
    // can do it using map or array

    // for int / double array golbally size<=1e7 and inside fn <=1e6
    // for bool array globall size <=1e8 and inside fn <= 1e7


    // L,R <= 1e7 then both seive and spf array applcable
    //L,R <= 1e8 then only seive applicable
    // what if L,R<= 1e9
    //Find how many rpimes are there in range L to R???

    //Given : 1<=R-L<= 1e6

    return 0;
}