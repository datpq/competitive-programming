#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, Q; cin >> N >> Q;
	vector<long long> prefix(N+1);
	long long sum = 0; prefix[0] = sum;
	for(int i=1; i<=N; i++) {
		int a; cin >> a;
		sum += a; prefix[i] = sum;
	}
	for (int i = 0; i < Q; i++) {
		int l, r; cin >> l >> r;
		cout << prefix[r] - prefix[l] << endl;
	}
	return 0;
}
