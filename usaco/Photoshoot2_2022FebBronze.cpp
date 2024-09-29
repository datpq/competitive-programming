#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

int solve(vector<int>& src, vector<int>& dest) {
	vector<bool> processed(n+1, false);
	int ans = 0;
	int idx1 = 0; int idx2 = 0;
	while (idx2 < n) {
		if (processed[src[idx1]]) {
			idx1++;
		}
		else if (src[idx1] == dest[idx2]) {
			processed[src[idx1]] = true;
			while (idx1 < src.size() && processed[src[idx1]]) {
				idx1++;
			}
		}
		else {
			ans++;
			processed[dest[idx2]] = true;
		}
		idx2++;
	}
	return ans;
}

int main() {
	cin >> n;
	vector<int> src(n), dest(n);
	for (auto& x : src) cin >> x;
	for (auto& x : dest) cin >> x;
	cout << solve(src, dest) << endl;

	return 0;
}