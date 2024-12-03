#include <bits/stdc++.h>

using namespace std;

int arr(vector<int> &v, int i, int idx) {
    if (i<idx) return v[i];
    return v[i+1];
}

bool solve(vector<int> &v) {
    bool inc = v[0] < v[1];
    for(int i=0; i<v.size()-1; i++) {
        if ((inc && v[i] >= v[i+1]) || (!inc && v[i] < v[i+1])) return false;
        if (v[i] == v[i+1] || abs(v[i]-v[i+1]) > 3) return false;
    }
    return true;
}

bool solveTolerate(vector<int> &v, int idx) {
    if (v.size() < 3) return false;
    bool inc = arr(v, 0, idx) < arr(v, 1, idx);
    for(int i=0; i<v.size()-2; i++) {
        if ((inc && arr(v, i, idx) >= arr(v, i+1, idx) || (!inc && arr(v, i, idx) < arr(v, i+1, idx)))) return false;
        if ((arr(v, i, idx) == arr(v, i+1, idx) || abs(arr(v, i, idx)-arr(v, i+1, idx)) > 3)) return false;
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
    const int LINES=1000;
    int ans = 0;
    for(int i=0; i<LINES; i++)
    {
        string s; getline(cin, s);
        stringstream ss(s);
        vector<int> v;
        int a;
        while (ss >> a) {
            v.push_back(a);
        }
        if (solve(v)) ans++;
        else {
            bool tolerable = false;
            for(int idx=0; idx<v.size(); idx++) {
                if (solveTolerate(v, idx)) {
                    tolerable = true;
                    break;
                }
            }
            if (tolerable) ans++;
        }
    }
    cout << ans;
    return 0;
}