#include <bits/stdc++.h>
#define int long long

using namespace std;

int rows, cols;
vector<string> grid;
vector<vector<bool>> vis;
int area;
vector<pair<int, int>> periLeft, periRight, periTop, periBottom;
const pair<int, int> dirLeft = {0, -1};
const pair<int, int> dirRight = {0, 1};
const pair<int, int> dirTop = {-1, 0};
const pair<int, int> dirBottom = {1, 0};

int getNumOfSize(vector<pair<int, int>> &perimeter) {
    sort(perimeter.begin(), perimeter.end());
    int ans = 0;
    int lastX = -2, lastY = -2;
    for(auto [x, y]: perimeter) {
        if (x > lastX || y > lastY+1) ans++;
        lastX = x, lastY = y;
    }
    return ans;
}

void dfs(int i, int j) {
    if (vis[i][j]) return;
    area++;
    vis[i][j] = true;
    {
        auto [dx, dy] = dirLeft;
        int x=i+dx, y=j+dy;
        if (x>=0 && x<rows && y>=0 && y<cols && grid[x][y] == grid[i][j]) {
            dfs(x, y);
        } else {
            periLeft.emplace_back(y, x);
        }
    }
    {
        auto [dx, dy] = dirRight;
        int x=i+dx, y=j+dy;
        if (x>=0 && x<rows && y>=0 && y<cols && grid[x][y] == grid[i][j]) {
            dfs(x, y);
        } else {
            periRight.emplace_back(y, x);
        }
    }
    {
        auto [dx, dy] = dirTop;
        int x=i+dx, y=j+dy;
        if (x>=0 && x<rows && y>=0 && y<cols && grid[x][y] == grid[i][j]) {
            dfs(x, y);
        } else {
            periTop.emplace_back(x, y);
        }
    }
    {
        auto [dx, dy] = dirBottom;
        int x=i+dx, y=j+dy;
        if (x>=0 && x<rows && y>=0 && y<cols && grid[x][y] == grid[i][j]) {
            dfs(x, y);
        } else {
            periBottom.emplace_back(x, y);
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

    string s;
    while(getline(cin, s)) grid.push_back(s);
    rows = grid.size(), cols = grid[0].size();
    vis = vector<vector<bool>>(rows, vector<bool>(cols, false));
    int ans = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if (!vis[i][j]) {
                area = 0;
                periLeft.clear(); periRight.clear(); periTop.clear(); periBottom.clear();
                dfs(i, j);
                ans += area*(getNumOfSize(periLeft) + getNumOfSize(periRight) + getNumOfSize(periTop) + getNumOfSize(periBottom));
            }
        }
    }
    cout << ans;
    return 0;
}