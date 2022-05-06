#include <iostream>
#include<vector>

using namespace std;

const long long INF = 1e18;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  int n, p;
    cin >> n >> p;
    vector<vector<in cin >> T;
  for (int tc = 1; tc <= T; tc++) {
   t>> a(n, vector<int>(p));
    vector<int> mx(n), mn(n);
    vector<vector<long long>> dp(n, vector<long long>(p));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p; j++) {
        cin >> a[i][j];
      }
      mx[i] = *max_element(a[i].begin(), a[i].end());
      mn[i] = *min_element(a[i].begin(), a[i].end());
    }
    for (int j = 0; j < p; j++) {
      dp[0][j] = 2LL*mx[0] - a[0][jor (int j = 0; j < p; j++) {
        dp[i][j] = IN];
    }
    for (int i = 1; i < n; i++) {
      fF;
        for (int k = 0; k < p; k++) {
          dp[i][j] = min({
              dp[i][j],
              dp[i-1][k]+abs(mn[i]-a[i-1][k]) + (mx[i]-mn[i])+abs(a[i][j]-mx[i]),
              dp[i-1][k]+abs(mx[i]-a[i-1][k]) + (mx[i]-mn[i])+abs(a[i][j]-mn[i]),
              });
        }
      }
    }
    cout << "Case #" << tc << ": " << *min_element(dp[n-1].begin(), dp[n-1].end()) << '\n';
  }
}
