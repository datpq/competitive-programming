#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("mootube.in");
    ofstream ofs("mootube.out");
    int n, q; ifs >> n >> q;
    vector<vector<pair<int, int>>> adj(n);
    for(int i=0; i<n-1; i++) {
        int a, b, c; ifs >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<vector<int>> ans(n);
    auto dfs = [&](const auto &self, int root, int node, int prev, int r) -> void {
        if (node != root) ans[root].push_back(r);
        for(auto &child: adj[node]) {
            if (child.first != prev) {
                self(self, root, child.first, node, min(r, child.second));
            }
        }
    };

    for(int i=0; i<q; i++) {
        int k, node; ifs >> k >> node; node--;
        if (ans[node].empty()) dfs(dfs, node, node, -1, 1e9);

        int rc = 0;
        for(auto &x: ans[node]) if (x >= k) rc++;
        ofs << rc << endl;
    }
    
    return 0;
}
