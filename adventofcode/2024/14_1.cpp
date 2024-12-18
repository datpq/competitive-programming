#include <bits/stdc++.h>
#define int long long

using namespace std;

const int rows = 103;
const int cols = 101;
const int STEP = 100;
int q1 = 0, q2 = 0, q3 = 0, q4 = 0;

void compute(int x, int y, int vx, int vy) {
    int nx = (x + vx*STEP)%rows;
    if (nx < 0) nx+=rows;
    int ny = (y + vy*STEP)%cols;
    if (ny < 0) ny+=cols;
    if (nx < rows/2) {
        if (ny<cols/2) {
            q1++;
        } else if (ny>cols/2) {
            q2++;
        }
    } else if (nx > rows/2) {
        if (ny<cols/2) {
            q3++;
        } else if (ny>cols/2) {
            q4++;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    // compute(4, 2, -3, 2);
    string s;
    while(getline(cin, s)) {
        stringstream ss(s);
        char c; int x,y,vx,vy;
        ss >> c >> c >> y >> c >> x >> c >> c >> vy >> c >> vx;
        compute(x, y, vx, vy);
    }
    int ans = q1*q2*q3*q4;
    cout << ans;
    return 0;
}