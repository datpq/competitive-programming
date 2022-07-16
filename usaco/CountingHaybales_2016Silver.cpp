#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream ifs("haybales.in");
	ofstream ofs("haybales.out");
	int N, Q; ifs >> N >> Q;
	vector<int> v(N);
	for (auto& x : v) ifs >> x;
	sort(v.begin(), v.end());
	while (Q--) {
		int A, B; ifs >> A >> B;
		auto itL = lower_bound(v.begin(), v.end(), A);
		auto itR = upper_bound(v.begin(), v.end(), B);
		ofs << itR - itL << "\n";
	}
	return 0;
}
