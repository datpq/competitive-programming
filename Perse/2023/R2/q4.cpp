#include <bits/stdc++.h>

using namespace std;

signed main() {
	string s1, s2;
	while(cin >> s1) {
		cin >> s2;
		int idx = 0;
		for(; idx<min(s1.size(), s2.size()); idx++) {
			if (s1[idx] != s2[idx]) {
				cout << s1[idx] << " " << s2[idx] << "\n";
				return 0;
			}
		}
		if (s1.size() != s2.size()) {
			if (idx == s1.size()) cout << "_ " << s2[idx] << "\n";
			else if (idx == s2.size()) cout << s1[idx] << " _\n";
			return 0;
		}
	}
    return 0;
}
