#include <bits/stdc++.h>
#define int long long

using namespace std;

bool check(int result, vector<int> &v) {
    int n = v.size();
    for(int s=0; s<(1<<(n-1)); s++) {
        int sum = v[0];
        for(int i=0; i<n-1; i++) {
            if ((s >> i) & 1) {
                sum *= v[i+1];
            } else {
                sum += v[i+1];
            }
            if (sum > result) break;
        }
        if (sum == result) return true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    int ans = 0;
    string s;
    while(getline(cin, s)) {
        int result; char c;
        stringstream ss(s);
        ss >> result >> c;
        vector<int> v; int a;
        while (ss >> a) v.push_back(a);
        if (check(result, v)) ans += result;
    }
    cout << ans;
    return 0;
}