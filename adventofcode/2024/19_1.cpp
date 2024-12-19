#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<string> patterns;
vector<bool> vis;

bool found = false;
void dfs(string &s, int idx) {
    if (idx == s.length()) found = true;
    if (found || vis[idx]) return;
    vis[idx] = true;
    for(auto &pat: patterns) {
        if (s.rfind(pat, idx) == idx) {
            dfs(s, idx + pat.size());
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    string s;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> s) {
        if (s.back() == ',') s=s.substr(0, s.length() - 1);
        patterns.push_back(s);
    }
    
    int ans = 0;
    while(getline(cin, s)) {
        if (s.empty()) continue;
        found = false;
        vis = vector<bool>(s.length(), false);
        dfs(s, 0);
        if (found) ans++;
    }
    cout << ans;
    return 0;
}