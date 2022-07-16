#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

ifstream ifs("perimeter.in");
ofstream ofs("perimeter.out");

int computePerimeter(vector<vector<char>>&v, vector<pair<int, int>>& blob) {
	int ans = 0;
	for (auto& x : blob) {
		if (x.first == 0 || v[x.first - 1][x.second] == '.') ans++;
		if (x.first == v.size() - 1 || v[x.first + 1][x.second] == '.') ans++;
		if (x.second == 0 || v[x.first][x.second - 1] == '.') ans++;
		if (x.second == v.size() - 1 || v[x.first][x.second + 1] == '.') ans++;
	}
	return ans;
}

int main() {
	int n; ifs >> n;
	vector<vector<char>> v(n, vector<char>(n));
	vector<pair<int, int>> ices;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		ifs >> v[i][j];
		if (v[i][j] == '#') ices.push_back({ i, j });
	}
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	auto dfs = [&](const auto& self, int x, int y, vector<pair<int, int>> &blob) -> void {
		if (x < 0 || x >= n || y < 0 || y >= n) return;
		if (v[x][y] == '.') return;
		if (visited[x][y]) return;
		visited[x][y] = true;
		blob.push_back({ x, y });
		self(self, x - 1, y, blob);
		self(self, x + 1, y, blob);
		self(self, x, y - 1, blob);
		self(self, x, y + 1, blob);
	};

	int ansArea = 0, ansPerimeter = 0;
	for(auto& it: ices) {
		if (visited[it.first][it.second]) continue;
		vector<pair<int, int>> blob;
		dfs(dfs, it.first, it.second, blob);
		if (ansArea < blob.size()) {
			ansArea = blob.size();
			ansPerimeter = computePerimeter(v, blob);
		}
		else if (ansArea == blob.size()) {
			ansPerimeter = min(ansPerimeter, computePerimeter(v, blob));
		}
	}

	ofs << ansArea << " " << ansPerimeter;

	return 0;
}
