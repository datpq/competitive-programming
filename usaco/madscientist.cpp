#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream ifs("breedflip.in");
	ofstream ofs("breedflip.out");
	int n; string a, b; ifs >> n >> a >> b;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			ans++;
			while (i < n-1 && a[i + 1] != b[i + 1]) i++;
		}
	}
	ofs << ans << endl;
	return 0;
}
