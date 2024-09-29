#include <bits/stdc++.h>

using namespace std;

const int INF = 127*127;

const vector<vector<int>> D = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<vector<pair<int, int>>> dijkstra(vector<string> &grid, int srcX, int srcY) {
    int n = grid.size();
    vector<vector<bool>> processed(n, vector<bool>(n, false));
    vector<vector<pair<int, int>>> distance(n, vector<pair<int, int>>(n, {INF, INF}));
    distance[srcX][srcY] = {0, 0};
    priority_queue<vector<int>> q; q.push({0, 0, srcX, srcY});
    while(!q.empty()) {
        vector<int> node = q.top(); q.pop();
        int x = node[2], y = node[3];
        if (processed[x][y]) continue;
        processed[x][y] = true;
        for(auto d: D) {
            int childX = x+d[0];
            int childY = y+d[1];
            if (childX < 0 || childX >= n || childY < 0 || childY >=n) continue;
            pair<int, int> newDis = {
                distance[x][y].first + (grid[childX][childY] == '1' ? 1 : 0),
                distance[x][y].second + (grid[childX][childY] == '0' ? 1 : 0)
            };
            if (newDis.first < distance[childX][childY].first) {
                distance[childX][childY] = newDis;
                q.push({-newDis.first, -newDis.second, childX, childY});
            }
        }
    }
    return distance;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];
    auto distance = dijkstra(grid, 0, 0);
    cout << distance[n-1][n-1].second;
    return 0;
}