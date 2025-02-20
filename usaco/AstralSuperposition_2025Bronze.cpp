#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];
    vector<vector<bool>> star(n, vector<bool>(n, false));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (grid[i][j] == 'B') {
                star[i][j] = true;
                if (i<b || j<a) return -1;
                star[i-b][j-a] = true;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (grid[i][j] == 'W') {
                if (star[i][j]) return -1;
            } else if (grid[i][j] == 'G') {
                if (star[i][j]) continue;
                if (i>=b && j>=a && star[i-b][j-a]) continue;
                star[i][j] = true;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += accumulate(star[i].begin(), star[i].end(), 0);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
    return 0;
}
