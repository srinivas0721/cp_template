#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;

int gcd(int a,int b,int &x,int &y){
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    int x1,y1;
    int g = gcd(b%a,a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return g;
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int a,b;
    cin>>a>>b;
    //let a =4,b =3 
    //4x + 3y = gcd(4,3)  ---> x =1 y =-1
    int x,y;
    cout<<gcd(a,b,x,y)<<endl;
    cout<<x<<" "<<y<<endl;

    return 0;
}
