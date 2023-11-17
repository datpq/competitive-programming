#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
 
using namespace std;
int n, q;
map<int, long long> dp;
 
long long solve(vector<long long> &p, int idx) {
    if (dp.count(idx)) return dp[idx];
    long long ans = 0;
    if (idx > p.size()-3) {
        for(int i=idx; i<n; i++)
            ans += p[i]*(100-q)/100;
    } else if (idx == n - 3) {
        long long curAns = 0;
        for(int i=idx; i<n; i++)
            curAns += p[i]*(100-q)/100;
        ans = min(curAns, p[idx] + p[idx+1]);
    } else {
        ans = min(p[idx]*(100-q)/100 + solve(p, idx+1), p[idx] + p[idx+1] + solve(p, idx+3));
    }
    dp[idx] = ans;
    return ans;
}
 
int main() {
    cin >> n >> q;
    vector<long long> p(n);
    for(auto &x: p) cin >> x;
    sort(p.begin(), p.end(), greater<long long>());
    cout << solve(p, 0);
    return 0;
}
