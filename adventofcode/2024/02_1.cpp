#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> &v) {
    bool inc = v[0] < v[1];
    for(int i=0; i<v.size()-1; i++) {
        if ((inc && v[i] >= v[i+1]) || (!inc && v[i] < v[i+1])) return false;
        if (v[i] == v[i+1] || abs(v[i]-v[i+1]) > 3) return false;
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
    }
    cout << ans;
    return 0;
}