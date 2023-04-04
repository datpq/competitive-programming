#include <bits/stdc++.h>

using namespace std;

signed main() {
	vector<vector<pair<int, int>>> grid(10, vector<pair<int, int>>(10));
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			grid[i][j] = make_pair(i, j);
		}
	}
	int q; cin >> q;
	while (q--) {
		char c, h;
		int l, r;
		cin >> c >> l >> h >> r;
		if (c == 'r') {
			for(int i=l; i<=r; i++) grid.erase(grid.begin() + l);
		} else {
			for(int i=0; i<grid.size(); i++) {
				for(int j=l; j<=r; j++) grid[i].erase(grid[i].begin() + l);
			}
		}
	}
	for(auto r: grid) {
		for(auto c: r) {
			cout << c.first << c.second << " ";
		}
		cout << "\n";
	}
    return 0;
}
