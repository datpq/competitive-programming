#include <bits/stdc++.h>
//FULL Solution : adapted dijstra + bfs

using namespace std;
int n;
vector<int> dis0, disN;

const long long INF = 4e5;
vector<int> dijkstra(vector<vector<int>> &adj, int src) {
    vector<bool> vis(n, false); vis[src] = true;
    vector<int> dis(n, INF);
    dis[src] = 0;
    priority_queue<pair<int, int>> q; q.push({0, src});
    while(!q.empty()) {
        int node = q.top().second; q.pop();
        for(auto child: adj[node]) {
            if (vis[child]) continue;
            vis[child] = true;
            dis[child] = max(1 + dis[node], dis0[child]);
            q.push({-dis[child],child});
        }
    }
    return dis;
}

vector<int> bfs(int src, vector<vector<int>> &adj) {
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
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    int m; cin >> n >> m;
    vector<vector<int>> adj(n), adjrev(n);
    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adjrev[v].push_back(u);
    }
    dis0 = bfs(0, adj);
    disN = bfs(n-1, adjrev);
    vector<int> dis = dijkstra(adjrev, n-1);
    for(int i=0; i<n-1; i++) cout << dis[i] << ' ';
    return 0;
}