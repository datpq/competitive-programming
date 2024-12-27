#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int sum = 0;
    int elsie = 0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        sum += v[i];
        if (i<n/2-1) elsie+=v[i];
    }

    int ans = elsie;
    for(int i=0; i<n/2-1; i++) {
        elsie -= v[n/2-1-i-1];
        elsie += v[n-i-1];
        ans = max(ans, elsie);
    }
    cout << sum - ans << " " << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}