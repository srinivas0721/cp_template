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

    string s,t;
    cin>>s>>t;
    int n= t.size();
    map<char,vector<int>>mp;
    for(int i=0;i<n;i++){
        mp[t[i]].push_back(i);
    }
    string anz="";
    int len =LLONG_MAX;
    int ind =-1;
    for(int i=0;i<n;i++){
        int val =-1;
        if(!mp[s[i]].empty()){
            val = i +(n-mp[s[i]].back());
        }
        if(val!=-1&&len>val){
            len = val;
            ind =i;
        }
    }
    for(int i=0;i<ind;i++){
        anz += s[i];
    }
    for(int i=len-ind;i<n;i++){
        anz+=t[i];
    }
    cout<<anz<<endl;
    return 0;
}