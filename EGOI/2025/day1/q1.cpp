#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n; cin >> t >> n;
    vector<bool> vis(t, false);
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    int l = 0, r = n - 1;
    for(int i=0; i<n; i++) {
        if (vis[v[i]]) {
            l = i;
            break;
        } else {
            vis[v[i]] = true;
        }
    }
    int ans = l + n - r - 1;
    int curL = l, curR = r;
    while(curL >= 0) {
        while(curR >= curL && !vis[v[curR]]) {
            vis[v[curR]] = true;
            curR--;
        }
        if (ans < curL + n - curR - 1) {
            ans = curL + n - curR - 1;
            l = curL; r = curR;
        }
        curL--;
        if (curL >= 0) vis[v[curL]] = false;
    }
    cout << l << ' ' << r << '\n';
    return 0;
}