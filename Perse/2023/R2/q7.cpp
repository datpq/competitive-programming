#include <bits/stdc++.h>
#define Node pair<int, int>

using namespace std;

string grid[6];
void dfs(Node node, Node prev) {
    if (prev.first >= 0 && prev.second >= 0) {
        grid[prev.first][prev.second] = '0';
        grid[node.first][node.second] = '#';
    }
    pair<int, int> arr[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(auto p: arr) {
        int newX = (node.first + p.first) % 6;
        if (newX < 0) newX += 6;
        int newY = (node.second + p.second) % 6;
        if (newY < 0) newY += 6;
        auto child = make_pair(newX, newY);
        if (child == prev) continue;
        if (grid[newX][newY] == '0') {
            dfs(child, node);
            break;
        }
    }
}

signed main() {
    int srcX, srcY;
    for(int i=0; i<6; i++) {
        cin >> grid[i];
        int j = grid[i].find('#');
        if (j>=0) { srcX = i; srcY = j; }
    }
    dfs({srcX, srcY}, {-1, -1});
    for(auto str: grid) cout << str << "\n";
    return 0;
}
