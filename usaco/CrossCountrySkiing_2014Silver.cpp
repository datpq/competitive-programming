#include <fstream>
#include <vector>
#include <memory.h>

using namespace std;

vector<pair<int, int>> waypoints;
vector<vector<int>> adj;
int m, n;
bool visited[500][500];

void dfs(int i, int j, int prev, int d) {
    if (i<0 || i>=m || j<0 || j >= n) return;
    if (visited[i][j]) return;
    if (prev>=0 && abs(adj[i][j]-prev) > d) return;
    visited[i][j] = true;
    dfs(i-1, j, adj[i][j], d);
    dfs(i+1, j, adj[i][j], d);
    dfs(i, j-1, adj[i][j], d);
    dfs(i, j+1, adj[i][j], d);
}

bool check(int d) {
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) visited[i][j] = false;
    // memset(visited, false, m*n*sizeof(bool));
    dfs(waypoints[0].first, waypoints[0].second, -1, d);
    for (int i=0; i<waypoints.size(); i++) {
        if (!visited[waypoints[i].first][waypoints[i].second]) return false;
    }
    return true;
}

int firsTrue(int lo, int hi) {
    hi++;
    while (lo < hi)
    {
        int mid = lo + (hi-lo)/2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    ifstream ifs("ccski.in");
    ofstream ofs("ccski.out");
    ifs >> m >> n;

    for(int i=0; i<m; i++) {
        vector<int> v(n);
        for(auto &x: v) ifs >> x;
        adj.push_back(v);
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int a; ifs >> a; if (a == 1) waypoints.push_back({i, j});
        }
    }
    ofs << firsTrue(0, 1e9);

    return 0;
}
