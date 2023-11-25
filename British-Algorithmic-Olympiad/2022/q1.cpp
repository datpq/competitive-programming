#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define eb emplace_back
#define f first
#define s second

using namespace std;

using Node = pair<int, int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool subTask1 = true, subTask2 = true, subTask3 = true;
    if (subTask1) {
        // int t; cin >> t;
        // while(t--) {
            string shift, check; cin >> shift >> check;
            int L = shift.length();
            int r; cin >> r; r%=L;
            bool positive = r > 0; r=abs(r);
            for(int i=0; i<L; i++) {
                int ci = check[i]-'0';
                int lastIdx = positive ? (r*(i+1)-1)%L : (L-r*(i+1)-1)%L;
                if (lastIdx<0) lastIdx+=L;
                int s0 = shift[(lastIdx+1)%L] - '0';
                int s1 = shift[lastIdx] - '0';
                ci ^= s0 ^ s1;
                cout << ci;
            }
            cout << "\n";
        // }
    }
    if (subTask2) {
        cout << "B: I, II, IV\n";
    }
    if (subTask3) {
        int L = pow(2, 23);
        cout << "C: " << L*(L-1)/2 << "\n";
    }
    return 0;
}
