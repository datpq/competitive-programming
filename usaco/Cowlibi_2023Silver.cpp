#include <bits/stdc++.h>
#define int long long

using namespace std;

bool checkAlibi(tuple<int, int, int> a, tuple<int, int, int> b) {
	auto [ta, xa, ya] = a;
	auto [tb, xb, yb] = b;
	return (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb) > (ta-tb)*(ta-tb);
}

signed main() {
    int G, N; cin >> G >> N;
	vector<tuple<int, int, int>> g(G), C(N);
	for(auto &[t, x, y]: g) cin >> x >> y >> t;
	sort(g.begin(), g.end());
	for(auto &[t, x, y]: C) cin >> x >> y >> t;
	int ans = 0;
	for(auto &cow: C) {
		auto it = lower_bound(g.begin(), g.end(), cow);
		bool isInnocent = false;
		if (it != g.end()) isInnocent = checkAlibi(cow, *it);
		if (it != g.begin() && !isInnocent) {
			it--;
			isInnocent = checkAlibi(cow, *it);
		}
		if (isInnocent) ans++;
	}
	cout << ans;
    return 0;
}
