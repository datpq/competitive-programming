#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

vector<int> fib = {1, 2};

signed main() {
    while(fib.back()<54e9) {
        int fibNext = fib[fib.size()-2]+fib[fib.size()-1];
        // cout << fibNext << " ";
        fib.pb(fibNext);
    }
    // cout << "\n";
    bool subTaksA = true, subTaskB = false, subTaskC = false, subTaskD = false;
    if (subTaksA) {
        // for (int cnt=0; cnt<11; cnt++) {
        int n; cin >> n;
        vector<int> ans;
        while(n) {
            for(int i=fib.size()-1; i>=0; i--) {
                if (fib[i] <= n) {
                    ans.pb(fib[i]);
                    n-=fib[i];
                    break;
                }
            }
        }
        for(auto x: ans) cout << x << " "; cout << "\n";
        // }
    }
    if (subTaskB) {
        for(int i=fib.size()-1; i>=0; i--) {
            if (fib[i] < 1e6) {
                cout << "subTaskB: " << fib[i] << "\n";
                break;
            }
        }
    }
    if (subTaskC) {
         int ans = 0;
         for(int i=0; i<fib.size(); i++) {
            for(int j=i+2; j<fib.size(); j++) {
                for(int k=j+2; k<fib.size(); k++) {
                    if (fib[i]+fib[j]+fib[k] < 53316291173) ans++;
                }
            }
         }
         cout << "subTaskC: " << ans << "\n";
    }
    if (subTaskD) {
        //701408733     1e9     1134903170  1836311903  2971215073  4807526976  5000000000
        //fib0          1e9     fib1        fib2        fib3        fib4        5e9
        // fib1 --> fib2 - 1 (fib0)
        // fib2 --> fib2 + fib0 - 1 (fib0)
        // fib3 --> fib3 + fib0 - 1 (fib0)
        // fib3 + fib0 --> fib3 + fib1 - 1 (0)
        // fib3 + fib1 --> fib3 + fib2 - 1 = fib4 - 1 (fib2-fib1 = fib0)
        // fib4 --> 5e9 (5e9-fib4+1)
        //4*fib0 + 5e9-fib4+1 = 2,998,107,957
        cout << "subTaskD: " << std::fixed << std::setprecision(0) << 4LL*701408733 + 5e9-4807526976+1 << "\n";
    }
    return 0;
}
