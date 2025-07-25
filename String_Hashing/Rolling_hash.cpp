#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF LLONG_MAX >> 1
const int MOD = 1e9 + 7;

int get_hash(string s) {
    int h = 0;
    for (char c : s)
        h = (h * 31 + (c - 'a' + 1)) % MOD;
    return h;
}
/*
eg :
cses string Matching
*/
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    int res = get_hash(s2); 
    int m = s2.size(), n = s1.size();
    if(m>=n){
        if(s1==s2)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        return 0;
    }
    int cnt = 0;
    vector<int> hash_map(n + 1, 0);
    int p = 1; 
    for (int i = 0; i < m; i++) {
        p = (p * 31) % MOD;
    }
    for (int i = 0; i < n; i++) {
        hash_map[i + 1] = (hash_map[i] * 31 + (s1[i] - 'a' + 1)) % MOD;
    }
    if (hash_map[m] == res) {
        cnt++;
    }

    for (int i = m; i < n; i++) {
        int current_hash = (hash_map[i + 1] - (hash_map[i + 1 - m] * p) % MOD + MOD) % MOD;
        if (current_hash == res) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
