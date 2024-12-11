#include <bits/stdc++.h>
#define int long long

using namespace std;

int getIdx(char c) {
    int idx = (c>='a' && c<='z') ? c-'a' : (c>='A' && c<='Z') ? 26 + (c - 'A') : (c>='0' && c<='9') ? 52 + (c-'0') : -1;
    return idx;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    vector<string> grid;
    vector<vector<pair<int, int>>> v(62);
    string s;
    int i=0;
    while(getline(cin, s)) {
        for(int j=0; j<s.length(); j++) {
            int idx = getIdx(s[j]);
            if (idx>=0) v[idx].emplace_back(i, j); 
        }
        i++;
        grid.push_back(s);
    }
    int rows = grid.size(), cols = grid[0].size();
    set<pair<int, int>> antis;
    for(auto &u: v) {
        if (u.size() < 2) continue;
        for(int i=0; i<u.size()-1; i++) {
            auto [x1, y1] = u[i];
            for(int j=i+1; j<u.size(); j++) {
                auto [x2, y2] = u[j];
                pair<int, int> coordis[2] = {{2*x1-x2, 2*y1-y2}, {2*x2-x1, 2*y2-y1}};
                for(auto [x, y]: coordis) {
                    if (x>=0 && x<rows && y>=0 && y<cols) antis.insert({x, y});
                }
            }
        }
    }
    cout << antis.size();
    return 0;
}