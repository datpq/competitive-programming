#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int a, int b) {  // union by size
        a = get(a), b = get(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

int n, m;
int node(pair<int, int> u) {
    return u.first * (m+1) + u.second;
}

signed main() {
    ifstream  ifs("fencedin.in");
    ofstream ofs("fencedin.out");
    int A, B;
    ifs >> A >> B >> n >> m;
    vector<int> a(n+2), b(m+2); a[0] = b[0] = 0; a[n+1] = A; b[m+1] = B;
    for(int i = 1; i <= n; i++) ifs >> a[i];
    for(int i = 1; i <= m; i++) ifs >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<tuple<int, pair<int, int>, pair<int, int>>> edges;
    for(int i=1; i<=n+1; i++) {
        for(int j=1; j<=m+1; j++) {
            if (j<=m) edges.push_back({(a[i] - a[i-1]), {i-1, j-1}, {i-1, j}});
            if (i<=n) edges.push_back({(b[j] - b[j-1]), {i-1, j-1}, {i, j-1}});
        }
    }
    sort(edges.begin(), edges.end());
    DSU dsu((n+1)*(m+1));
    long long ans = 0;
    for(auto &[cost, u, v] : edges) {
        if (dsu.unite(node(u), node(v))) {
            ans += cost;
        }
    }
    ofs << ans << "\n";
    return 0;
}