#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

vector<string> patterns;

vector<int> dp;
int compute(string &s, int idx) {
    if (dp[idx]) return dp[idx];
    int ans = 0;
    for(auto &pat: patterns) {
        if (s.rfind(pat, idx) == idx) {
            ans += compute(s, idx + pat.size());
        }
    }
    dp[idx] = ans;
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
    getline(cin, s);
    stringstream ss(s);
    while (ss >> s) {
        if (s.back() == ',') s=s.substr(0, s.length() - 1);
        patterns.push_back(s);
    }
    
    int ans = 0;
    while(getline(cin, s)) {
        if (s.empty()) continue;
        dp = vector<int>(s.length() + 1, 0);
        dp[s.length()] = 1;
        ans += compute(s, 0);
    }
    cout << ans;
    return 0;
}