#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int WALL = 1e5;

const vector<vector<int>> D = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<vector<int>> dijkstra(vector<string> &grid, int srcX, int srcY) {
    int n = grid.size();
    vector<vector<bool>> processed(n, vector<bool>(n, false));
    vector<vector<int>> distance(n, vector<int>(n, INF));
    distance[srcX][srcY] = 0;
    priority_queue<vector<int>> q; q.push({0, srcX, srcY});
    while(!q.empty()) {
        vector<int> node = q.top(); q.pop();
        int x = node[1], y = node[2];
        if (processed[x][y]) continue;
        processed[x][y] = true;
        for(auto d: D) {
            int childX = x+d[0];
            int childY = y+d[1];
            if (childX < 0 || childX >= n || childY < 0 || childY >=n) continue;
			int newDis = distance[x][y] + (grid[childX][childY] == '1' ? WALL : 1);
            if (newDis < distance[childX][childY]) {
                distance[childX][childY] = newDis;
                q.push({-newDis, childX, childY});
            }
        }
    }
    return distance;
}

int main() {
    int n; cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];
    auto distance = dijkstra(grid, 0, 0);
    cout << distance[n-1][n-1] % WALL;
    return 0;
}
