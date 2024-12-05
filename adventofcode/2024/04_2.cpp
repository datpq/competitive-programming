#include <bits/stdc++.h>
#define int long long

using namespace std;
vector<string> grid;

int rows, cols;
vector<vector<pair<int, int>>> dirs = {
    {{-1, -1}, {0, 0}, {1, 1}},
    {{-1, 1}, {0, 0}, {1, -1}},
};
const string MAS = "MAS";
const string SAM = "SAM";

int search(int i, int j) {
    int ans = 0;
    for(auto d: dirs) {
        string s = "";
        for(int k=0; k<3; k++) {
            auto [dx, dy] = d[k];
            int x=i+dx;
            int y=j+dy;
            if (x<0 || x>=rows || y<0 || y>=cols) return 0;
            s += grid[x][y];
        }
        if (s != MAS && s != SAM) return 0;
    }
    return 1;
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