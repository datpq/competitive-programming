#include <bits/stdc++.h>
#define int long long

using namespace std;

int rows, cols;
vector<string> grid;
const pair<int, int> dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int INF = 1e9;

vector<pair<int, int>> findPath(int srcX, int srcY, int destX, int destY) {
    vector<pair<int, int>> ans = {{srcX, srcY}};
    int lastX=-1, lastY=-1;
    while (srcX != destX || srcY != destY) {
        for(auto [dx, dy]: dirs) {
            int x=srcX+dx, y=srcY+dy;
            if ((x != lastX || y!= lastY) && grid[x][y] != '#') {
                ans.emplace_back(x, y);
                lastX = srcX, lastY = srcY;
                srcX = x, srcY = y;
                continue; // unique path
            }
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    string line;
    int srcX, srcY, destX, destY;

    while(cin >> line) {
        if (line.find('S') != string::npos) {
            srcX = grid.size(); srcY = line.find('S');
        } else if (line.find('E') != string::npos) {
            destX = grid.size(); destY = line.find('E');
        }
        grid.push_back(line);
    }
    rows = grid.size(), cols = grid[0].size();
    auto path = findPath(srcX, srcY, destX, destY);

    int ans = 0;
    vector<vector<vector<int>>> vis(rows, vector<vector<int>>(cols));
    for(int i=0; i<path.size(); i++) {
        auto [x, y] = path[i];
        for(auto [dx, dy]: dirs) {
            int cx=x+dx, cy=y+dy;
            int ccx=x+2*dx, ccy=y+2*dy;
            if (ccx>=0 && ccx<rows && ccy>=0 && ccy<cols
                && grid[cx][cy] == '#' && grid[ccx][ccy] != '#') {
                vis[ccx][ccy].push_back(i);
            }
        }
        for (auto j: vis[x][y]) {
            if (i-j-2>=100) ans++;
        }
    }
    cout << ans;
    return 0;
}