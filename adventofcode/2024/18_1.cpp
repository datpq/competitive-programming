#include <bits/stdc++.h>
#define int long long

using namespace std;

const int rows = 71, cols = 71;
vector<string> grid(rows, string(cols, '.'));
const pair<int, int> dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int srcX = 0, srcY = 0, destX = rows-1, destY = cols-1;
const int Fallen = 1024;
vector<vector<int>> dis(rows, vector<int>(cols, 0));

void bfs() {
    vector<vector<bool>> vis(rows, vector<bool>(cols, false));
    queue<pair<int, int>> q; q.push({srcX, srcY}); vis[srcX][srcY] = true;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(auto [dx, dy]: dirs) {
            int cx = x+dx, cy=y+dy;
            if (cx < 0 || cx >= rows || cy < 0 || cy >= cols || vis[cx][cy] || grid[x][y] == '#') continue;
            dis[cx][cy] = dis[x][y]+1;
            vis[cx][cy] = true;
            q.push({cx, cy});
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    int x, y; char c;
    int cnt = 0;
    while(cin >> y) {
        cin >> c >> x;
        if (cnt++ < Fallen) grid[x][y] = '#';
    }

    bfs();
    cout << dis[destX][destY];
    return 0;
}