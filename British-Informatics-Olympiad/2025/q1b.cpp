#include <bits/stdc++.h>

using namespace std;

bool isPalindrom(int n) {
    if (n%10 == 0) return false;
    string s = to_string(n);
    for(int i=0; i<s.length()/2; i++) if (s[i] != s[s.length()-1-i]) return false;
    return true;
}

void pali(int n) {
    if (isPalindrom(n)) {
        cout << n << '\n';
    }

    for(int i=1; i<=n/2; i++) {
        if (isPalindrom(i) && isPalindrom(n-i)) {
            cout << i << ' ' << n-i << '\n';
        }
    }

    for(int i=1; i<=n/3; i++) {
        if (!isPalindrom(i)) continue;
        int m = n-i;
        for(int j=i; j<=m/2; j++) {
            if (isPalindrom(j) && isPalindrom(m-j)) {
                cout << i << ' ' << j << ' ' << m-j << '\n';
            }
        }
    }
}

int main() {
    //b
    pali(54);
    return 0;
}