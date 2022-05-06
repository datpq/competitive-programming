#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, int>> v;
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		vector<pair<int, int>> vi;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				char c; cin >> c;
				if (c == '1') {
					if (i == 0) v.push_back({ j, k });
					else vi.push_back({ j, k });
				}
			}
		}
		if (i == 0) continue;
		int dx = v[0].first - vi[0].first;
		int dy = v[0].second - vi[0].second;
		bool samePattern = true;
		for (int j = 1; j < v.size(); j++) {
			if (dx + vi[j].first != v[j].first || dy + vi[j].second != v[j].second) {
				samePattern = false; break;
			}
		}
		if (samePattern) ans++;
	}
	cout << ans * v.size();
	return 0;
}