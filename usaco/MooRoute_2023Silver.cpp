#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

signed main() {
	int N, M; cin >> N >> M;
	vector<int> ans(N, INF); ans[0] = 0;
	vector<vector<tuple<int, int, int>>> adj(N);
	for(int i=0; i<M; i++) {
		int c, r, d, s; cin >> c >> r >> d >> s;
		c--; d--;
		adj[c].emplace_back(r, d, s);
	}
	vector<int> A(N); for(auto &a: A) cin >> a;
	A[0] = 0;
	for(int i=0; i<N; i++) {
		for(auto &[r, d, s]: adj[i]) r-=A[i];
		sort(adj[i].begin(), adj[i].end());
	}
	//BFS remove the edges along the transversal
	queue<tuple<int, int>> q;
	for(auto [r, d, s]: adj[0]) q.emplace(d, s);
	while(!q.empty()) {
		auto [d, s] = q.front(); q.pop();
		ans[d] = min(ans[d], s);
		for(int i=adj[d].size()-1; i>=0; i--) {
			auto [rd, dd, sd] = adj[d][i];
			if (rd < s) break;
			adj[d].pop_back();
			q.emplace(dd, sd);
		}
	}
	for(auto x: ans) cout << (x == INF ? -1 : x) << "\n";
    return 0;
}
