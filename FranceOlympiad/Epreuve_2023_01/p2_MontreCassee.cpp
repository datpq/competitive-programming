#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ans, rayons;
vector<vector<pair<int, int>>> adj;
bool stop = false;
vector<bool> vis;
map<int, vector<int>> rayPos;
map<int, int> rayCnts;

void dfs(int node, int r) {
    if (stop || vis[node]) return;
    if (ans[node] && ans[node] != r) { stop = true; return; }
    ans[node] = r; vis[node] = true;
    rayCnts[r]++; if (rayCnts[r] > rayPos[r].size()) { stop = true; return; }
    for(auto child: adj[node]) {    
        dfs(child.first, child.second-ans[node]);
    }
}

signed main() {
    cin >> n;
    rayons = vector<int>(n);
    adj = vector<vector<pair<int, int>>>(n);
    for(int i=0; i<n; i++) {
        cin >> rayons[i]; rayPos[rayons[i]].push_back(i+1);
    }
    int m; cin >> m;
    while(m--) {
        int u, v, d; cin >> u >> v >> d;
        u--; v--;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    for(auto r: rayPos) {
        ans=vector<int>(n, 0);
        vis = vector<bool>(n, false);
        rayCnts.clear(); stop = false;
        dfs(0, r.first);
        if (!stop) break;
    }
    if (!stop) for(int i=0; i<n; i++) {
        cout << rayPos[ans[i]].back() << " ";
        rayPos[ans[i]].pop_back();
    }
    else cout << "impossible";
    return 0;
}
