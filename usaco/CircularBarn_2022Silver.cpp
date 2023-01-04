#include <bits/stdc++.h>

using namespace std;

const int INF = 5*1e6;
vector<int> sieve(INF, 0); // 0 --> prime number
// closest prime less than a number and have the same remainder when divide by 4
vector<int> closestPrime(INF, 0);
int maxPrime[4] = {0, 1, 2, 3};
void sieveEratos() {
    for(int x = 2; x < INF; x++) {
        closestPrime[x] = maxPrime[x % 4];
        if (sieve[x]) continue;
        maxPrime[x % 4] = x;
        for(int j = 2*x; j < INF; j += x) sieve[j] = x;
    }
}

bool solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
        if (!sieve[a[i]]) a[i] = 1; // if prime --> 1 step
        else if (a[i] % 4 == 0) a[i] /= 2; // if multiple of 4 --> 2nd win with a/2 steps
        else a[i] = 1 + (a[i]-closestPrime[a[i]])/2; // 1st win with 1 + (a-closestPrime)/2
	}
    int best = INF;
    for(auto x: a) if(best / 2 > x / 2) best = x; // 9 4 --> 3 2 --> 1st win.
    return best % 2 != 0;
}

int main() {
    sieveEratos();
	int t; cin >> t;
	while (t--) {
		cout << (solve() ? "Farmer John\n" : "Farmer Nhoj\n");
	}
	return 0;
}
