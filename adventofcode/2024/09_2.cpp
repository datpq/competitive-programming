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
    string input = s;
    int n = s.length();
    int startIdx = 0, endIdx = 0;
    for(int l=0; l<n; l++) {
        if (l%2==0) {
            if (s[l] == '0') {
                startIdx += (input[l] - '0');
            } else {
                endIdx = startIdx + (s[l] - '0');
                ans += l/2*(startIdx + endIdx - 1)*(endIdx - startIdx)/2;
                startIdx = endIdx;
            }
        } else {
            bool found = false;
            for(int r=2*((n-1)/2); r>=l; r-=2) {
                if (s[r] > '0' && s[r] <= s[l]) {
                    endIdx = startIdx + (s[r] - '0');
                    ans += r/2*(startIdx + endIdx - 1)*(endIdx - startIdx)/2;
                    startIdx = endIdx;
                    s[l] -= (s[r] - '0');
                    s[r] = '0';
                    if (s[l] != '0') l--;//dont move
                    found = true;
                    break;
                }
            }
            if (!found) {
                startIdx += (s[l] - '0');
            }
        }
    }
    cout << ans;
    return 0;
}