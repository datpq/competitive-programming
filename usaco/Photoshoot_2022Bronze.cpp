#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1]) v.push_back(s[i] == 'G' ? -1 : 1);
    }
    int ans = 0;
    int idx = v.size() - 1;
    while (v[idx] == 1) idx--;
    while (idx >= 0) {
        while (idx > 0 && v[idx] == v[idx - 1]) idx--;
        ans++;
        idx--;
    }
    cout << ans;
    return 0;
}
