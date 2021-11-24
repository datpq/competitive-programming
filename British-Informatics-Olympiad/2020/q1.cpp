#include <iostream>
#include <unordered_set>

using namespace std;

string integer_to_Roman(int n) {
	string str_romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string result = "";
	for (int i = 0; i < 13; i++) {
		while (n - values[i] >= 0) {
			result += str_romans[i];
			n -= values[i];
		}
	}
	return result;
}

string solve(string s) {
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		int diffIdx = i + 1; // find first character different from s[i]
		while (diffIdx < s.length() && s[diffIdx] == s[i]) diffIdx++;
		if (diffIdx - i < 4) {
			string iStr(diffIdx - i, 'I');
			ans += (iStr + s[i]);
		}
		else if (diffIdx - i == 4) {
			ans = ans + "IV" + s[i];
		}
		else if (diffIdx - i == 5) {
			ans = ans + "V" + s[i];
		}
		i = diffIdx - 1;
	}
	return ans;
}

int main() {
	// 1(a)
	string s; int n; cin >> s >> n;
	while (n--) {
		s = solve(s);
	}
	int countI = 0;
	int countV = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'I') countI++;
		else if (s[i] == 'V') countV++;
	}
	cout << countI << ' ' << countV << endl;

	// 1(c)
	unordered_set<string> descs;
	for (int i = 1; i <= 3999; i++) {
		string s = integer_to_Roman(i);
		descs.insert(solve(s));
	}
	cout << descs.size() << endl;

	return 0;
}