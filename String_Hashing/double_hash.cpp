#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
//cses finding border
int power(int a, int b, int MOD) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        string s1;
        cin>>s1;
        int n = s1.size();
        vector<int>hash_map1(n+1,0);
        vector<int>hash_map2(n+1,0);
        for (int i = 0; i < n; i++) {
        hash_map1[i + 1] = (hash_map1[i] * 31 + (s1[i] - 'a' + 1)) % MOD1;
    }
    for (int i = 0; i < n; i++) {
        hash_map2[i + 1] = (hash_map2[i] * 37 + (s1[i] - 'a' + 1)) % MOD2;
    }
    for(int i =0;i<n-1;i++){
        int pre_hash1 = hash_map1[i+1];
        int pre_hash2 = hash_map2[i+1];

        int suff_hash1 = (hash_map1[n]-(hash_map1[n-1-i]*power1(31,i+1))%MOD1+MOD1)%MOD1;
        int suff_hash2 = (hash_map2[n]-hash_map2[n-1-i]*power2(37,i+1)%MOD2+MOD2)%MOD2;

        if(pre_hash1==suff_hash1&&pre_hash2==suff_hash2){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    return 0;
}