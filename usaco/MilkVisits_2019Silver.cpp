#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("milkvisits.in");
    ofstream ofs("milkvisits.out");
    int n, m; string pref; ifs >> n >> m >> pref;

    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++) {
        int a, b; ifs >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> groupIds(n);
    auto dfs = [&](const auto &self, int node, int prev, int id) -> void {
        groupIds[node] = id;
        for(auto &child: adj[node]) {
            if (child != prev && pref[child] == pref[node]) self(self, child, node, id);
        }
    };

    int id=0;
    for(int i=0; i<n; i++) {
        if (!groupIds[i]) dfs(dfs, i, -1, ++id);
    }

    for(int i=0; i<m; i++) {
        int a, b; char c; ifs >> a >> b >> c; a--; b--;
        ofs << ((groupIds[a] == groupIds[b] && pref[a] != c) ? 0 : 1);
    }
    
    return 0;
}
