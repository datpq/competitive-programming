#include <bits/stdc++.h>

using namespace std;

ifstream ifs("pails.in");
ofstream ofs("pails.out");

int solve() {
    int X, Y, M;
    ifs >> X >> Y >> M;
    for(int m=M; m>=0; m--) {
        for(int i=0; i*X<=m; i++) {
            if ((m-i*X) % Y == 0) return m;
        }
    }
    return 0;
}

signed main() {
    ofs << solve();
    return 0;
}