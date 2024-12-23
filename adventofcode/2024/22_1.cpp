#include <bits/stdc++.h>
#define int long long

using namespace std;

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
    int ans = 0;
    int secret;
    while(cin >> secret) {
        for(int i=0; i<2000; i++) secret = compute(secret);
        ans += secret;
    }
    cout << ans << "\n";
    return 0;
}