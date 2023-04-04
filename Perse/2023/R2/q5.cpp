#include <bits/stdc++.h>

using namespace std;

signed main() {
	int lastWandWin = -1, score0 = 0, score1 = 0;
	for(int i=0; i<6; i++) {
		string s; cin >> s;
		if (s=="WW") {
			if (lastWandWin == 0) score0 = 0;
			else if (lastWandWin == 1) score1 = 0;
		} else if (s[0] == 'W') {
			score0++; lastWandWin = 0;
		} else if (s[1] == 'W') {
			score1++; lastWandWin = 1;
		} else if (s[0] == s[1]) {
			continue;
		} else if (s[0] == 'R') {
			if (s[1] == 'P') score1++;
			else score0++;
		} else if (s[0] == 'P') {
			if (s[1] == 'S') score1++;
			else score0++;
		} else if (s[0] == 'S') {
			if (s[1] == 'R') score1++;
			else score0++;
		}
	}
	cout << score0 << "-" << score1;
    return 0;
}
