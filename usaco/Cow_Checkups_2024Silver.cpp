#include <bits/stdc++.h>
#define int long long

using namespace std;

int solve(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int ans = 0;
    vector<int> leftB(n, 0), rightB(n, 0), cnt(n, 0);
    for(int i=0; i<n; i++) {
        cnt[b[i]]++;
    }
    for(int i=0, j=n-1; i<n; i++, j--) {
        if (i < j) {
            leftB[b[i]] += i+1;
            rightB[b[j]] += i+1;
            cnt[b[i]]--;
            cnt[b[j]]--;
            ans += cnt[a[i]]*(i+1);
        } else if (i > j) {
            leftB[b[j]] -= j+1;
            rightB[b[i]] -= j+1;
            cnt[b[i]]++;
            cnt[b[j]]++;
            ans += cnt[a[i]]*(j+1);
        } else if (a[i] == b[j]) {
            ans += i+1;
        }
        
        ans += rightB[a[i]];
        ans += leftB[a[i]];
    }
    return ans;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) {
        cin >> a[i]; a[i]--;
    }
    for(int i=0; i<n; i++) {
        cin >> b[i]; b[i]--;
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        if (a[i] == b[i]) {
            ans += i*(i+1)/2;
            ans += (n-i)*(n-i-1)/2;
        }
    }
    int add = solve(a, b);
    ans += add;
    cout << ans;
    return 0;
}
