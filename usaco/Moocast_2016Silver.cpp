#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory.h>

using namespace std;

ifstream ifs("moocast.in");
ofstream ofs("moocast.out");

struct talkie { int x, y, p; };

int main() {
	int n; ifs >> n;
	vector<talkie> v(n);
	for (auto& it : v) ifs >> it.x >> it.y >> it.p;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int z = (v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y);
			if (z <= v[i].p * v[i].p) adj[i].push_back(j);
			if (z <= v[j].p * v[j].p) adj[j].push_back(i);
		}
	}

	bool visited[200];
	int ans = 0;
	auto dfs = [&](const auto& self, int node) -> void {
		if (visited[node]) return;
		visited[node] = true; ans++;
		for (auto& x : adj[node]) self(self, x);
	};

	int best = 0;
	for (int i = 0; i < n; i++) {
		memset(visited, false, n * sizeof(bool));
		ans = 0;
		dfs(dfs, i);
		best = max(best, ans);
	}

	ofs << best;
	return 0;
}
