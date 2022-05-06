#include <iostream>

using namespace std;

const long long MAX_N = 999999999999;
string s;
string permutation;
int ans;

void decrypt() {
	for (int i = s.length() - 1; i > 0; i--) {
		int n = s[i] - s[i - 1];
		if (n < 1) n += 26;
		s[i] = 'A' + n - 1;
	}
}

void search(int idx) {
	if (idx == 3) {
		s = permutation;
		long long count = 0;
		for (long long i = 0; i < MAX_N; i++) {
			decrypt();
			count++;
			if (s == permutation) {
				if (MAX_N % count == 0) {
					//cout << s << ' ' << count << endl;
					ans++;
				}
				break;
			}
		}
	}
	else {
		for (int i = 0; i < 26; i++) {
			permutation[idx] = 'A' + i;
			search(idx + 1);
		}
	}
}

int main() {
	cin >> s;
	decrypt();
	cout << s << endl;

	//1b
	// ZZZZZ

	//1c
	//s = "OLYMPIAD";
	//int count = 0;
	//do {
	//	count++;
	//	decrypt();
	//} while (s != "OLYMPIAD");
	//cout << count << endl;

	//1d
	//permutation = "AAA";
	//ans = 0;
	//search(0);
	//cout << ans << endl;

	return 0;
}