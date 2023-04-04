#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> pos;

int diff(int x) {
    return ((x < pos[x] ? x+n : x)-pos[x]);
}

signed main() {
    int q; cin >> n >> q;
    pos = vector<int>(n);
    map<int, int> m;
    for(int i=0; i<n; i++) {
        int x; cin >> x; x--;
        pos[x] = i;
        m[diff(x)]++;
    }
    for(int i=0; i<n; i++) {
        int x, y; cin >> x >> y; x--; y--;
        m[diff(x)]--; if (!m[diff(x)]) m.erase(diff(x));
        m[diff(y)]--; if (!m[diff(y)]) m.erase(diff(y));
        swap(pos[x], pos[y]);
        m[diff(x)]++; m[diff(y)]++;
        cout << (m.size() == 1 ? "OUI" : "NON") << "\n";
    }
    return 0;
}
