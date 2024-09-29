#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
string arr[4];

bool used[4];
bool search(string s, int idx) {
	if (idx == s.size()) return true;
	bool ans = false;
	for (int i = 0; i < 4; i++) {
		if (!ans && !used[i] && arr[i].find(s[idx]) != string::npos) {
			used[i] = true;
			ans = search(s, idx + 1);
			used[i] = false;
		}
	}
	return ans;
}

bool solve(string s) {
	memset(used, 4, false);
	return search(s, 0);
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < 4; i++) cin >> arr[i];
	vector<string> str(n);
	for (int i = 0; i < n; i++) cin >> str[i];
	for (int i = 0; i < n; i++) {
		cout << (solve(str[i]) ? "YES" : "NO") << endl;
	}

	return 0;
}