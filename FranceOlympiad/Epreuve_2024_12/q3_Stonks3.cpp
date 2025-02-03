#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    while(n--) {
        int p; cin >> p;
        if (!pq.empty() && pq.top() < p) {
            ans += p - pq.top();
            pq.pop();
            pq.push(p);
        }
        pq.push(p);
    }
    cout << ans;
    return 0;
}