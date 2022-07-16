#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

int firstTrue(int lo, int hi, function<bool(int)> f) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main() {
	ifstream ifs("cowdance.in");
	ofstream ofs("cowdance.out");
	int N, T; ifs >> N >> T;
	vector<int> d(N);
	for (auto& x : d) ifs >> x;
	ofs << firstTrue(1, N,
		[&](int x) {
			multiset<int> durations;
			for (int i = 0; i < N; i++) {
				if (i < x) durations.insert(d[i]);
				else {
					if (i == x) {
						auto it = durations.end();
						it--;
						if (*it > T) return false;
					}
					int newDuration = *durations.begin() + d[i];
					if (newDuration > T) return false;
					durations.insert(newDuration);
					durations.erase(durations.begin());
				}
			}
			return true;
		});
	return 0;
}
