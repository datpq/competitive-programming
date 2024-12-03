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
    map<int, int> rmp;
    for(int i=0; i<LINES; i++) {
        cin >> x[i] >> y[i];
        rmp[y[i]]++;
    }
    int ans = 0;
    for(int i=0; i<LINES; i++) {
        ans += x[i]*rmp[x[i]];
    }
    cout << ans;
    return 0;
}