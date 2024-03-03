#include <bits/stdc++.h>

using namespace std;

ifstream ifs("diamond.in");
ofstream ofs("diamond.out");

int solve() {
    int n, k; ifs >> n >> k;
    vector<int> v(n);
    for(auto &x: v) ifs >> x;
    sort(v.begin(), v.end());
    int left = 0;
    int right = 0;
    int ans = right - left + 1;
    while (right < n) {
        if (v[right]-v[left] <= k) {
            ans = max(ans, right - left + 1);
            right++;
        } else {
            left++;
        }
    }
    return ans;
}

signed main() {
    ofs << solve();
    return 0;
}