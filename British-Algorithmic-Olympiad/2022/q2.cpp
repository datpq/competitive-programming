#include <bits/stdc++.h>

using namespace std;

signed main() {
    bool subTaskA = true, subTaskB = true, subTaskC = true;
    if (subTaskA) {
        int p; cin >> p;
        int x, y; cin >> x >> y;
        int ans = 0;
        for(int i=0; i<=p; i++) {
            for(int j=0; j<=p; j++) {
                if (i==x && j==y) continue;
                if (gcd(i-x, j-y) == 1) ans++;
            }
        }
        cout << ans << "\n";
    }
    if (subTaskB) {
        cout << (gcd(987654321, 123456789) == 1 ? "Yes" : "No") << "\n";//gcd = 9
    }
    if (subTaskC) {
        int p = 999, x = 1, y = 1;
        int cntX0 = 0, cntXP = 0, cntY0 = 0, cntYP = 0;
        for(int i=0; i<=p; i++) {
            if (gcd(i-x, 0-y) == 1) cntX0++;
            if (gcd(i-x, p-y) == 1) cntXP++;
            if (gcd(0-x, i-y) == 1) cntY0++;
            if (gcd(p-x, i-y) == 1) cntYP++;
        }
        // cout << cntX0 << " " << cntXP << " " << cntY0 << " " << cntYP << "\n";
        int ans = 0;
        ans += cntX0*(cntX0-1)/2;
        ans += cntXP*(cntXP-1)/2;
        ans += cntY0*(cntY0-1)/2;
        ans += cntYP*(cntYP-1)/2;
        ans++; // the triangle (0,0), (2,0), (0,2)
        cout << ans << "\n";
    }
    return 0;
}
