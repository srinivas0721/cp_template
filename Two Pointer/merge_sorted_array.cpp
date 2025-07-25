#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX >> 1
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    vector<int> a{3, 4, 7};    // i will be here
    vector<int> b{1, 2, 5, 6};  // j will be here
    int i = 0;
    int j = 0;
    
    vector<int> ans; // Just declare ans without size
    while (i < a.size() || j < b.size()) {
        if (a[i] > b[j]) {
            ans.push_back(b[j]);
            j++;
        } else {
            ans.push_back(a[i]);
            i++;
        }
    }
    

    // Output the merged array
    for (auto m : ans) {
        cout << m << " ";
    }
    cout << endl;
    return 0;
}
