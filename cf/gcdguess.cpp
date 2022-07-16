#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <string>
#include <memory.h>
#include <queue>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define f first
#define s second

const int INF = 1e9;
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

void solve() {
    int cur = 0;
    int idx = 0;
    while(true) {
        cout << "? " << (1 << idx) - cur << " " <<  (1 << (idx + 1)) - cur << endl;
        int gcd; cin >> gcd;
        cur += (1 << (gcd-1));
    }
    cout << "! " << cur << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}