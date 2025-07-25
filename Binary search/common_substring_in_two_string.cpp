#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;
bool check(string a,string b,int len){
        int n = a.size(),m=b.size();
        set<string> s;
        bool found = false;

        for(int i=0;i+len<=n;i++) {
            s.insert(a.substr(i,len));
        }
        for(auto i:s)
            if(b.find(i)!=string::npos){
                found =true;
        }
        return found;
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        string s1,s2;
        cin>>s1>>s2;
        int l =0,r=min(s1.size(),s2.size()),anz=0;
        while(l<=r){
            int mid = (l+r)/2;
            if(check(s1,s2,mid)){
                l=mid+1;
                anz=mid;
            }
            else
                r=mid-1;
        }
        cout<<s1.size()+s2.size()-2*anz<<endl;
    }
    return 0;
}