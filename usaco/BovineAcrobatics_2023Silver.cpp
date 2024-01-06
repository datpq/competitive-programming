#include <bits/stdc++.h>
#define int long long

using namespace std;

using Node = pair<int, int>;
const int INF = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int ans = 0;
    vector<Node>v(n);
    for(auto &x: v) cin >> x.first >> x.second;
    sort(v.begin(), v.end(), greater<Node>());
    deque<Node> towers = {{2*INF, m}};
    for(auto [w, a]: v) {
        int allAdd = 0;
        while (towers.size() && a && w+k<=towers.front().first) {
            int add = min(a, towers[0].second);
            ans += add;
            towers[0].second -= add;
            a -= add;
            if (!towers[0].second) towers.pop_front();
            allAdd += add;
        }
        if (allAdd) towers.push_back({w, allAdd});
    }
    cout << ans << "\n";
    return 0;
}