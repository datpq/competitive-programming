#include <bits/stdc++.h>
#define int long long

using namespace std;

int rows, cols;
vector<string> grid;
int srcX, srcY;
const pair<int, int> dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const string dirstr = "><v^";

void move(char dirc) {
    auto [dx, dy] = dirs[dirstr.find(dirc)];
    int x=srcX, y=srcY;
    while(grid[x][y] != '#' && grid[x][y] != '.') {
        x+=dx, y+=dy;
    }
    if (grid[x][y] == '.') {
        while(!(x == srcX && y == srcY)) {
            grid[x][y] = grid[x-dx][y-dy];
            x-=dx; y-=dy;
        }
        grid[x][y] = '.';
        srcX+=dx; srcY+=dy;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    string s, path;
    bool pathReading = false;
    while(getline(cin, s)) {
        if (pathReading) {
            path += s;            
        } else if (!s.empty()) {
            if (s.find('@') != string::npos) {
                srcX = grid.size();
                srcY = s.find('@');
            }
            grid.push_back(s);
        } else {
            pathReading = true;
        }
    }
    rows = grid.size(), cols = grid[0].size();
    for(auto c: path) move(c);
    int ans = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if (grid[i][j] == 'O') {
                ans += 100*i + j;
            }
        }
    }
    cout << ans;
    return 0;
}