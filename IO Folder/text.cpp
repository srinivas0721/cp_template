#include <bits/stdc++.h>
using namespace std;

#define int long long

int t;

bool can_produce(int time, vector<int> &machines) {
    long long cnt = 0; // explicitly long long
    for (auto &m : machines) {
        cnt += time / m;
        if (cnt >= t) return true; // early exit
    }
    return cnt >= t;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> t;
    vector<int> machines(n);
    for (int i = 0; i < n; i++) cin >> machines[i];

    int l = 0, r = 1e18, ans = 1e18; // upper bound safe
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (can_produce(mid, machines)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
}
