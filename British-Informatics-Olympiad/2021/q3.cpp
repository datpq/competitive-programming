#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>;

#define INFINITY 9999

using namespace std;

unordered_map<string, int> calculated;

int computeOperations(string s) {
	int ans = INFINITY;
	if (!calculated.count(s)) {
		calculated[s] = ans;
		if (s.length() == 1) {
			ans = 1;
		} else if (s[s.length() - 1] == 'A' + s.length() - 1) { //add
			ans = computeOperations(s.substr(0, s.length() - 1)) + 1;
		}
		else {
			int ans1 = computeOperations(s.substr(1, 1) + s.substr(0, 1) + s.substr(2, s.length() - 1)) + 1; // swap
			int ans2 = computeOperations(s.substr(s.length() - 1, 1) + s.substr(0, s.length() - 1)) + 1; //rotate
			ans = min(ans1, ans2);
		}
	}

	ans = min(calculated[s], ans);
	calculated[s] = ans;
	return ans;
}

void cleanCalculated() {
	auto it = calculated.begin();
	while (it != calculated.end()) {
		if (it->second == INFINITY) {
			it = calculated.erase(it); //erase() return the next iterator so no need to increment
		} else {
			it++;
		}
	}
}

int main() {
	// 3(a)
	//while(true) {
		string s; cin >> s;
		int ans = computeOperations(s);
		cout << ans << endl;
	//}

	// 3(b)
	//string s = "ABCDE";
	//do {
	//	cleanCalculated();
	//	if (computeOperations(s) == 6) {
	//		cout << s << endl;
	//	}
	//} while (next_permutation(s.begin(), s.end()));

	//string s = "HGFEDCBA";
	//int ans = computeOperations(s);

	return 0;
}
