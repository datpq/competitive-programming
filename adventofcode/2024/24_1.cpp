#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Assign {
    string left1, left2, oper, right;
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif
    map<string, int> vars;
    string s;
    bool settingup = true;
    vector<Assign> v;
    while(getline(cin, s)) {
        if (s.empty()) {
            settingup = false; continue;
        }
        if (settingup) {
            string key = s.substr(0, 3);
            int val = s[5] - '0';
            vars[key] = val;
        } else {
            Assign a;
            string tmp;
            stringstream ss(s);
            ss >> a.left1 >> a.oper >> a.left2 >> tmp >> a.right;
            v.push_back(a);
        }
    }
    bool found = true;
    while(found) {
        found = false;
        for(auto &a: v) {
            if (vars.count(a.right)) continue;
            if (a.oper == "AND") {
                if (vars.count(a.left1) && vars.count(a.left2)) {
                    vars[a.right] = vars[a.left1] & vars[a.left2];
                    found = true;
                } else if (vars.count(a.left1) && vars[a.left1] == 0) {
                    vars[a.right] = 0;
                    found = true;
                } else if (vars.count(a.left2) && vars[a.left2] == 0) {
                    vars[a.right] = 0;
                    found = true;
                }
            } else if (a.oper == "OR") {
                if (vars.count(a.left1) && vars.count(a.left2)) {
                    vars[a.right] = vars[a.left1] | vars[a.left2];
                    found = true;
                } else if (vars.count(a.left1) && vars[a.left1] == 1) {
                    vars[a.right] = 1;
                    found = true;
                } else if (vars.count(a.left2) && vars[a.left2] == 1) {
                    vars[a.right] = 1;
                    found = true;
                }
            } else if (vars.count(a.left1) && vars.count(a.left2)) {
                vars[a.right] = vars[a.left1] ^ vars[a.left2];
                found = true;
            }
        }
    }
    int ans = 0;
    int cnt = 0;
    for(auto [key, val]: vars) {
        if (key[0] == 'z') {
            ans += (val << cnt++);
        }
    }
    cout << ans;
    return 0;
}