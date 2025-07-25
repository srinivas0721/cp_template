#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Predefined prime numbers for characters 'a' to 'z'
        vector<int> primes = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
            47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
        };

        // Large prime number for modulo
        const long long MOD = 1e9 + 7;

        // Hash map to store grouped anagrams
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& s : strs) {
            int xor_hash = 0;
            long long product_hash = 1;

            for (char c : s) {
                int index = c - 'a';
                xor_hash ^= c;                           // XOR hash
                product_hash = (product_hash * primes[index]) % MOD; // Product hash with modulo
            }

            // Create a unique key as a string
            string key = to_string(xor_hash) + "#" + to_string(product_hash);
            anagramGroups[key].push_back(s);
        }

        // Prepare the result from the hash map
        vector<vector<string>> result;
        for (const auto& entry : anagramGroups) {
            result.push_back(entry.second);
        }

        return result;
    }
};
