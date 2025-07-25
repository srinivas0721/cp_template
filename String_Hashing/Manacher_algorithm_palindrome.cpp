#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;

struct manacher{
	vector<int>p;
	void run_manacher(string s){
		cout<<s<<endl;
		int n = s.length();
		p.assign(n,1);
		int l = 1,r =1;
		for(int i=1;i<n;i++){
			p[i] = max(0,min(r-i,p[l+r-i]));
			while(i+p[i]<n&&i-p[i]>=0&&s[i+p[i]]==s[i-p[i]]){
				p[i]++;
			}
			if(i+p[i]>r){
				l = i-p[i];
				r=i+p[i];
			}
		}
	}
	void build(string s){
		string t;
		for(auto v:s){
			t+=string("#")+v;
		}
		run_manacher(t+"#");
	}
	// abbabba
	int getLongest(int cen,bool odd){
		int pos = 2*cen +1+(!odd);
		return p[pos]-1;
	}
	bool checkPalin(int l,int r){
		if((r-l+1)<=getLongest((l+r)/2,l%2==r%2){
			return 1;
		}
		return 0;
	}
}m;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s = "babbabbabc";
    m.build(s)
    return 0;
}