#include <bits/stdc++.h>
#define int long long

using namespace std;

const vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
const string dirstr = "<>v^";
const vector<string> NUMPAD = {
    "789",
    "456",
    "123",
    " 0A"
};
const vector<string> DIRPAD = {
    " ^A",
    "<v>",
};

int rows, cols;
void bfs(const vector<string> &grid, vector<vector<vector<pair<int, int>>>> &parent,
    vector<vector<vector<int>>> &parentIdx, char dest, int &srcX, int &srcY) {
    queue<pair<int, int>> q;
    vector<vector<int>> dis(rows, vector<int>(cols, INT_MAX));
    q.push({srcX, srcY}); dis[srcX][srcY] = 0;
    while(!q.empty()) {
        auto [x, y]=q.front(); q.pop();
        if (grid[x][y] == dest) srcX=x, srcY=y;
        for(int i=0; i<4; i++) {
            auto [dx, dy] = dirs[i];
            int cx=x+dx, cy=y+dy;
            if (cx<0 || cx>=rows || cy<0 ||cy>=cols || grid[cx][cy] == ' ') continue;
            if (dis[cx][cy] > dis[x][y] + 1) {
                parent[cx][cy].clear(), parentIdx[cx][cy].clear();
                parent[cx][cy].emplace_back(x, y), parentIdx[cx][cy].push_back(i);
                q.push({cx, cy});
                dis[cx][cy] = dis[x][y] + 1;
            } else if (dis[cx][cy] == dis[x][y] + 1) {
                parent[cx][cy].emplace_back(x, y), parentIdx[cx][cy].push_back(i);
            }
        }
    }
}

void findPaths(vector<vector<vector<pair<int, int>>>> &parent, vector<vector<vector<int>>> &parentIdx,
    int x, int y, string &path, vector<string> &paths) {
    if (parent[x][y].empty()) {
        auto tmp = path;
        reverse(tmp.begin(), tmp.end());
        tmp.push_back('A');
        paths.push_back(tmp);
        return;
    }
    for(int i=0; i<parent[x][y].size(); i++) {
        auto [cx, cy] = parent[x][y][i];
        path.push_back(dirstr[parentIdx[x][y][i]]);
        findPaths(parent, parentIdx, cx, cy, path, paths);
        path.pop_back();
    }
}

void concatPaths(vector<vector<string>> &paths, int idx, string &path, vector<string> &result) {
    if (idx == paths.size()) {
        result.push_back(path);
        return;
    }
    for(auto &v: paths[idx]) {
        path.insert(path.end(), v.begin(), v.end());
        concatPaths(paths, idx+1, path, result);
        for(int i=0; i<v.size(); i++) path.pop_back();
    }
}

void bfsLine(const vector<string> &pad, string &s, int x, int y, vector<string> &result) {
    vector<vector<string>> allPaths;
    for(char c: s) {
        rows = pad.size(), cols = pad[0].length();
        vector<vector<vector<pair<int, int>>>>parent(rows, vector<vector<pair<int, int>>>(cols));
        vector<vector<vector<int>>> parentIdx(rows, vector<vector<int>>(cols));
        bfs(pad, parent, parentIdx, c, x, y);
        string path;
        vector<string> paths;
        findPaths(parent, parentIdx, x, y, path, paths);
        allPaths.push_back(paths);
    }
    string path;
    concatPaths(allPaths, 0, path, result);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    string line;
    vector<string> v;
    while(cin >> line) v.push_back(line);

    int ans = 0;
    for(auto &s: v) {
        vector<string> ans1;
        bfsLine(NUMPAD, s, 3, 2, ans1); // starting node A in NUMPAD
        vector<string> ans2;
        int sz = INT_MAX;
        for(auto &s1: ans1) {
            vector<string> result;
            bfsLine(DIRPAD, s1, 0, 2, result); // starting node A in NUMPAD
            for(auto &sr: result) {
                if (sr.length() > sz) continue;
                if (sr.length() < sz) ans2.clear();
                sz = sr.length();
                ans2.push_back(sr);
            }
        }
        sz = INT_MAX;
        for(auto &s2: ans2) {
            vector<string> result;
            bfsLine(DIRPAD, s2, 0, 2, result); // starting node A in NUMPAD
            for(auto &sr: result) sz = min(sz, (int)sr.length());
        }

        int n = stoi(s);
        ans += n*sz;
    }
    cout << ans;
    #ifdef DEBUG
        cout << endl << "__________________________";
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}