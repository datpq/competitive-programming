#include <bits/stdc++.h>
//sub task 4 TOPO

using namespace std;
int n;
vector<int> dis0, disN;
vector<int> dp;

vector<int> vis, topo;
void dfs(int node, vector<vector<int>> &adj) {
    if (vis[node]) return;
    vis[node] = 1;
    for(auto child : adj[node]) dfs(child, adj);
    vis[node] = 2;
    topo.push_back(node);
}

vector<int> bfs(int src, vector<vector<int>> adj) {
    queue<int> q;
    vector<bool> vis(n, false);
    vector<int> dis(n, 2e5);
    vis[src] = true; dis[src] = 0;
    q.push(src);
    while(!q.empty()) {
        int node=q.front(); q.pop();
        for(auto child: adj[node]) {
            if (vis[child]) continue;
            dis[child] = dis[node]+1;
            q.push(child);
            vis[child] = true;
        }
    }
    return dis;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m; cin >> n >> m;
    vector<vector<int>> adj(n), adjrev(n);
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adjrev[v].push_back(u);
    }
    dis0 = bfs(0, adj);
    disN = bfs(n-1, adjrev);
    vis = vector<int>(n, 0);
    dfs(0, adj);
    dp = vector<int>(n, 4e5);
    dp[n-1] = 0;
    for(int i=1; i<n; i++) {
        int node = topo[i];
        for(auto child : adj[node]) {
            dp[node] = min(dp[node], dp[child] + 1);
        }
        dp[node] = max(dp[node], dis0[node]);
    }

    for(int i=0; i<n-1; i++) {
        cout << dp[i] << ' ';
    }
    return 0;
}
