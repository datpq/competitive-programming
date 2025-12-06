#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> x;

bool check(int r) {
    int cur = x[0];
    for(int i=0; i<k; i++) {
        int next = cur + 2 * r;
        auto it = upper_bound(x.begin(), x.end(), next);
        if (it == x.end()) return true;
        cur = *it;
    }
    return false;
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

signed main() {
    ifstream  ifs("angry.in");
    ofstream ofs("angry.out");
    ifs >> n >> k;
    x.resize(n);
    for(int i=0; i<n; i++) ifs >> x[i];
    sort(x.begin(), x.end());
    int r = firstTrue(0, 1e9);
    ofs << r << '\n';
    return 0;
}