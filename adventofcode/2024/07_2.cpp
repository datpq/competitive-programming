#include <bits/stdc++.h>
#define int long long

using namespace std;

bool found = false;
int result;
void dfs(int cur, int idx, vector<int> &v) {
    if (found) return;
    if (idx == v.size()) {
        if (cur==result) found = true;
        return;
    }
    if (cur > result) return;
    dfs(cur + v[idx], idx+1, v);
    dfs(cur * v[idx], idx+1, v);
    dfs(stoll(to_string(cur) + to_string(v[idx])), idx+1, v);
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
    while(getline(cin, s)) {
        char c;
        stringstream ss(s);
        ss >> result >> c;
        vector<int> v; int a;
        while (ss >> a) v.push_back(a);
        found = false;
        dfs(v[0], 1, v);
        if (found) ans += result;
    }
    cout << ans;
    return 0;
}