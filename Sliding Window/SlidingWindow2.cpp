//Find 1t negative in the subsequence of length k

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF LLONG_MAX>>1
const int MOD = 1e9 +7;

signed main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    vector<int>v{-3,2,7,-1,2,-3,5,8,9};
    int k =3; 
    deque<int>d;
    int ind = 0;
    int n = v.size();
    for(int i =0;i<n;i++){
        if(v[i]<0){
            d.push_back(i);
        }
    }
    for(int i=0;i<=n-k;i++){
        if(d.front()>=i&&d.front()<i+k){
            cout<<v[d.front()]<<" ";
        }
        else{
            d.pop_front();
            if(d.front()>=i&&d.front()<i+k){
            cout<<v[d.front()]<<" ";}
            else
            cout<<0<<" ";
        }
    }
    return 0;   
}