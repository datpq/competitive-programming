#include <bits/stdc++.h>

using namespace std;
using Node = pair<int, int>;

string s;
int ans2 = 0;
map<Node, int> dp;
int search(int len, int curIdx) {
    // memoization to reduce the execution time from 0.7sec to 0.2sec
    if (dp.count({len, curIdx})) return dp[{len, curIdx}];
    int ans = (len?1:0); ans2 = max(ans2, len);
    for(int i=curIdx+1; i<s.length(); i++) {
        if (s[i] <= s[curIdx]) continue;
        ans += search(len+1, i);
    }
    dp[{len, curIdx}] = ans;
    return ans;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        cin >> s;
        ans2 = 0;
        int ans = search(0, -1);
        cout << ans << " " << ans2 << endl;
    }
    return 0;
}
/* test cases
6
abced
gjhadeibcfk
hndemgijcbpoafkl
stmcahirdlnkojebpgfq
ivhsowebftdqarjxnlpugkzcym
abcdefghijklmnopqrstuvwxzy

23 4
87 5
280 7
779 8
1706 7
50331647 25
*/
