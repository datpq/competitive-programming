#include <bits/stdc++.h>
#define int long long

using namespace std;

int rows, cols;
vector<string> grid;
int srcX, srcY;
const pair<int, int> dirs[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const string dirstr = "><v^";

vector<pair<int, int>> moves;
bool moveable = true;
void moveVertical(int x, int y, int dx) {
    if (!moveable) return;
    if (grid[x][y] == '#') {
        moveable = false; return;
    } else if (grid[x][y] != '.') {
        moves.emplace_back(x, y);
        if (grid[x][y] == ']') {
            moves.emplace_back(x, y-1);
            moveVertical(x+dx, y, dx);
            moveVertical(x+dx, y-1, dx);
        } else if (grid[x][y] == '[') {
            moves.emplace_back(x, y+1);
            moveVertical(x+dx, y, dx);
            moveVertical(x+dx, y+1, dx);
        } else if (grid[x][y] == '@') {
            moveVertical(x+dx, y, dx);
        }
    }
}

void move(char dirc) {
    auto [dx, dy] = dirs[dirstr.find(dirc)];
    int x=srcX, y=srcY;
    x+=dx, y+=dy;
    if (dx == 0) {
        while(grid[x][y] != '#' && grid[x][y] != '.') {
            x+=dx, y+=dy;
        }
        if (grid[x][y] == '.') {
            while(!(x == srcX && y == srcY)) {
                grid[x][y] = grid[x-dx][y-dy];
                x-=dx; y-=dy;
            }
            grid[x][y] = '.';
            srcX+=dx; srcY+=dy;
        }
    } else {//dy == 0
        moves.clear();
        moveable = true;
        moveVertical(srcX, srcY, dx);
        if (moveable) {
            sort(moves.begin(), moves.end());
            moves.erase( unique( moves.begin(), moves.end() ), moves.end() );
            if (dx > 0) reverse(moves.begin(), moves.end());
            for(int i=0; i<moves.size(); i++) {
                auto [x, y] = moves[i];
                grid[x+dx][y] = grid[x][y];
                grid[x][y] = '.';
            }
            srcX += dx;
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

    string s, path;
    bool pathReading = false;
    while(getline(cin, s)) {
        if (pathReading) {
            path += s;            
        } else if (!s.empty()) {
            string line = "";
            for(auto c: s) {
                if (c == '#') line.append("##");
                else if (c == 'O') line.append("[]");
                else if (c == '.') line.append("..");
                else if (c == '@') line.append("@.");
            }
            if (line.find('@') != string::npos) {
                srcX = grid.size();
                srcY = line.find('@');
            }
            grid.push_back(line);
        } else {
            pathReading = true;
        }
    }
    rows = grid.size(), cols = grid[0].size();
    for(auto c: path) move(c);
    int ans = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if (grid[i][j] == '[') {
                ans += 100*i + j;
            }
        }
    }
    cout << ans;
    return 0;
}