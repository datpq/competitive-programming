#include <fstream>

using namespace std;

int main() {
	ifstream ifs("pails.in");
	ofstream ofs("pails.out");
	int x, y, m; ifs >> x >> y >> m;
	int ans = m;
	for (int i = 0; i <= (m / x); i++) {
		int remainder = m - (i * x);
		ans = min(ans, remainder % y);
		if (ans == 0) break;
	}
	ofs << (m - ans) << endl;
}