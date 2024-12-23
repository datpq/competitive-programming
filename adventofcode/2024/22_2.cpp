#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2000;
const int MOD = 16777216;
int compute(int secret) {
    secret ^= (secret * 64);
    secret %= MOD;
    secret ^= (secret / 32);
    secret %= MOD;
    secret ^= (secret * 2048);
    secret %= MOD;
    return secret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif
    int a;
    vector<int> tmp(20*20*20*20, 0);
    vector<vector<int>> v;

    while(cin >> a) {
        v.push_back(tmp);
        vector<int> diff;
        for(int i=0; i<N; i++) {
            int b = compute(a);
            diff.push_back(b%10 - a%10 + 10);
            a = b;
            int n = diff.size();
            if (n >= 4) {
                int key = 20*20*20*diff[n-4] + 20*20*diff[n-3] + 20*diff[n-2] + diff[n-1];
                if (!v[v.size()-1][key]) v[v.size()-1][key] = a%10;
            }
        }
    }
    int ans = 0;
    for(int j=0; j<v[0].size(); j++) {
        int sum = 0;
        for(int i=0; i<v.size(); i++) {
            sum += v[i][j];
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}