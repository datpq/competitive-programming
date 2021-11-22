#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>;

using namespace std;

unordered_map<string, bool> calculated;

char min_char(string s) {
	char ans = s[0];
	for (auto c : s) {
		if (c < ans) ans = c;
	}
	return ans;
}

char max_char(string s) {
	char ans = s[0];
	for (auto c : s) {
		if (c > ans) ans = c;
	}
	return ans;
}

bool solve(string s) {
	bool ans = false;
	if (s.length() == 1) {
		ans = true;
	}
	else if (calculated.count(s) > 0) {
		ans = calculated[s];
	}
	else {
		for (int i = 1; i < s.length(); i++) {
			string sLeft = s.substr(0, i);
			string sRight = s.substr(i, s.length() - i);
			if (min_char(sLeft) > max_char(sRight)) {
				reverse(sLeft.begin(), sLeft.end());
				reverse(sRight.begin(), sRight.end());
				ans = solve(sLeft) && solve(sRight);
				if (ans) break;
			}
		}
	}
	calculated.insert({ s, ans });
	return ans;
}

int main() {
	calculated.clear();

	// 1(a)
	//while (true) {
		string s1, s2; cin >> s1 >> s2;
		cout << (solve(s1) ? "YES" : "NO") << endl;
		cout << (solve(s2) ? "YES" : "NO") << endl;
		cout << (solve(s1 + s2) ? "YES" : "NO") << endl;
	//}

	// 1(b)
	//string s = "ABCD";
	//do {
	//	if (solve(s)) {
	//		cout << s << endl;
	//	}
	//} while (next_permutation(s.begin(), s.end()));
	return 0;
}