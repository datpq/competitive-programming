#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> parent;

void dfs(int node, int prev) {
    parent[node] = prev;
    for(auto child: adj[node]) {
        if (child != prev) dfs(child, node);
    }
}

bool disOk(int src, int dest) {
    vector<int> srcAncestors, destAncestors;
    int node=src, cnt=0;
    while(node!=-1 && cnt!=4) {
        srcAncestors.push_back(node);
        node = parent[node]; cnt++;
    }
    node=dest, cnt=0;
    while(node!=-1 && cnt!=4) {
        destAncestors.push_back(node);
        node = parent[node]; cnt++;
    }
    for(int i=0; i<srcAncestors.size(); i++) {
        for(int j=0; j<destAncestors.size(); j++) {
            if (srcAncestors[i] == destAncestors[j] && i+j<=3) return true;
        }
    }
    return false;
}

int solve() {
    cin >> n;
    parent = vector<int>(n);
    adj = vector<vector<int>>(n);
    for(int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0, -1);
    int src; cin >> src; src--;
    bool ans=true;
    for(int i=0; i<n-1; i++) {
        int dest; cin >> dest; dest--;
        if (ans && !disOk(src, dest)) ans=false;
        src = dest;
    }
    return ans;
}

signed main() {
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
    return 0;
}
