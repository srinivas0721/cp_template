#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n' 
#define INF LLONG_MAX>>1
const int MOD = 1e9 + 7;

int T = 1000;
const int MAX_N = 50, MAX_M = 50;

char randomChar() {
    return (rand() % 2) + '0';
}

vector<string> generateTestCase(int &n, int &m) {
    n = rand() % MAX_N + 1;
    m = rand() % MAX_M + 1;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i] += randomChar();
        }
    }
    return grid;
}

// User's original implementation
string userSolution(int n, int m, vector<string> &grid) {
    vector<vector<int>> v(n + 2, vector<int>(m + 2, 1));
    vector<vector<bool>> v1(n + 2, vector<bool>(m + 2, true));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i][j] = grid[i - 1][j - 1] - '0';
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == 1) {
                v1[i][j] = v1[i - 1][j] || v1[i][j - 1];
            } else {
                v1[i][j] = false;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] != v1[i][j]) {
                return "NO";
            }
        }
    }
    return "YES";
}

// Correct implementation
string correctSolution(int n, int m, vector<string> &grid) {
    int a[55][55], p[55][55] = {0};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            a[i][j] = grid[i - 1][j - 1] - '0';
        }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) p[i][j] = 1;
            else break;
        }
    }
    
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 1) p[i][j] = 1;
            else break;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] && !p[i][j]) return "NO";
        }
    }
    return "YES";
}

int32_t main() {
    srand(time(0));
    while (T--) {
        int n, m;
        vector<string> grid = generateTestCase(n, m);
        
        string userAns = userSolution(n, m, grid);
        string correctAns = correctSolution(n, m, grid);
        
        if (userAns != correctAns) {
            cout << "Found failing test case!\n";
            cout << "n = " << n << ", m = " << m << "\n";
            for (auto &row : grid) cout << row << "\n";
            cout << "User Output: " << userAns << "\n";
            cout << "Correct Output: " << correctAns << "\n";
            return 0;
        }
    }
    cout << "All tests passed!" << endl;
    return 0;
}