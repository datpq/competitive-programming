// receive n as string --> 5/10. as still we have to output ans as integer
#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	string s; cin >> s;
	int digits = 0;
	int ansByDigits = 0; //number of 7 of all numbers less than 10, 100, 1000,...
	int ans = 0;
	while(s.length()) {
		int r = stoi(s.substr(s.length()-1, 1));
		ans+= r*ansByDigits;
		if (r >= 7) ans+=pow(10, digits);
		ansByDigits = 10*ansByDigits + pow(10, digits);
		s = s.substr(0, s.length()-1);
		digits++;
	}
	cout << ans;
	return 0;
}

// receive n as integer --> 5/10
#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	string s; cin >> s;
	int digits = 0;
	int ansByDigits = 0; //number of 7 of all numbers less than 10, 100, 1000,...
	int ans = 0;
	while(s.length()) {
		int r = stoi(s.substr(s.length()-1, 1));
		ans+= r*ansByDigits;
		if (r >= 7) ans+=pow(10, digits);
		ansByDigits = 10*ansByDigits + pow(10, digits);
		s = s.substr(0, s.length()-1);
		digits++;
	}
	cout << ans;
	return 0;
}
