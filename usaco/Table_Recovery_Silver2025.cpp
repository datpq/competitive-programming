#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    map<int, vector<pair<int, int>>> stats;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> g[i][j];
            stats[g[i][j]].emplace_back(i, j);
        }
    }

    if (n==1) {
        cout << 2; return 0;
    }

    vector<vector<pair<int, int>>> cnt(n+1);
    for(auto &[_, v]: stats) {
        for(auto &[i, j]: v) {
            cnt[v.size()].emplace_back(i, j);
        }
    }

    auto compute = [&](int row2, int row2n) -> vector<vector<int>> {
        map<int, int> swaps;
        auto [midX, midY] = *cnt[n].begin();
        swaps[g[midX][midY]] = n+1;// diagonal line
        for(auto x: g[row2]) {
            if (x == g[midX][midY]) continue;
            swaps[x] = 1 + stats[x].size();
        }
        for(auto x: g[row2n]) {
            if (x == g[midX][midY]) continue;
            swaps[x] = 2*n + 1 - stats[x].size();
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans[i][j] = swaps[g[i][j]];
            }
        }
        return ans;
    };

    auto ans1 = compute(cnt[1][0].first, cnt[1][1].first);
    auto ans2 = compute(cnt[1][1].first, cnt[1][0].first);
    auto ans = min(ans1, ans2);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << ans[i][j] << (j==n-1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
