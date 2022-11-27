#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s; cin >> n >> s;
    vector<int> v(n), buffer(n, 0);
    for(auto &e: v) cin >> e;
    sort(v.begin(), v.end(), greater<int>());
    while (s--) {
        int m, centers; cin >> m >> centers;
        for (int i = 0; i < centers; i++) buffer[i] = v[i]-m;
        int a = 0, b = centers;
        for(int i=0; i<n; i++) {
            if (a==centers) break;
            if (b == n || v[b] < buffer[a]) v[i] = buffer[a++];
            else v[i] = v[b++];
        }
    }
    for(auto &e: v) cout << e << "\n";
    return 0;
}
