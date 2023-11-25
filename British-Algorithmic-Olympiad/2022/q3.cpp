#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    for(int x=0; x*x<n; x++) {
        int y = sqrt(n-(x*x));
        if (y*y+x*x == n) y--;
        ans+=y+1;
    }
    cout << "C: " << ans << "\n";
    cout << "D: " << 1 << "\n";
    return 0;
}
