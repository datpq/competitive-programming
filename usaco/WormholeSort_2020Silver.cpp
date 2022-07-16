//#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int lastTrue(int lo, int hi, function<bool(int)> f) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main() {
	ifstream ifs("wormsort.in");
	ofstream ofs("wormsort.out");

	int N, M; ifs >> N >> M;
	vector<int> P(N);
	vector<vector<pair<int, int>>> adj(N);
	for (auto& x : P) {
		ifs >> x; x--;
	}
	int maxW = 0;
	for (int i = 0; i < M; i++) {
		int a, b, w; ifs >> a >> b >> w;
		a--; b--; maxW = max(maxW, w);
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	int alreadySorted = true;
	for (int i = 0; i < N; i++) {
		if (P[i] != i) {
			alreadySorted = false; break;
		}
	}
	if (alreadySorted) {
		ofs << "-1"; return 0;
	}

	int ans = lastTrue(1, maxW, [&](int w) {
		vector<int> visited(N, -1);
		auto dfs = [&](const auto& self, int node, int group) -> void {
			if (visited[node] != -1) return;
			visited[node] = group;
			for (auto& x : adj[node]) {
				if (x.second >= w) self(self, x.first, group);
			}
		};
		int group = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i] != -1) continue;
			dfs(dfs, i, ++group);
		}
		for (int i = 0; i < N; i++)
			if (visited[i] != visited[P[i]]) return false;
		return true;
	});
	ofs << ans;
	return 0;
}
