#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n; cin >> n;
    map<int, pair<int, int>> m;
    int G = 0, L = 0;
    while (n--) {
        char c; int p; cin >> c >> p;
        if (!m.count(p)) m[p] = { 0, 0 };
        if (c == 'G') {
            m[p].second++; G++;
        }
        else {
            m[p].first++; L++;
        }
    }
    int best = G;
    int ans = best;
    int lastL = 0;
    for (auto& x : m) {
        ans -= (x.second.second - lastL);
        lastL = x.second.first;
        best = min(best, ans);
    }
    cout << best << endl;
    return 0;
}