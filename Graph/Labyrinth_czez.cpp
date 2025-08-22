#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1193
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    pair<int,int> start, end;

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') start = {i,j};
            if(grid[i][j] == 'B') end = {i,j};
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m,false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int r = cur.first, c = cur.second;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m 
               && !visited[nr][nc] && grid[nr][nc] != '#') {
                visited[nr][nc] = true;
                parent[nr][nc] = {r,c};
                q.push({nr,nc});
            }
        }
    }

    if(!visited[end.first][end.second]) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<char> path;
    pair<int,int> cur = end;
    while(cur != start) {
        pair<int,int> p = parent[cur.first][cur.second];
        int drMove = cur.first - p.first;
        int dcMove = cur.second - p.second;

        if(drMove == -1) path.push_back('U');
        else if(drMove == 1) path.push_back('D');
        else if(dcMove == -1) path.push_back('L');
        else if(dcMove == 1) path.push_back('R');

        cur = p;
    }

    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for(char ch : path) cout << ch;
    cout << "\n";

    return 0;
}
