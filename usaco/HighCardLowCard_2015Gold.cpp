#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	ifstream ifs("cardgame.in");
	ofstream ofs("cardgame.out");
	int N; ifs >> N;
	vector<int> ve(N), v(N);
	for (int i = 0; i < N; i++) {
		int n; ifs >> n;
		ve[i] = v[i] = n; 
	}
	sort(ve.begin(), ve.end());
	int val = 1, idx = 0;
	vector<int> vb;
	while (val <= 2 * N) {
		if (idx == N || val < ve[idx]) { vb.push_back(val); val++; }
		else if (val == ve[idx]) { val++; idx++; }
		else if (val > ve[idx]) idx++;
	}
	int ans = 0;
	sort(v.begin(), v.begin() + N / 2, greater<int>());//sort in decreasing order
	sort(vb.begin(), vb.end());
	for (int i = 0; i < N / 2; i++) {
		if (vb[vb.size() - 1] > v[i]) {
			ans++;
			vb.pop_back();
		}
	}

	sort(v.begin() + N / 2, v.end());
	sort(vb.begin(), vb.end(), greater<int>());
	for (int i = N/2; i < N; i++) {
		if (vb[vb.size() - 1] < v[i]) {
			ans++;
			vb.pop_back();
		}
	}
	ofs << ans;
	return 0;
}