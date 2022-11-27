#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, s; cin >> n >> s;
    vector<int> v(n), buffer(n, 0);
    for(auto &e: v) cin >> e;
    sort(v.begin(), v.end(), greater<int>());
    while (s--) {
        int m, c; cin >> m >> c;
        for (int i = 0; i < c; i++) buffer[i] = v[i]-m;
        int idxBuffer = 0, idx = c;
        for(int i=0; i<n; i++) {
            if (idxBuffer==c) break;
            if (idx == n || v[idx] < buffer[idxBuffer]) {
                v[i] = buffer[idxBuffer];
                buffer[idxBuffer++] = 0;
            } else v[i] = v[idx++];
        }
    }
    for(auto &e: v) cout << e << "\n";
    return 0;
}
