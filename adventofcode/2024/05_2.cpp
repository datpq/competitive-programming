#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100;

vector<vector<int>> adj(N+1);
vector<int> vis(N+1, 0), topo;
set<int> subnodes;

void dfs(int node) {
    if (vis[node]) return;
    if (!subnodes.count(node)) return;
    vis[node] = 1;
    for(auto child : adj[node]) dfs(child);
    vis[node] = 2;
    topo.push_back(node);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    int ans = 0;
    string s;
    bool firstPart = true;
    while(getline(cin, s)) {
        if (s.empty()) {
            firstPart = false;
            continue;
        }
        stringstream ss(s);
        int u, v; char c;
        if (firstPart) {
            ss >> u >> c >> v;
            adj[u].push_back(v);
        } else {
            bool correctOrder = true;
            subnodes.clear();
            vector<int> v;
            ss >> u; v.push_back(u); subnodes.insert(u);
            while(ss >> c) {
                ss >> u; v.push_back(u);
                subnodes.insert(u);
            }

            vis = vector<int>(N+1, 0); topo.clear();
            for(int i=0; i<v.size(); i++) {
                if (vis[v[i]]==0) dfs(v[i]);
            }
            int idx = topo.size()-1;
            for(auto node: v) {
                while(idx>=0 && topo[idx] != node) idx--;
                if (idx<0) {
                    correctOrder = false; break;
                }
            }
            if (!correctOrder) {
                reverse(topo.begin(), topo.end());
                ans += topo[topo.size()/2];
            }
        }
   }
    cout << ans;
    return 0;
}