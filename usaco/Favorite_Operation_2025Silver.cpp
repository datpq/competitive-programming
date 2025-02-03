#include <bits/stdc++.h>
#define int long long

using namespace std;

int solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i]; v[i] %= m;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) v.push_back(v[i]+m);

    vector<int> ps(2*n);
    for(int i=0; i<2*n; i++) {
        ps[i] = (i==0 ? 0 : ps[i-1]) + v[i];
    }
     int best = ps[n-1];
    for(int i=0; i<n; i++) {
        int x = v[i];
        int idx = upper_bound(v.begin(), v.end(), x+m/2) - v.begin() - 1;
        int ans1 = ps[idx] - (i==0 ? 0 : ps[i-1]) - (idx-i+1)*x;
        int ans2 = (m+x)*(i+n-1-idx) - (ps[i+n-1] - ps[idx]);
        best = min(best, ans1 + ans2);
    }
    return best;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
    return 0;
}