#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, ta, tb;
vector<int> a, b, c;

//a(ta-x) + b(tb-y) <= c, x+y = mid <=> a.ta + b.tb -(a.x + b.y) <= c
//<=> a.ta+b.tb-c <= ax + by.
//if (a>b) ==> a.ta+b.tb-c <= (a-b)x + b(x+y) <=> ceil((a.ta+b.tb-c - b.mid) / (a-b)) <=x
//you have minX, minY over the loop.
//These 2 min have to satisfy the condition minX+minY >= mid and minX< ta, minY<tb
bool check(int mid) {
    int minRa = 0, minRb = 0;
    for(int i=0; i<N; i++) {
        if (c[i] >= (ta*a[i] + tb*b[i])) continue;
        int rest = (ta*a[i] + tb*b[i]) - c[i] - mid*min(a[i], b[i]);
        if (rest < 0) continue;
        if (a[i] > b[i]) {
            int newMin = rest/(a[i]-b[i]);
            minRa = max(minRa, rest % (a[i]-b[i]) == 0 ? newMin : newMin+1);
        } else if (a[i] < b[i]) {
            int newMin = rest/(b[i]-a[i]);
            minRb = max(minRb, rest % (b[i]-a[i]) == 0 ? newMin : newMin+1);
        } else if (rest > 0) return false;
        if (minRa + minRb > mid) return false;
        if (minRa >= ta || minRb >= tb) return false;
    }
    return true;
}

int firstTrue(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int solve() {
    cin >> N >> ta >> tb;
    a = vector<int>(N); b = vector<int>(N); c = vector<int>(N);
    for(int i=0 ; i<N; i++) cin >> a[i] >> b[i] >> c[i];
    return firstTrue(0, 2e9);
}

signed main() {
    int t; cin >> t;
    while(t--) cout << solve() << "\n";
    return 0;
}
