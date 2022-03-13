#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int main() {
	ifstream ifs("whereami.in");
	ofstream ofs("whereami.out");

	int n; string s; ifs >> n >> s;
	int ans = 0;
	unordered_set<string> mb;
	bool found = true;
	while (found) {
		ans++;
		mb.clear();
		found = false;
		for (int i = 0; i < n + 1 - ans; i++) {
			if (!mb.count(s.substr(i, ans))) mb.insert(s.substr(i, ans));
			else {
				found = true;
				break;
			}
		}
	}

	ofs << ans << endl;
	return 0;
}