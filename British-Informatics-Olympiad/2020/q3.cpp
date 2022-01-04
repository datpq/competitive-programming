#include <iostream>

using namespace std;

int p, q, r;
long n;
string s;
long permutationCount;

void generatePermutation(int idx, int sameCount) {
	if (permutationCount >= n) return;
	if (idx == r) {
		//cout << s << endl;
		permutationCount++;
		if (permutationCount == n) cout << s << endl;
		return;
	}
	for (int i = 0; i < p; i++) {
		if (idx == 0) {
			s[idx] = 'A' + i;
			generatePermutation(idx + 1, 1);
		}
		else if ('A' + i == s[idx-1] && sameCount < q) {
			s[idx] = 'A' + i;
			generatePermutation(idx + 1, sameCount+1);
		}
		else if ('A' + i != s[idx - 1]) {
			s[idx] = 'A' + i;
			generatePermutation(idx + 1, 1);
		}
	}
}

//9 / 27 marks
int main() {
	//while (true) {
		cin >> p >> q >> r >> n;
		string temp(r, ' ');
		s = temp;
		permutationCount = 0;
		generatePermutation(0, 0);
	//}

	return 0;
}