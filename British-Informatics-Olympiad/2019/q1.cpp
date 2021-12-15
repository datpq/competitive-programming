#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string solve(string s) {
	int len = s.length();
	string sRight = s.substr((len+1) / 2, len - (len+1)/ 2);
	long nRight = sRight == "" ? 0 : stol(sRight); // right half to a long
	int idx = 0;
	while (len - idx - 1 > idx) {
		s[len - idx - 1] = s[idx];
		idx++;
	}
	sRight = s.substr((len + 1) / 2, len - (len + 1) / 2);
	if ((sRight == "" ? 0 : stol(sRight)) > nRight) return s;

	if (len % 2 == 1) { // 345 --> 353, 343 --> 353
		if (s[len / 2] != '9') {
			s[len / 2]++;
			return s;
		}
		else {
			s[len / 2] = '0';
		}
	}

	string sLeft = s.substr(0, len / 2);
	long nLeft = sLeft == "" ? 0 : stol(sLeft); // left half to a long
	if (nLeft == pow(10, len / 2) - 1) { // 999xx --> 10001, 99xx --> 1001
		string ans(len - 1, '0');
		ans = "1" + ans + "1";
		return ans;
	}
	else {
		nLeft++; // ABCxxx --> (ABC+1)
		sLeft = to_string(nLeft);
		for (int i = 0; i < len; i++) { // CDEF0xxx --> CDEFFEDC, CDE0xxx --> CDE0EDC
			if (i < len / 2) {
				s[i] = sLeft[i];
			}
			else if (len % 2 == 0 || i != len / 2) {
				s[i] = sLeft[len - i - 1];
			}
		}
		return s;
	}
	return s;
}

int main() {
	//while (true) {
		string s; cin >> s; // receive input as string (20 digits)
		cout << solve(s) << endl;
	//}
	return 0;
}