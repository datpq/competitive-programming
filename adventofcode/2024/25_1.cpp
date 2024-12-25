#include <bits/stdc++.h>

using namespace std;

const int rows = 5;
const int cols = 5;

bool check(vector<int> &lock, vector<int> &key) {
    for(int i=0; i<cols; i++) {
        if (lock[i] + key[i] > rows) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif
    vector<vector<int>> keys, locks;
    string s;
    int r = 0;
    bool readingKey = true;
    while(getline(cin, s)) {
        if (s.empty()) {
            r = 0; // new grid
            continue;
        }
        if (r==0) {
            readingKey = s[0] == '.';
            if (readingKey) {
                vector<int> v(cols, rows);
                keys.push_back(v);
            } else {
                vector<int> v(cols, 0);
                locks.push_back(v);
            }
        } else if (r<=rows) {
            if (readingKey) {
                for(int i=0; i<cols; i++) {
                    if (s[i]=='.') keys[keys.size()-1][i]--;
                }
            } else {
                for(int i=0; i<cols; i++) {
                    if (s[i]=='#') locks[locks.size()-1][i]++;
                }
            }
        }
        r++;
    }
    int ans = 0;
    for(int i=0; i<locks.size(); i++) {
        for(int j=0; j<keys.size(); j++) {
            if (check(locks[i], keys[j])) ans++;
        }
    }
    cout << ans;
    return 0;
}