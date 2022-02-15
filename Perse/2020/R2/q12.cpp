#include <iostream>
#include <set>

using namespace std;

long long gcd(long long a, long long b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

int shuffle(int idx, int n, int k) {
	return (idx >= n - k) ? n - 1 - idx : idx < (n - k) / 2 ? (k + 2 * idx) : (k + 2 * (idx - (n - k) / 2) + 1);
	//n = 9, k = 3 ==> 0 1 2 3 4 5 6 7 8 ==> 8 7 6 0 3 1 4 2 5
	//0-->3+2*0=3, 1-->3+2*1=5, ..., 4-->3+2*(4-(9-3)/2)+1=6, 7-->9-1-7=1
}

int main() {
	int n, k; cin >> n >> k;
	set<int> done;

	long long ans = 1;
	for (int i = 0; i < n; i++) {
		if (!done.count(i)) {
			int idx = i;
			long long count = 0;
			do {
				done.insert(idx);
				idx = shuffle(idx, n, k);
				count++;
			} while (idx != i);
			ans *= (count / gcd(ans, count));
		}
	}
	cout << ans << endl;
	return 0;
}