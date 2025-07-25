#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    

    double n;        //for value to be in decimal use double for binary search
    cin>>n;

    double l=0,r = 1e5+1;   //l!=-1 in range of bs becoz (l,r) exclusive when doing 
   //bs in case of integer it starts from 0 but in case of double it starts from -0.999999.. 
    //which is inaccurate so we take 0 the range would be 0.000000...1 which is fine
    

    // we dont know how many time loop should take place r-l>1 will not work 10^5 is max
    //so the bs operation will be 10^5/(2/2/2..k) = 10^5/2^k = relative/abs error


    //   k = log2(max(x)/abs. error);=log2(10^5/10^-6)=36.54... take k = 100 for better precision

    for(int i =0;i<100;i++){
    	double x = (l+r)/2;
    	(x*x + sqrt(x)<=n)?l=x:r=x;
    }
    cout<<fixed<<setprecision(15);
    cout<<l<<endl;
    return 0;
}