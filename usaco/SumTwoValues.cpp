#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, sum; cin >> n >> sum;
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a; v.push_back({ a, i });
	}
	sort(v.begin(), v.end());
	int idx1 = 0; int idx2 = n - 1;
	while (idx1 < idx2 && v[idx1].first + v[idx2].first != sum) {
		if (v[idx1].first + v[idx2].first < sum) idx1++; else idx2--;
	}
	if (idx1 == idx2) cout << "IMPOSSIBLE\n";
	else cout << v[idx1].second << ' ' << v[idx2].second << endl;
	return 0;
}