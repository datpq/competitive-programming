```cpp
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MX = 200042;

vector<int> adj[MX];

int dep[MX];
int up[MX][20];
bool covered[MX];

void dfsInit(int node, int d) {
    dep[node] = d;
    for (auto& x: adj[node]) {
        if (x == up[node][0])
            continue;
        up[x][0] = node;
        for (int it = 1; it < 20; it++)
            up[x][it] = up[up[x][it - 1]][it - 1];
        dfsInit(x, d + 1);
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v])
        swap(u, v);

    int dif = dep[v] - dep[u];
    for (int bit = 0; bit < 20; bit++) {
        if ((((int)1 << bit) & dif) != 0) {
            v = up[v][bit];
        }
    }

    if (u == v)
        return u;

    for (int bit = 19; bit >= 0; bit--) {
        if (up[u][bit] != up[v][bit]) {
            u = up[u][bit];
            v = up[v][bit];
        }
    }

    return up[u][0];
}

void mark(int node) {
    if (covered[node])
        return;
    covered[node] = true;
    for (auto& x: adj[node])
        if (x != up[node][0])
            mark(x);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        covered[i] = false;
        for (int j = 0; j < 20; j++)
            up[i][j] = 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsInit(0, 0);

    vector<pair<int, pair<int, int>>> mid {};

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int m = lca(u, v);
        mid.push_back({-dep[m], {u, v}});
    }

    sort(mid.begin(), mid.end());

    int ans = 0;
    for (auto& x: mid) {
        int u = x.se.fi;
        int v = x.se.se;
        int m = lca(u, v);

        if (covered[u] || covered[v])
            continue;

        mark(m);
        ans++;
    }

    cout << ans << '\n';
}```