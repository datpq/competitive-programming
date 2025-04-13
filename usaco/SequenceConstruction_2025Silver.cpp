#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m, k; cin >> m >> k;
    vector<int> ans;
    int sum = 0;
    for(int i=4; i>=0; i--) {
        if (k >> i & 1) {
            int bits = (1 << i);
            sum += (1 << bits) - 1;
            ans.push_back((1 << bits) - 1);
        }
    }
    if (sum > m) {
        cout << "-1\n"; return;
    }
    sum = m - sum;
    if (sum == 1) {
        bool found = false;
        for(int i=0; i<ans.size(); i++) {
            if (ans[i] == 1) {
                ans[i] = 2;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "-1\n"; return;
        }
    } else {
        int cnt = 0;
        for(int i=30; i>=0; i--) {
            if (sum >> i & 1) {
                cnt++;
                ans.push_back(1 << i);
            }
        }
        if (cnt%2 == 1) {
            bool found = false;
            for(int i=0; i<ans.size(); i++) {
                if (ans[i] %2 == 0) {
                    ans[i] /= 2;
                    ans.push_back(ans[i]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "-1"; return;
            }
        }
    }
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
