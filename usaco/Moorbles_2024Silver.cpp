#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> vEven(m), vBest(m);
    for(int i=0; i<m; i++) {
        int mxOdd = 0, mxEven = 0, mnOdd = 1000, mnEven = 1000;
        for(int j=0; j<k; j++) {
            int a; cin >> a;
            if (a%2) {
                mxOdd = max(mxOdd, a);
                mnOdd = min(mnOdd, a);
            } else {
                mxEven = max(mxEven, a);
                mnEven = min(mnEven, a);
            }
        }
        vEven[i] = (mxOdd == 0 ? mnEven : -mxOdd);
        vBest[i] = (mxOdd == 0 ? mnEven : mxEven == 0 ? mnOdd : -min(mxEven, mxOdd));
    }
    vector<int> ssBest(m+1), smBest(m+1); // suffix sum of vBest, suffix max of ssBest
    ssBest[m] = 0, smBest[m] = 0;
    for(int i=m-1; i>=0; i--) {
        ssBest[i] = ssBest[i+1] + vBest[i];
        smBest[i] = max(smBest[i+1], ssBest[i]);
    }
    if (n+ssBest[0]-smBest[0] <= 0) {
        cout << "-1" << "\n";
        return;
    }
    vector<bool> ans;
    for(int i=0; i<m; i++) {
        if (n+vEven[i] > 0 && n+vEven[i]+ssBest[i+1]-smBest[i+1] > 0 ) {
            ans.push_back(true);
            n+=vEven[i];
        } else {
            ans.push_back(false);
            n+=vBest[i];
        }
    }

    cout << (ans[0] ? "Even" : "Odd");
    for(int i=1; i<ans.size(); i++) cout << (ans[i] ? " Even" : " Odd");
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
