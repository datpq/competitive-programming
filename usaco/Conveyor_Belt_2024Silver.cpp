#include <bits/stdc++.h>

using namespace std;

const string DIRS = "LRUD";
const vector<pair<int, int>> DIR = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<string> grid;
vector<vector<bool>> good;
int n;

int goodCount;
void dfs(int x, int y) {
    good[x][y] = true;
    goodCount++;
    for(int i=0; i<4; i++) {
        auto [dx, dy] = DIR[i];
        int xx = x+dx, yy = y+dy;
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && !good[xx][yy] && (grid[xx][yy] == '?' || grid[xx][yy] == DIRS[i])) {
            dfs(xx, yy);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> n >> q;
    grid = vector<string>(n, string(n, '?'));
    good = vector<vector<bool>>(n, vector<bool>(n, false));
    vector<tuple<int, int, char>> queries;
    for(int i=0; i<q; i++) {
        int x, y; char c;
        cin >> x >> y >> c; x--; y--;
        grid[x][y] = c;
        queries.emplace_back(x, y, c);
    }
    goodCount = 0;
    for(int i=0; i<n; i++) {
        if ((grid[i][0] == '?' || grid[i][0] == 'L')  && !good[i][0]) dfs(i, 0);
        if ((grid[i][n-1] == '?' || grid[i][n-1] == 'R')  && !good[i][n-1]) dfs(i, n-1);
        if ((grid[0][i] == '?' || grid[0][i] == 'U')  && !good[0][i]) dfs(0, i);
        if ((grid[n-1][i] == '?' || grid[n-1][i] == 'D')  && !good[n-1][i]) dfs(n-1, i);
    }
    vector<int> ans;
    ans.push_back(n*n - goodCount);
    for(int i=q-1; i>0; i--) {
        auto [x, y, c] = queries[i];
        grid[x][y] = '?';
        if (!good[x][y]) {
            bool isGood = (x==0 || x==n-1 || y==0 || y==n-1);
            if (!isGood) {
                for(auto [dx, dy]: DIR) {
                    int xx=x+dx, yy=y+dy;
                    if (xx>=0 && xx<n && yy>=0 && yy<n && good[xx][yy]) {
                        isGood = true;
                        break;
                    }
                }
            }
            if (isGood) dfs(x, y);
        }
        ans.push_back(n*n - goodCount);
    }
    for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << "\n";
    return 0;
}