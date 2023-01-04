#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<long long> hb, sumSubTree;
vector<tuple<int, int, long long>> ans;

void dfs_calculate_subtree(int node, int prev) {
    sumSubTree[node] = hb[node];
	for (auto child : adj[node]) {
		if (child == prev) continue;
		dfs_calculate_subtree(child, node);
        sumSubTree[node] += sumSubTree[child];
	}
}

void dfs(int node, int prev) {
	for (auto child : adj[node]) {
		if (child == prev) continue;
        if (sumSubTree[child] >= 0) dfs(child, node);
        if (sumSubTree[child] > 0) ans.push_back({child, node, sumSubTree[child]});
	}
	for (auto child : adj[node]) {
		if (child == prev) continue;
        if (sumSubTree[child] < 0) {
            ans.push_back({node, child, -1 * sumSubTree[child]});
            dfs(child, node);
        }
	}
}

int main() {
	int N; cin >> N;
	hb = vector<long long>(N);
    sumSubTree = vector<long long>(N, 0);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> hb[i];
		sum += hb[i];
	}
    for(int i=0; i<N; i++) hb[i] -= (sum / N);
	adj = vector<vector<int>>(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b); adj[b].push_back(a);
	}

	dfs_calculate_subtree(0, -1);
    dfs(0, -1);

    cout << ans.size() << "\n";
	for (auto [src, dest, val] : ans) cout << src + 1 << " " << dest + 1 << " " << val << "\n";

	return 0;
}
