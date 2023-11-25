#include <bits/stdc++.h>

using namespace std;

string s;
int ans1 = 0, ans2 = 0;
void search(int idx, vector<int> &path) {
    // for(auto x: path) cout << (char)('A' + x);
    // if (!path.empty()) cout << endl;
    for(int i=idx; i<s.length(); i++) {
        if (!path.empty() && s[i] <= s[path.back()]) continue;
        path.push_back(i);
        ans1++; ans2 = max(ans2, (int)path.size());
        search(i+1, path);
        path.pop_back();
    }
}

signed main() {
    int t; cin >> t;
    while (t--) {
        cin >> s;
        vector<int> path; ans1 = ans2 = 0;
        search(0, path);
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
