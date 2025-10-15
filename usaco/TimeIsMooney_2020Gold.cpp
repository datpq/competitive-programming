#include <bits/stdc++.h>

using namespace std;

int N, M, C;
vector<int> m;
vector<vector<int>> adj, dp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream ifs("time.in");
    ofstream ofs("time.out");
    ifs >> N >> M >> C;
    m = vector<int>(N);
    dp = vector<vector<int>>(N, vector<int>(1001, -1));
    dp[0][0] = 0;
    adj = vector<vector<int>>(N);
    for (int i = 0; i < N; i++) ifs >> m[i];
    for(int i=0; i<M; i++) {
        int u, v; ifs >> u >> v; u--; v--;
        adj[u].push_back(v);
    }
    int ans = 0;
    for(int d=0; d<1000; d++) {
        for(int node=0; node<N; node++) {
            if(dp[node][d] == -1) continue;
            for(auto child: adj[node]) {
                dp[child][d+1] = max(dp[child][d+1], dp[node][d] + m[child]);
            }
        }
        ans = max(ans, dp[0][d+1] - C*(d+1)*(d+1));
    }
    ofs << ans << "\n";
    return 0;
}