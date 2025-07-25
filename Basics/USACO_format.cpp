#include <stdio.h>

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF LLONG_MAX>>1
const int MOD = 1e9 +7;

int cmp(int a,int b){
    return a<b;
}

signed main(){
    if (fopen("notlast.in", "r")) {
		freopen("notlast.in", "r", stdin);
		freopen("notlast.out", "w", stdout);
	}
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    map<string,int>mp;
    map<int,string,decltype(&cmp)>r(cmp);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int a;
        cin>>a;
        mp[s]+=a;
    }
    int mini = 1e5;
    for(auto num:mp){
        if(num.second>0)
        mini = min(mini,num.second);
    }
    int sec_min=1e5;
    for(auto num:mp){
        if(num.second>mini){
            sec_min = min(sec_min,num.second);
        }
    }
    int cnt =0;
    string ans=" "; 
    for(auto i:mp){
        if(i.second==sec_min){
            cnt++;
        }
    }
    if(cnt ==0||cnt>1){
        cout<<"Tie"<<endl;
    }
    else{
        for(auto i:mp){
        if(i.second==sec_min){
            ans = i.first;
            break;
        }
        }
        cout<<ans<<endl;
    }
    return 0;
}