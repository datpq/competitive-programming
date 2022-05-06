#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream ifs("gymnastics.in");
	ofstream ofs("gymnastics.out");
	int K, N; ifs >> K >> N;
	vector<vector<int>> v;
	for (int i = 0; i < K; i++) {
		vector<int> r(N);
		for (int j = 0; j < N; j++) {
			int a; ifs >> a; r[a-1] = j;
		}
		v.push_back(r);
	}
	int ans = 0;
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			bool consistent = true;
			for (int p = 1; p < K; p++) {
				if ((v[0][i] - v[0][j]) * (v[p][i] - v[p][j]) < 0) {
					consistent = false;
					break;
				}
			}
			if (consistent) ans++;
		}
	}
	ofs << ans << endl;
	return 0;
}

