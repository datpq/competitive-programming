#include <bits/stdc++.h>
#define int long long

using namespace std;

int rows, cols;
vector<string> grid;
vector<vector<bool>> vis;
const pair<int, int> dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int srcX, srcY, destX, destY;
int best = INT_MAX;

const int INF = INT_MAX;
map<tuple<int, int, int>, vector<tuple<int, int, int>>> prec;
vector<vector<vector<int>>> dijkstra() {
    vector<vector<vector<bool>>> processed(rows, vector<vector<bool>>(cols, vector<bool>(4, false)));
    vector<vector<vector<int>>> distance(rows, vector<vector<int>>(cols, vector<int>(4, INF)));
    distance[srcX][srcY][0] = 0;
    priority_queue<tuple<int, int, int, int>> q; q.push({0, srcX, srcY, 0});
    while(!q.empty()) {
        auto [d, x, y, dir] = q.top(); q.pop();
        if (processed[x][y][dir]) continue;
        processed[x][y][dir] = true;
        auto [dx, dy] = dirs[dir];
        int childX = x+dx, childY = y+dy;
        if (childX>=0 && childX<rows && childY>=0 & childY<cols && grid[childX][childY] != '#') {
            if (distance[x][y][dir] + 1 <= distance[childX][childY][dir]) {
                if (distance[x][y][dir] + 1 < distance[childX][childY][dir]) {
                    prec[{childX, childY, dir}].clear();
                }
                prec[{childX, childY, dir}].emplace_back(x, y, dir);
                distance[childX][childY][dir] = distance[x][y][dir] + 1;
                q.push({-distance[childX][childY][dir], childX, childY, dir});
            }
        }
        for(int i=0; i<4; i++) {
            if (i == dir) continue;
            if (min(i, dir)<=1 && max(i, dir)>1) {
                if (distance[x][y][dir] + 1000 <= distance[x][y][i]) {
                    if (distance[x][y][dir] + 1000 < distance[x][y][i]) {
                        prec[{x, y, i}].clear();
                    }
                    prec[{x, y, i}].emplace_back(x, y, dir);
                    distance[x][y][i] = distance[x][y][dir] + 1000;
                    q.push({-distance[x][y][i], x, y, i});
                }
            }
        }
    }
    return distance;
}

void dfs(int i, int j, int dirx, int diry, int score) {
    if (vis[i][j]) return;
    if (score >= best) return;
    if (i==destX && j==destY) {
        best = score;
        return;
    }
    vis[i][j] = true;
    for(auto [dx, dy]: dirs) {
        int x=i+dx, y=j+dy;
        if (x<0 || x>=rows || y<0 || y>=cols || grid[x][y] == '#') continue;
        int newscore = score;
        if (dx == dirx) {
            if (dy == diry) {
                 newscore++;
            } else {
                newscore += 2001;
            }
        } else newscore += 1001;
        dfs(x, y, dx, dy, newscore);
    }
    vis[i][j] = false;
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
        if (s.find('S') != string::npos) {
            srcX = grid.size();
            srcY = s.find('S');
        } else if (s.find('E') != string::npos) {
            destX = grid.size();
            destY = s.find('E');
        }
        grid.push_back(s);
    }
    rows = grid.size(), cols = grid[0].size();
    vis = vector<vector<bool>>(rows, vector<bool>(cols, false));

    // dfs(srcX, srcY, 0, 1, 0);
    auto dis = dijkstra();
    vector<int> bestDirs;
    for(int i=0; i<4; i++) {
        if (best >= dis[destX][destY][i]) {
            if (best > dis[destX][destY][i]) {
                bestDirs.clear();
            }
            bestDirs.push_back(i);
            best = dis[destX][destY][i];
        }
    }
    cout <<  best << "\n";
    set<pair<int, int>> st;
    for(auto dir: bestDirs) {
        queue<tuple<int, int, int>> qq;
        qq.push({destX, destY, dir});
        while(!qq.empty()) {
            auto [x, y, dir] = qq.front(); qq.pop();
            st.insert({x, y});
            for(auto [px, py, pdir]: prec[{x, y, dir}]) {
                qq.push({px, py, pdir});
            }
        }
    }
    cout << st.size() << "\n";
    return 0;
}