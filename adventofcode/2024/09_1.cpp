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

    int ans = 0;
    string s; cin >> s;
    int n = s.length();
    int l=0, r=2*((n-1)/2);
    int startIdx = 0, endIdx = 0;
    while(l<=r) {
        if (l%2 == 0) {
            endIdx = startIdx + (s[l] - '0');
            ans += l/2*(startIdx + endIdx - 1)*(endIdx - startIdx)/2;
            startIdx = endIdx;
            l++;
        } else {
            endIdx = startIdx + (min(s[l], s[r]) - '0');
            ans += r/2*(startIdx + endIdx - 1)*(endIdx - startIdx)/2;
            startIdx = endIdx;
            if (s[l] < s[r]) {
                s[r] -= (s[l] - '0');
                l++;
            } else if (s[l] > s[r]) {
                s[l] -= (s[r] - '0');
                r-=2;
            } else {
                l++; r-=2;
            }
        }
    }
    cout << ans;
    return 0;
}