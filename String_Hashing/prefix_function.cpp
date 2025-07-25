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

    string s;
    cin >> s;
    int n = s.size();
    vector<int> pre_fun(n, 0);
    
    // Calculate the prefix function
    for(int i = 1; i < n; i++) {
        int j = pre_fun[i - 1];
        
        // Find the longest proper prefix which is also a suffix
        while(j > 0 && s[i] != s[j]) {
            j = pre_fun[j - 1];  // Go to the previous prefix length
        }
        
        if(s[i] == s[j]) {
            j++;  // If characters match, increase the length of the prefix
        }
        
        pre_fun[i] = j;  // Store the computed prefix length
    }
    
    // Print the computed prefix function
    for(auto i : pre_fun) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
