#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
bool ycomp(const pair<int, int>& a, const pair<int, int> b) { return a.second > b.second; }

int main() {
	ifstream ifs("rental.in");
	ofstream ofs("rental.out");
	int N, M, R; ifs >> N >> M >> R;
	vector<int> c(N), r(R);
	vector<pair<int, int>> shop(M);
	long long sum = 0;
	for (int i = 0; i < N; i++) ifs >> c[i], sum += c[i];
	for (int i = 0; i < M; i++) ifs >> shop[i].first >> shop[i].second;
	for (int i = 0; i < R; i++) ifs >> r[i];
	sort(c.begin(), c.end());
	sort(shop.begin(), shop.end(), ycomp);
	sort(r.begin(), r.end(), greater<int>());
	vector<long long> sells;
	long long value = 0;
	int j = 0; // shop index
	for (int i = N - 1; i >= 0; i--) {
		int left = c[i];
		while (j < M && left > 0) {
			if (left > shop[j].first) {
				left -= shop[j].first;
				value += (long long)shop[j].first * shop[j].second;
				shop[j].first = 0;
				j++;
			}
			else {
				value += (long long)left * shop[j].second;
				shop[j].first -= left;
				left = 0;
			}
		}
		sells.push_back(value);
	}

	long long best = sells[N-1];
	long long rent = 0;
	for (int i = 0; i < min(N, R); i++) {
		rent += r[i];
		long long ans = rent + sells[N-i-2];
		best = max(best, ans);
	}
	ofs << best << endl;
	return 0;
}
