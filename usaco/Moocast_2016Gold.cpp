#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

ifstream ifs("moocast.in");
ofstream ofs("moocast.out");

int main() {
	int n; ifs >> n;
	vector<pair<int, int>> nodes(n);
	for (auto& [x, y] : nodes) ifs >> x >> y;
    vector<tuple<int, int, int>> distances;
	for (int i = 0; i < n - 1; i++) {
        auto [x1, y1] = nodes[i];
		for (int j = i + 1; j < n; j++) {
            auto [x2, y2] = nodes[j];
			int d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
            distances.push_back({d, i, j});
		}
	}
    sort(distances.begin(), distances.end());
    DSU dsu(n);
    int ans = 0;
    for(auto [d, x, y]: distances) {
        dsu.unite(x, y);
        if (dsu.size(x) == n) {
            ans = d;
            break;
        }
    }
    ofs << ans;
	return 0;
}
