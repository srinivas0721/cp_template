#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;
//can also be done with binary search two for loop and lower_bound() then check 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){

        cin>>v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(),v.end());
    for(int i =0;i<n;i++){
        int j = i+1,k=n-1;
        int rem = x-v[i].first;
        while(j<k){
            if(v[j].first+v[k].first==rem){
                cout<<v[i].second<<" "<<v[j].second<<" "<<v[k].second<<endl;
                return 0;
            }
            else if(v[j].first+v[k].first>rem)
                k--;
            else
                j++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}