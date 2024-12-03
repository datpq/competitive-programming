#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif
    const int LINES=1000;

    vector<int> x(LINES), y(LINES);
    for(int i=0; i<LINES; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int ans = 0;
    for(int i=0; i<LINES; i++) {
        ans += abs(x[i]-y[i]);
    }
    cout << ans;
    return 0;
}