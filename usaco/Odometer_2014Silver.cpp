#include <bits/stdc++.h>
#define int long long

using namespace std;

string num;
map<tuple<int, int, bool, bool>, int> dp;

int dfs(int pos, int k, bool under, bool started, int digit, int digit2) {
    if (pos == num.size()) {
        if (!started) return 0;
        if (digit2 == -1) {
            return (k>=0 ? 1 : 0);
        } else {
            return (k==0 ? 1 : 0);
        }
    }
    tuple<int, int, bool, bool> key = {pos, k, under, started};
    if (dp.count(key)) return dp[key];

    int ans = 0;
    int numDigit = num[pos] - '0';
    for(int i=0; i<10; i++) {//add digit i to the position pos
        if (!under && i>numDigit) break;// if not under yet and receive i bigger than numDigit then stop
        bool new_under = under;
        if (i<numDigit) new_under = true;//under=true mean we can receive every digit from now
        bool new_started = started || i;
        if (new_started && digit2 != -1 && i!=digit && i!=digit2) continue;
        int new_k = k;
        if (new_started) new_k = i==digit ? k+1 : k-1;
        ans += dfs(pos+1, new_k, new_under, new_started, digit, digit2);
    }
    auto [k1, k2, k3, k4] = key;
    dp[key] = ans;
    return ans;
}

int compute(int n) {
    num = to_string(n);
    int ans = 0;
    for(int i=0; i<10; i++) {
        dp.clear();
        ans += dfs(0, 0, false, false, i, -1);
    }
    int duplicates = 0;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            dp.clear();
            duplicates += dfs(0, 0, false, false, i, j);
        }
    }
    ans -= (duplicates/2);
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream ifs("odometer.in");
    ofstream ofs("odometer.out");
    int X, Y;
    ifs >> X >> Y;
    int ans = compute(Y) - compute(X-1);
    ofs << ans << endl;
    return 0;
}
