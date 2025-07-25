#include <iostream>
#include <vector>
#include <string>

using namespace std;

//https://www.youtube.com/watch?v=ynv7bbcSLKE


// Function to compute the LPS array
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);  // LPS array to store the longest prefix-suffix lengths
    int length = 0;  // Length of the previous longest prefix suffix
    int i = 1;

    // Compute the LPS array
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];  // Use the LPS array to avoid unnecessary comparisons
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Function to perform KMP search
void KMPSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // Compute the LPS array for the pattern
    vector<int> lps = computeLPSArray(pattern);

    int i = 0;  // Index for text
    int j = 0;  // Index for pattern

    // Search for the pattern in the text
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // Match found at index (i - j)
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];  // Continue to search for other matches
        } else if (i < n && pattern[j] != text[i]) {
            // Mismatch after some matches
            if (j != 0) {
                j = lps[j - 1];  // Use the LPS array to skip ahead
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababa";

    // Perform the KMP search
    KMPSearch(text, pattern);

    return 0;
}
