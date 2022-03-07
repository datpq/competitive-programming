#include <iostream>
#include <vector>
#include <set>
#include <math.h>

#define NUMS 10000
using namespace std;
set<long long> seens;

long long fold(long long n) {
	int digits = log10(n);
	int d = digits / 2 + 1;
	long long ans = (n / (int)pow(10, d)) + (n % (int)pow(10, d));
	return ans;
}

long long solve(long long n) {
	long long ans = n * n;
	while (ans >= 1000000) ans = fold(ans);
	while (seens.count(ans)) ans++;
	return ans;
}

int main() {
	long long n, target; cin >> n >> target;
	vector<long long> vect = { n }; seens.insert(n);
	long long sum = n;
	while(true) {
		n = solve(n);
		if (vect.size() >= NUMS) {
			if (sum == target) {
				cout << n << endl;
				return 0;
			}
			sum -= vect[vect.size() - NUMS];
		}
		vect.push_back(n);
		sum += n;
		seens.insert(n);
	}
	return 0;
}
