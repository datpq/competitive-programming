#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, limit, quantity;
vector<int> prix, prefix;

pair<int, int> check(int delta) {
    int qtyBelowLimit = upper_bound(prix.begin(), prix.end(), delta) - prix.begin();
    int qtyAboveLimit = prix.end() - lower_bound(prix.begin(), prix.end(), 2*limit-delta);
    int diffCost = prefix[qtyBelowLimit] + 2*limit*qtyAboveLimit - (prefix[n] - prefix[n-qtyAboveLimit]);
    return {qtyBelowLimit + qtyAboveLimit, diffCost};
}

int lastTrue(int lo, int hi) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (check(mid).first <= quantity) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int solve() {
    cin >> limit >> quantity;
    int targetLimit = lastTrue(-1e9, limit);
    auto targetInfo = check(targetLimit);
    int ans = targetInfo.second + (targetLimit+1)*(quantity-targetInfo.first);
    return ans;
}

signed main() {
    int q; cin >> n >> q;
    prix = vector<int>(n);
    for(auto &x: prix) cin >> x;
    sort(prix.begin(), prix.end());
    prefix = vector<int>(n+1); prefix[0] = 0;
    for(int i=0; i<n; i++) prefix[i+1]=prefix[i]+prix[i];

    while(q--) cout << solve() << "\n";

    return 0;
}
