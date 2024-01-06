#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(k), b(k);
    for(auto &x: a) cin >> x, x--;
    for(auto &x: b) cin >> x, x--;
    map<int, int> mpa, mp;
    vector<bool> vis(n, false);
    for(int i=0; i<k; i++) {
        mpa[a[i]] = i;
        vis[a[i]] = true;
    }
    set<int> remainderA;
    for(int i=0; i<n; i++) if (!vis[i]) remainderA.insert(i);
    vis = vector<bool>(n, false);
    for(int i=0; i<k; i++) {
        int num = b[i];
        vis[num] = true;
        if (mpa.count(num)) mp[num] = (mpa[num]>=i ? mpa[num]-i : mpa[num]-i+k);
    }
    int ans2 = 0;
    for(int i=0; i<n; i++) if (!vis[i] && remainderA.count(i)) ans2++;

    int ans1 = 0;
    map<int, int> mpDiff;
    for(auto [key, val]: mp) {
        mpDiff[val]++;
        ans1 = max(ans1, mpDiff[val]);
    }
    reverse(b.begin(), b.end());
    mp.clear();
    for(int i=0; i<k; i++) {
        int num = b[i];
        if (mpa.count(num)) mp[num] = (mpa[num]>=i ? mpa[num]-i : mpa[num]-i+k);
    }
    mpDiff.clear();
    for(auto [key, val]: mp) {
        mpDiff[val]++;
        ans1 = max(ans1, mpDiff[val]);
    }
    int ans = ans1 + ans2;
    cout << ans << "\n";
    return 0;
}