#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
int n, targetSum, dp[505][125005];
const int MOD = 1e9 + 7;

int solve(int i, int sum) {
    if (sum == targetSum) {
        return 1;
    }
    if (i > n || sum > targetSum) {
        return 0;
    }
    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }
    int include = solve(i + 1, sum + i) % MOD;
    int exclude = solve(i + 1, sum) % MOD;

    return dp[i][sum] = (include + exclude) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    if ((n * (n + 1)) % 4 != 0) {
        cout << "0" << endl;
        return 0;
    }
    targetSum = (n * (n + 1)) / 4;
    memset(dp, -1, sizeof dp);
    int counti = solve(1, 0) % MOD;
    cout << (counti * (MOD + 1) / 2) % MOD << endl;
    return 0;
}
