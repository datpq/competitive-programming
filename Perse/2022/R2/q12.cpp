#include <iostream>
#include <vector>

using namespace std;

int n, dest, permCount;
vector<int> permutation = { 0 };

void search(int node) {
	if (permCount >= n) return;
	if (node == dest) {
		permCount++;
		if (permCount == n) {
			for (int i = 0; i < permutation.size(); i++) {
				cout << (permutation[i] < 26 ? (char)('A' + permutation[i]) : (char)('a' + (permutation[i] - 26)));
			}
		}
	}
	else {
		for (int i = 1; i <= 2; i++) {
			if (node + i > dest) break;
			permutation.push_back(node+i);
			search(node+i);
			permutation.pop_back();
		}
	}
}

int main() {
	string s; cin >> s >> n;
	dest = s.length() - 1;
	permCount = 0;
	search(0);
	return 0;
}
