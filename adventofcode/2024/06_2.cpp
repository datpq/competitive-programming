#include <bits/stdc++.h>
#define int long long

using namespace std;

const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const string dirstr = "^><v";
vector<string> grid;
int srcX = -1, srcY = -1, srcDirection, direction;
int rows, cols;
set<pair<int, int>> path;

bool bfs() {
    // vector<vector<vector<bool>>> vis(rows, vector<vector<bool>>(cols, vector<bool>(4, false)));
    set<tuple<int, int, int>> vis;
    queue<tuple<int, int, int>> q; q.push({srcX, srcY, srcDirection});
    bool filling = path.empty();
    while(!q.empty()) {
        auto [x, y, direction] = q.front(); q.pop();
        if (filling) path.insert({x, y});
        // if (vis[x][y][direction]) return true;
        // vis[x][y][direction] = true;
        if (vis.count(make_tuple(x, y, direction))) return true;
        vis.insert(make_tuple(x, y, direction));
        auto [dx, dy] = dirs[direction];
        int newX = x+dx, newY = y+dy;
        if (newX < 0 || newX >= rows || newY < 0 || newY >= cols) return false;
        if (grid[newX][newY] == '#') {
            direction = (direction + 1) % 4;
            q.push({x, y, direction});
        } else {
            q.push({newX, newY, direction});
        }
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    string s;
    while(getline(cin, s)) {
        if (srcX==-1 && srcY==-1) {
            for(srcDirection = 0; srcDirection < 4; srcDirection++) {
                string cstr(1, dirstr[srcDirection]);
                int idx = s.find(cstr);
                if (idx >= 0) {
                    srcX = grid.size(); srcY = idx;
                    break;
                }
            }
        }
        grid.push_back(s);
    }

    rows = grid.size(), cols = grid[0].size();
    grid[srcX][srcY] = '.';
    bfs();

    int ans = 0;
    path.erase({srcX, srcY}); //do not take the start position
    for(auto [x, y]: path) {
        grid[x][y] = '#';
        if (bfs()) ans++;
        grid[x][y] = '.';
    }
    #ifdef DEBUG
        cout << endl << "__________________________";
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    cout << ans;
    return 0;
}