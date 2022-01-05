#include <iostream>
#include <map>

using namespace std;

int p, q, r;
long long n, permutationCount;
string s;

map<pair<int, int>, long long> sections;

void generatePermutation(int idx, int sameCount) {
	if (permutationCount >= n) return;
	if (idx == r) {
		//cout << s << endl;
		permutationCount++;
		if (permutationCount == n) cout << s << endl;
		return;
	}
	
	auto pastKey = make_pair(idx, sameCount);
	if (sections.count(pastKey) && permutationCount + sections[pastKey] < n) {
		permutationCount += sections[pastKey];
		return;
	}
	long long oldPermutationCount = permutationCount;
	for (int i = 0; i < p; i++) {
		if (idx == 0 || 'A' + i != s[idx - 1]) {
			s[idx] = 'A' + i;
			generatePermutation(idx + 1, 1);
		}
		else if ('A' + i == s[idx - 1] && sameCount < q) {
			s[idx] = 'A' + i;
			generatePermutation(idx + 1, sameCount + 1);
		}
	}
	long long sectionCount = permutationCount - oldPermutationCount;
	sections[pastKey] = sectionCount;
}

int main() {
	//while (true) {
		cin >> p >> q >> r >> n;
		string temp(r, ' ');
		s = temp;
		permutationCount = 0;
		sections.clear();
		generatePermutation(0, 0);
	//}
	return 0;
}