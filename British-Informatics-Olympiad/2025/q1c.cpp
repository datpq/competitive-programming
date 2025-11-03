#include <bits/stdc++.h>

using namespace std;

vector<int> allPalin;
bool isPalindrom(int n) {
    if (n%10 == 0) return false;
    string s = to_string(n);
    for(int i=0; i<s.length()/2; i++) if (s[i] != s[s.length()-1-i]) return false;
    return true;
}

map<int, vector<int>> mp;
vector<int> pali(int n) {
    if (isPalindrom(n)) {
        return {n};
    } else if (mp.count(n)) {
        return mp[n];
    } else {
        for(int i=1; i<=n/3; i++) {
            if (!isPalindrom(i)) continue;
            int m = n-i;
            if (mp.count(m) && mp[m][0]>=i) {
                vector<int> ans = mp[m];
                ans.insert(ans.begin(), i);
                return ans;
            }
        }
    }
    return {};
}

int main() {
    //c
    for(int i=1; i<1e6; i++) {
        if (isPalindrom(i)) allPalin.push_back(i);
    }
    for(int i=0; i<allPalin.size(); i++) {
        for(int j=i; j<allPalin.size(); j++) {
            if (mp.count(allPalin[i] + allPalin[j])) continue;
            mp[allPalin[i] + allPalin[j]] = {allPalin[i], allPalin[j]};
        }
    }
    int cnt = 0;
    for(int i=1; i<=1e6; i++) {
        auto ans = pali(i);
        if (ans.size() == 3) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}