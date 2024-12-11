#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    const string dirstr = "^><v";

    vector<string> grid;
    int srcX = -1, srcY = -1, direction;
    string s;
    while(getline(cin, s)) {
        if (srcX==-1 && srcY==-1) {
            for(direction = 0; direction < 4; direction++) {
                string cstr(1, dirstr[direction]);
                int idx = s.find(cstr);
                if (idx >= 0) {
                    srcX = grid.size(); srcY = idx;
                    break;
                }
            }
        }
        grid.push_back(s);
    }
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    queue<pair<int, int>> q; q.push({srcX, srcY});
    int ans = 0;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (!vis[x][y]) ans++;
        vis[x][y] = true;
        auto [dx, dy] = dirs[direction];
        int newX = x+dx, newY = y+dy;
        if (newX < 0 || newX >= rows || newY < 0 || newY >= cols) break;
        if (grid[newX][newY] == '#') {
            direction = (direction + 1) % 4;
            q.push({x, y});
        } else {
            q.push({newX, newY});
        }
    }

    cout << ans;
    return 0;
}