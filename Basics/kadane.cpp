#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int best_sum = LLONG_MIN; // to handle all-negative case
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        best_sum = max(best_sum, current_sum);
        if (current_sum < 0) current_sum = 0; // reset if sum goes negative
    }

    cout << best_sum << endl;
    return 0;
}
