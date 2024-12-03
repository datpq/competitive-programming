#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif
    const int LINES=6;
    std::regex pattern("mul\\((\\d+),(\\d+)\\)");

    int ans = 0;
    for(int i=0; i<LINES; i++)
    {
        string s; getline(cin, s);
        auto begin = std::sregex_iterator(s.begin(), s.end(), pattern);
        auto end = std::sregex_iterator();

        while (begin != end) {
            std::smatch match = *begin;

            if (match.size() >= 3) {
                int a = stoi(match[1]);
                int b = stoi(match[2]);
                ans += a*b;
            }

            ++begin; // Move to the next match
        }
    }
    cout << ans;
    return 0;
}