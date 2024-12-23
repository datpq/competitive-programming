#include <bits/stdc++.h>
#define int long long

using namespace std;

const int n=26*26;
vector<vector<int>> adj(n);
map<int, set<int>> adjM;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif
    string s;
    while(cin >> s) {
        int u = (s[0]-'a')*26 + (s[1]-'a');
        int v = (s[3]-'a')*26 + (s[4]-'a');
        adj[u].push_back(v);
        adj[v].push_back(u);
        adjM[u].insert(v);
        adjM[v].insert(u);
    }

    set<vector<int>> ans;
    for(auto &[k, val]: adjM) {
        if (k/26 == 't'-'a') {
            for(int node: adj[k]) {
                for(int child: adj[node]) {
                    if (adjM[k].count(child)) {
                        vector<int> v = {k, node, child};
                        sort(v.begin(), v.end());
                        ans.insert(v);
                    }
                }
            }
        }
    }
    cout << ans.size();
    return 0;
}
