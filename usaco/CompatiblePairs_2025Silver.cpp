#include <bits/stdc++.h>
#define int long long

using namespace std;

int ans = 0;
map<int, int> nodes;
int n, a, b;
void dfs(int node, int prev) {
    int child = -1;
    if (a-node != prev && nodes.count(a - node) && (a-node != node)) {
        child = a - node;
    } else if (b-node != prev && nodes.count(b - node) && (b-node != node)) {        
        child = b - node;
    }
    if (child != -1) {
        dfs(child, node);
        int diff = min(nodes[node], nodes[child]);
        ans += diff;
        nodes[node] -= diff;
        nodes[child] -= diff;
        if (nodes[node] == 0) {
            nodes.erase(node);
        }
        if (nodes[child] == 0) {
            nodes.erase(child);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    for(int i=0; i<n; i++) {
        int w, id; cin >> w >> id;
        nodes[id] = w;
    }

    while(!nodes.empty()) {
        int prevans = ans;
        dfs(nodes.begin()->first, -1);
        if (ans == prevans) {
            if (nodes.begin()->first * 2 == a || nodes.begin()->first * 2 == b) {
                ans += nodes.begin()->second / 2;
            }
            nodes.erase(nodes.begin());
        }
    }
    cout << ans << '\n';
    return 0;
}
