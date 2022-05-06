#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;

int main() {
	ifstream ifs("shell.in");
	ofstream ofs("shell.out");
	int n; ifs >> n;
	int a[MAX_N], b[MAX_N], g[MAX_N];
	for (int i = 0; i < n; i++) {
		ifs >> a[i] >> b[i] >> g[i];
		a[i]--;  b[i]--; g[i]--;
	}

	int best = 0;
	for (int pebble = 0; pebble < 3; pebble++) {
		int p[3] = { 0, 1, 2 };
		int currentPebble = pebble;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			currentPebble = (currentPebble == a[i] ? b[i] : currentPebble == b[i] ? a[i] : currentPebble);
			swap(p[a[i]], p[b[i]]);
			if (currentPebble == g[i]) ans++;
		}
		best = max(best, ans);
	}
	ofs << best << endl;
	return 0;
}