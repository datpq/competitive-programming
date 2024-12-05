#include <bits/stdc++.h>
#define int long long

using namespace std;
vector<string> grid;

int rows, cols;
vector<vector<pair<int, int>>> dirs = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {0, -1}, {0, -2}, {0, -3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {-1, 0}, {-2, 0}, {-3, 0}},
    {{0, 0}, {1, 1}, {2, 2}, {3, 3}},
    {{0, 0}, {-1, -1}, {-2, -2}, {-3, -3}},
    {{0, 0}, {1, -1}, {2, -2}, {3, -3}},
    {{0, 0}, {-1, 1}, {-2, 2}, {-3, 3}},
};
const string XMAS = "XMAS";

int search(int i, int j) {
    int ans = 0;
    for(auto d: dirs) {
        bool found = true;
        for(int k=0; k<4; k++) {
            auto [dx, dy] = d[k];
            int x=i+dx;
            int y=j+dy;
            if (x<0 || x>=rows || y<0 || y>=cols || grid[x][y] != XMAS[k]) {
                found = false; break;
            }
        }
        if (found) ans++;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif
    const int LINES=140;

    for(int i=0; i<LINES; i++)
    {
        string s; getline(cin, s);
        grid.push_back(s);
    }
    rows = grid.size();
    cols = grid[0].size();
    int ans = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            ans += search(i, j);
        }
    }
    cout << ans;
    return 0;
}