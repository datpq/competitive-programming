#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define VAL(x) (int)((x) - 'A' - 12)

using namespace std;

int main() {
	string s; cin >> s;
	vector<int> sums(s.length());
	vector<char[2]> tracks(s.length());

	tracks[0][0] = tracks[0][1] = s[0];
	sums[0] = VAL(s[0]);
	for (int i = 1; i < s.length(); i++) {
		int n = VAL(s[i]);
		if (n > sums[i - 1] + n) tracks[i][0] = s[i];
		else tracks[i][0] = tracks[i - 1][0];
		tracks[i][1] = s[i];
		sums[i] = max(n, sums[i - 1] + n);
	}
	auto itS = max_element(sums.begin(), sums.end());
	auto itT = itS - sums.begin() + tracks.begin();
	cout << *itS << endl;
	cout << (*itT)[0] << (*itT)[1] << endl;

	return 0;
}
