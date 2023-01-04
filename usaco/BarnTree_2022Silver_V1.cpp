#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<long long> hayBales, sumSubTree;
vector<tuple<int, int, long long>> ansUp, ansDown;

void dfs_calculate_subtree(int node, int prev) {
    sumSubTree[node] = hayBales[node];
	for (auto child : adj[node]) {
		if (child == prev) continue;
		dfs_calculate_subtree(child, node);
        sumSubTree[node] += sumSubTree[child];
	}
}

void dfsMoveUp(int node, int prev) {
	for (auto child : adj[node]) {
		if (child == prev) continue;
		dfsMoveUp(child, node);
        if (sumSubTree[child] > 0) {
            ansUp.push_back({child, node, sumSubTree[child]});
            sumSubTree[child] = 0;
        }
	}
}

void dfsMoveDown(int node, int prev) {
	for (auto child : adj[node]) {
		if (child == prev) continue;
		dfsMoveDown(child, node);
        if (sumSubTree[child] < 0) {
            ansDown.push_back({node, child, -1*sumSubTree[child]});
            sumSubTree[child] = 0;
        }
	}
}

int main() {
	int N; cin >> N;
	hayBales = vector<long long>(N);
    sumSubTree = vector<long long>(N, 0);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> hayBales[i];
		sum += hayBales[i];
	}
    for(int i=0; i<N; i++) hayBales[i] -= (sum / N);
	adj = vector<vector<int>>(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b); adj[b].push_back(a);
	}

	dfs_calculate_subtree(0, -1);
    dfsMoveUp(0, -1);
    dfsMoveDown(0, -1);

	cout << ansUp.size() + ansDown.size() << "\n";
	for (auto [src, dest, val] : ansUp) cout << src + 1 << " " << dest + 1 << " " << val << "\n";
    reverse(ansDown.begin(), ansDown.end());
	for (auto [src, dest, val] : ansDown) cout << src + 1 << " " << dest + 1 << " " << val << "\n";

	return 0;
}
