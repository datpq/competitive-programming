#include <bits/stdc++.h>
#define int long long

using namespace std;

int solve(int ax, int ay, int bx, int by, int x, int y) {
    if (x % gcd(ax, bx) != 0) return 0;
    if (y % gcd(ay, by) != 0) return 0;
    int ans = 400;
    for(int i=0; i<=100; i++) {
        int restX = x - i*ax;
        int restY = y - i*ay;
        if (restX >= 0 && restY >= 0 && restX%bx==0 && restY%by==0 && restX/bx == restY/by) {
            ans = min(ans, 3*i + restX/bx);
        }
    }
    if (ans == 400) return 0;
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    const string ButtonA = "Button A: ";
    const string ButtonB = "Button B: ";
    const string Prize = "Prize: ";

    string s;
    int x, y, ax, ay, bx, by;
    int ans = 0;
    while(getline(cin, s)) {
        if (s.rfind(ButtonA, 0) == 0) {
            stringstream ss(s.substr(ButtonA.length()));
             char c; ss >> c >> c >> ax >> c >> c >> c >> ay;
        } else if (s.rfind(ButtonB) == 0) {
            stringstream ss(s.substr(ButtonB.length()));
             char c; ss >> c >> c >> bx >> c >> c >> c >> by;
        }  else if (s.rfind(Prize) == 0) {
            stringstream ss(s.substr(Prize.length()));
            char c; ss >> c >> c >> x >> c >> c >> c >> y;
            ans += solve(ax, ay, bx, by, x, y);
        }
    }
    cout << ans;

    return 0;
}