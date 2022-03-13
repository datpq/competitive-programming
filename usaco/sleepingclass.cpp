#include <iostream>
#include <vector>

using namespace std;

int solve() {
	int n; cin >> n; vector<int> v(n);
	int sum = 0; int maxVal = 0;
	for (auto& x : v) {
		cin >> x; sum += x;
		maxVal = max(maxVal, x);
	}
	int maxNumOfGroups = (maxVal == 0 ? 0 : sum / maxVal);
	int groups = maxNumOfGroups;
	for (; groups > 0; groups--) {
		int dest = sum / groups;
		bool divisible = true;
		for (int i = 0; i < n; i++) {
			int subsum = v[i];
			while (subsum < dest && i < n - 1) subsum += v[++i];
			if (subsum != dest) {
				divisible = false; break;
			}
		}
		if (divisible) break;
	}
	return maxVal == 0 ? 0 : n - groups;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
	return 0;
}