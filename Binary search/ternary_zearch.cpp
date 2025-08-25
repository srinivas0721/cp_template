#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

long long cost(vector<int>& a, int L) {
    long long sum = 0;
    for (int x : a) sum += abs(x - L);
    return sum;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int lo = *min_element(a.begin(), a.end());
    int hi = *max_element(a.begin(), a.end());

    while (hi - lo > 3) { // stop when range is small
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;

        if (cost(a, mid1) < cost(a, mid2)) {
            hi = mid2 - 1;
        } else {
            lo = mid1 + 1;
        }
    }

    long long ans = LLONG_MAX;
    for (int L = lo; L <= hi; L++) {
        ans = min(ans, cost(a, L));
    }

    cout << ans << endl;
    return 0;
}
