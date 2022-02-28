#include <iostream>
#include <map>

using namespace std;

long long factorial(int n) {
	long long ans = 1;
	for (int i = 1; i <= n; i++) ans *= i;
	return ans;
}

long long computePermutationCount(map<char, int>& m) {
	long long ans = 1;
	int len = 0;
	for (auto& x : m) {
		len += x.second;
		ans *= factorial(x.second);
	}
	// n! / (m1! * m2! * ... * mk!)
	ans = factorial(len) / ans;
	return ans;
}

//search the next character
void search(map<char, int>& m, long long n) {
	for (auto& x : m) {
		if (x.second > 0) {
			x.second--;
			long long permutationCount = computePermutationCount(m);
			if (permutationCount >= n) {
				cout << x.first;
				search(m, n);
				break;
			}
			else {
				x.second++;
				n -= permutationCount;
			}
		}
	}
}

int main() {
	string s; long long n; cin >> s >> n;
	map<char, int> m;
	for (char& c : s) m[c]++;
	search(m, n);
	cout << endl;
	return 0;
}
