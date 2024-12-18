#include <bits/stdc++.h>
#define int long long

using namespace std;

int rows, cols;
vector<string> grid;
vector<vector<bool>> vis;
int area, perimeter;
const pair<int, int> dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j) {
    if (vis[i][j]) return;
    area++;
    vis[i][j] = true;
    for(auto [dx, dy]: dirs) {
        int x=i+dx, y=j+dy;
        if (x>=0 && x<rows && y>=0 && y<cols && grid[x][y] == grid[i][j]) {
            dfs(x, y);
        } else {
            perimeter++;
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
                area = perimeter = 0;
                dfs(i, j);
                ans += area*perimeter;
            }
        }
    }
    cout << ans;
    return 0;
}