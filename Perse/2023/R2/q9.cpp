#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main() {
    int n; cin >> n;
    int minX=0, minY=0, maxX=1e9, maxY=1e9;
    while(n--) {
        int x, y, dx, dy; cin >> x >> y >> dx >> dy;
        minX = max(minX, x);
        minY = max(minY, y);
        maxX = min(maxX, x+dx);
        maxY = min(maxY, y+dy);
    }
    cout << (maxX-minX)*(maxY-minY);
	return 0;
}
