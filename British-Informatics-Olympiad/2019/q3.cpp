#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool validate(string s) {
	for (int i = 0; i < s.length(); i++) {
		for (int j = i + 1; j < s.length(); j++) {
			if (s[i] < s[j]) {
				for (int k = j + 1; k < s.length(); k++) {
					if (s[j] < s[k]) return false;
				}
			}
		}
	}
	return true;
}

bool preValidate(string s, vector<char> &suffix) {
	if (s.length() == 0) return true;
	char min_prefix = s[0];
	for (int i = 0; i < s.length(); i++) {
		suffix.erase(find(suffix.begin(), suffix.end(), s[i]));

		if (s[i] < min_prefix) min_prefix = s[i];
		else if (s[i] > min_prefix && suffix.size() > 0) {
			auto it = max_element(suffix.begin(), suffix.end());
			if (*it > s[i]) return false;
		}
	}
	return true;
}

// it's a dumb solution got 15/24 marks
int main() {
	//while (true) {
	int l; string p; cin >> l >> p;
	int ans = 0;
	vector<char> charsExceptP;
	for (int i = 0; i < l; i++) {
		charsExceptP.push_back('A' + i);
	}

	if (preValidate(p, charsExceptP)) {
		do {
			string s(charsExceptP.begin(), charsExceptP.end());
			if (validate(p + s)) {
				//cout << p << s << endl;
				ans++;
			}
		} while (next_permutation(charsExceptP.begin(), charsExceptP.end()));
	}
	cout << ans << endl;
	//}
	return 0;
}