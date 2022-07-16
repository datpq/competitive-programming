#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

ifstream ifs("fenceplan.in");
ofstream ofs("fenceplan.out");

int main() {
	int n, m; ifs >> n >> m;
	vector<pair<int, int>> v(n+1);
	for (int i = 1; i <= n; i++) ifs >> v[i].first >> v[i].second;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; ifs >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}

	vector<bool> visited(n + 1, false);
	int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
	auto dfs = [&](const auto& self, int node) -> void {
		if (visited[node]) return;
		visited[node] = true;
		minX = min(v[node].first, minX);
		minY = min(v[node].second, minY);
		maxX = max(v[node].first, maxX);
		maxY = max(v[node].second, maxY);
		for (auto& x : adj[node]) self(self, x);
	};

	int ans = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
		dfs(dfs, i);
		ans = min(ans, 2*((maxX-minX)+(maxY-minY)));
	}

	ofs << ans;
	return 0;
}
