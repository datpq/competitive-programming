#include <bits/stdc++.h>

using namespace std;
int n, val;
vector<int> a, b, ab, idx;
vector<tuple<int, int, int>> ans;
vector<bool> vis;

void dfs(int u) {
    if (vis[u]) return;
    int v = ab[u];
    vis[u] = vis[v] = true;
    int t = (2*n + val - u) % (2*n);
    if (t != v) {
        ans.emplace_back(idx[u], v, t);
        dfs(ab[t]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    cin >> n;
    a = b = vector<int>(n);
    ab = idx = vector<int>(2*n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        idx[a[i]] = idx[b[i]] = i;
        ab[a[i]] = b[i];
        ab[b[i]] = a[i];
    }
    vector<int> midpoints(2*n, 0);
    for(int i = 0; i < n; i++) {
        midpoints[(a[i] + b[i]) % (2*n)]++;
    }
    val = 1; int mx = 0;
    for(int i=1; i<2*n; i+=2) {
        if (midpoints[i] > mx) {
            val = i;
            mx = midpoints[i];
        }
    }

    vis = vector<bool>(2*n, false);
    for(int i=0; i<n; i++) {
        dfs(a[i]);
    }

    cout << ans.size() << "\n";
    for(auto &[x, y, z] : ans) {
        cout << x << ' ' << y << ' ' << z << '\n';
    }
    return 0;
}