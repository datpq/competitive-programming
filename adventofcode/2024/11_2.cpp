#include <bits/stdc++.h>
#define int long long

using namespace std;

map<pair<int, int>, int> dp;
int compute(int n, int step) {
    if (dp.count({n, step})) return dp[{n, step}];
    if (step==0) return 1;
    int ans = 0;
    if (n == 0) return compute(1, step - 1);
    else {
        string str = to_string(n);
        if (str.length() % 2 == 0) {
            int left = stoll(str.substr(0, str.length()/2));
            int right = stoll(str.substr(str.length()/2));
            ans += compute(left, step-1);
            ans += compute(right, step-1);
        } else {
            ans = compute(n*2024, step-1);
        }
    }
    dp[{n, step}] = ans;
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    const int N = 75;
    int val;
    int ans = 0;
    while(cin >> val) ans += compute(val, N);
    cout << ans;
    return 0;
}