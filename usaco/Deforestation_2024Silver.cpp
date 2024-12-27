#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, k; cin >> n >> k;
    vector<int> trees(n);
    vector<tuple<int, int, int, int>> events;
    for(int i=0; i<n; i++) {
        cin >> trees[i];
        events.emplace_back(trees[i], 0, 0, 0);
    }
    sort(trees.begin(), trees.end());
    for(int i=0; i<k; i++) {
        int l, r, t; cin >> l >> r >> t;
        int rangecount = upper_bound(trees.begin(), trees.end(), r) - lower_bound(trees.begin(), trees.end(), l);
        events.emplace_back(l, -1, r, rangecount-t);
    }
    sort(events.begin(), events.end());
    priority_queue<pair<int, int>> pq;
    int ans = 0;
    for(auto &[l, tp, r, limit]: events) {
        if (tp == -1) {
            pq.emplace(-(limit+ans), r);//increasing order
        } else {
            while (!pq.empty() && pq.top().second < l) {
                pq.pop();
            }
            if (pq.empty() || abs(pq.top().first) > ans) {
                ans++;
            }
        }
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