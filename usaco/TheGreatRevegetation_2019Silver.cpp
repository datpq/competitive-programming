#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("revegetate.in");
    ofstream ofs("revegetate.out");
    int n, m; ifs >> n >> m;
    vector<vector<pair<bool, int>>> adj(n);
    vector<int> groupIds(n, -1);

    for(int i=0; i<m; i++) {
        char c; int a, b; ifs >> c >> a >> b; a--; b--;
        adj[a].push_back({c == 'S', b});
        adj[b].push_back({c == 'S', a});
    }
    bool impossible = false;
    auto dfs = [&](const auto &self, int node, int id) -> void {
        if (impossible) return;
        if (groupIds[node] == id) return;
        if (groupIds[node] >= 0) { impossible= true; return; }
        groupIds[node] = id;
        for(auto child: adj[node])self(self, child.second, child.first ? id : 1 - id);
    };
    string ans = "1";
    for(int i=0; i<n; i++) {
        if (impossible) break;
        if (groupIds[i] < 0) {
            dfs(dfs, i, 0);
            ans += "0";
        }
    }
    ofs << (impossible ? "0" : ans);
    return 0;
}
