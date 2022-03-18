#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream ifs("div7.in");
	ofstream ofs("div7.out");
	int N; ifs >> N;
	vector<long long> prefix(N);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		int a; ifs >> a;
		sum += a; sum %= 7; prefix[i] = sum;
	}
	vector<int> rem1(7, N), rem2(7, -1);
	for (int i = 0; i < N; i++) {
		rem1[prefix[i]] = min(i, rem1[prefix[i]]);
		rem2[prefix[i]] = max(i, rem2[prefix[i]]);
	}
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		if (rem1[i] != -1 && rem2[i] != N) ans = max(ans, rem2[i] - rem1[i]);
	}
	ofs << ans << endl;
	return 0;
}