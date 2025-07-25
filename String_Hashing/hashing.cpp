#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;

int get_hash(string s){
	int h =0;
	for (char c:s)
		h = (h*31+(c-'a'+1))%MOD;
	return h;
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

        cout<<get_hash("cab")<<endl;
        cout<<(get_hash("dab")==get_hash("dab"))<<endl;
        
    return 0;
}