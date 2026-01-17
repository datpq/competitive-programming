#include <bits/stdc++.h>

using namespace std;

map<string, int> getMoos(string &s) {
    map<string, int> mp;
    int n = s.size();
    for(int i=0; i+2<n; i++) {
        if (s[i] != s[i+1] && s[i+1] == s[i+2]) {
            mp[s.substr(i, 3)]++;
        }
    }
    return mp;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, f; cin >> n >> f;
    string s; cin >> s;
    auto mp = getMoos(s);
    set<string> ans;
    for(auto [str, cnt]: mp) {
        if (cnt >= f) ans.insert(str);
    }
    for(int i=0; i<n; i++) {
        for(char k = 'a'; k <= 'z'; k++) {
            if (s[i] == k) continue;
            int st = max(0, i-2);
            int en = min(n-1, i+2);
            string oldstr = s.substr(st, en - st + 1);
            char old = s[i];
            s[i] = k;
            string newstr = s.substr(st, en - st + 1);
            auto oldmp = getMoos(oldstr);
            auto newmp = getMoos(newstr);
            for(auto [str, cnt]: newmp) {
                if (newmp[str] - oldmp[str] + mp[str] >= f) {
                    ans.insert(str);
                }
            }
            s[i] = old;
        }
    }
    cout << ans.size() << "\n";
    for(auto x: ans) cout << x << "\n";
    return 0;
}
