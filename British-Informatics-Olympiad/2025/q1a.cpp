#include <bits/stdc++.h>

using namespace std;

bool isPalindrom(int n) {
    if (n%10 == 0) return false;
    string s = to_string(n);
    for(int i=0; i<s.length()/2; i++) if (s[i] != s[s.length()-1-i]) return false;
    return true;
}

vector<int> pali(int n) {
    if (isPalindrom(n)) {
        return {n};
    } else {
        for(int i=1; i<=n/2; i++) {
            if (isPalindrom(i) && isPalindrom(n-i)) {
                return {i, n-i};
            }
        }
        for(int i=1; i<=n/3; i++) {
            if (!isPalindrom(i)) continue;
            int m = n-i;
            for(int j=i; j<=m/2; j++) {
                if (isPalindrom(j) && isPalindrom(m-j)) {
                    return {i, j, m-j};
                }
            }
        }
    }
    return {};
}

int main() {
    //a
    // int t; cin >> t;
    // while(t--) {
    //     int n; cin >> n;
    //     auto ans = pali(n);
    //     for(auto x: ans) cout << x << ' ';
    //     cout << '\n';
    // }
    int n; cin >> n;
    auto ans = pali(n);
    for(auto x: ans) cout << x << ' ';
    cout << '\n';
    return 0;
}