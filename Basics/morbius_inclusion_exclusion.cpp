// https://cses.fi/problemset/task/2417/

//TRY IT !!!!(num_theory last lectu)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAX_A = 1e6 +1;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> freq(MAX_A + 1, 0);

    // Input array and find maximum element
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    // Step 1: Calculate Mobius function values up to MAX_A
    vector<int> mobius(MAX_A + 1, 1);
    for (int i = 2; i <= MAX_A; i++) {
        if (mobius[i] == 1) { // `i` is prime
            for (int j = i; j <= MAX_A; j += i) {
                mobius[j] *= -1; // Flip sign
            }
            for (int j = i * i; j <= MAX_A; j += i * i) {
                mobius[j] = 0; // Set to 0 if divisible by a square
            }
        }
    }

    // Step 2: Calculate pairs sharing a common divisor for each `d`
    vector<ll> divisor_pairs(MAX_A + 1, 0);
    for (int d = 1; d <= MAX_A; d++) {
        ll count = 0;
        for (int multiple = d; multiple <= MAX_A; multiple += d) {
            count += freq[multiple];
        }
        divisor_pairs[d] = (count * (count - 1)) / 2; // Total pairs that can be formed
    }

    // Step 3: Use Inclusion-Exclusion principle to count non-coprime pairs
    ll non_coprime_pairs = 0;
    for (int d = 1; d <= MAX_A; d++) { 
        non_coprime_pairs += mobius[d] * divisor_pairs[d]; // Apply Mobius
    }

    // Step 4: Calculate total pairs and subtract non-coprime pairs
    ll total_pairs = (ll)n * (n - 1) / 2; // Total pairs
    ll coprime_pairs = total_pairs - non_coprime_pairs; // Coprime pairs

    cout << coprime_pairs << endl; // Output the result

    return 0;
}
