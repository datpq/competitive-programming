#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> depth, ans;
vector<pair<int, int>> price;
vector<vector<int>> parent;
vector<vector<tuple<int, int, int>>> adj;

void dfs1(int node, int prev, int dis) {
    depth[node] = dis;
    parent[node][0] = prev;
    for(auto child : adj[node]) if(get<0>(child) != prev) {
        dfs1(get<0>(child), node, dis+1);
        price[get<0>(child)] = make_pair(get<1>(child), get<2>(child));
    }
}

void dfs2(int node, int prev) {
    for(auto child : adj[node]) if(get<0>(child) != prev) {
        dfs2(get<0>(child), node);
        ans[node] += ans[get<0>(child)];
    }
}

int ancestor(int x, int k) {
    int cnt=0;
    while(k&&x) {
        if(k&1) x = parent[x][cnt];
        k = k>>1; cnt++;
    }
    return x;
}

int lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    a = ancestor(a, depth[a]-depth[b]);
    if(a == b) return a;
    for(int k=19; k>=0; k--) {
        int aa = parent[a][k];
        int bb = parent[b][k];
        if(aa != bb) {
            a = aa; b = bb;
        }
    }
    return parent[a][0];
}

signed main() {
    int n; cin >> n;
    parent = vector<vector<int>>(n, vector<int>(20, 0));
    adj = vector<vector<tuple<int, int, int>>>(n);
    price = vector<pair<int, int>>(n);
    ans = vector<int>(n, 0);
    depth = vector<int>(n);
    for(int i=1; i<n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--; b--;
        adj[a].push_back(make_tuple(b, c, d)); adj[b].push_back(make_tuple(a, c, d));
    }
    dfs1(0, 0, 0);
    for(int k=1; k<20; k++) {
        for(int i=0; i<n; i++) {
            if(parent[i][k-1]) parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }
    for(int i=1; i<n; i++) {
        int a = lca(i-1, i);
        ans[i-1]++; ans[i]++; ans[a]-=2;
    }
    dfs2(0, 0);
    int total=0;
    for(int i=1; i<n; i++) {
        total += min(ans[i]*price[i].first, price[i].second);
    }
    cout << total;
}