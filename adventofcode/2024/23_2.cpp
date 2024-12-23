#include <bits/stdc++.h>

using namespace std;

const int n=26*26;
map<int, set<int>> adjM;

string toStr(int n) {
    string ans = "  ";
    ans[0] = 'a' + n/26;
    ans[1] = 'a' + n%26;
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif
    string s;
    set<vector<int>> ans;
    while(cin >> s) {
        int u = (s[0]-'a')*26 + (s[1]-'a');
        int v = (s[3]-'a')*26 + (s[4]-'a');
        adjM[u].insert(v);
        adjM[v].insert(u);
        if (u < v) ans.insert({u, v}); else ans.insert({v, u});
    }

    for(int cnt=2; cnt<20; cnt++) {
        set<vector<int>> cur;
        for(auto v: ans) {
            vector<int> nodes(cnt);
            for(int i=0; i<cnt; i++) nodes[i] = v[i];
            for(int node=0; node<n; node++) {
                bool found = true;
                for(int i=0; i<cnt; i++) {
                    if (node == nodes[i] || !adjM[node].count(nodes[i])) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    vector<int> vv = v;
                    vv.push_back(node);
                    sort(vv.begin(), vv.end());
                    cur.insert(vv);
                }
            }
        }
        if (cur.empty()) break;
        ans = cur;
    }
    
    cout << ans.size() << "\n";
    for(int node: *ans.begin()) {
        cout << toStr(node) << ",";
    }

    #ifdef DEBUG
        cout << endl << "__________________________";
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}
