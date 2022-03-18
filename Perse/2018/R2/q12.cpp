#include <iostream>
#include <vector>

using namespace std;

int main() {
	int d, n; cin >> d >> n;
	vector<int> X(n + 1), Y(n + 1), seens(n + 1, false);
	X[0] = Y[0] = 0; seens[0] = true;
	vector<int> beaconSource = { 0 };
	for (int i = 1; i <= n; i++) cin >> X[i] >> Y[i];
	int idx = 0;
	int ans = 0;
	while(idx < beaconSource.size())
	{
		int beaconsSize = beaconSource.size();
		for (int i = idx; i < beaconsSize; i++) {
			for (int j = 1; j <= n; j++) {
				if (seens[j]) continue;
				if ((long long)(X[j] - X[beaconSource[i]]) * (X[j] - X[beaconSource[i]])
					+ (long long)(Y[j] - Y[beaconSource[i]]) * (Y[j] - Y[beaconSource[i]]) <= (long long)d * d) {
					beaconSource.push_back(j);
					seens[j] = true;
				}
			}
		}
		if (beaconSource.size() != beaconsSize) {
			ans += (beaconSource.size() - beaconsSize);
			cout << ans << endl;
		}
		idx = beaconsSize;
	}
	return 0;
}
