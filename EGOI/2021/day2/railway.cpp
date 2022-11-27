#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    long long s; cin >> s; s*=2;
    int t, m, n; cin >> t >> m >> n;
    vector<pair<long long, int>> vt(2*t);
    for(int i=0; i<2*t; i+=2) {
        cin >> vt[i].first; vt[i].first *= 2;
        vt[i].second = 1;//tunnel start
    }
    for(int i=1; i<2*t; i+=2) {
        cin >> vt[i].first; vt[i].first *= 2;
        vt[i].second = 2;//tunnel end
    }
    vector<long long> c(m), d(n);
    for(int i=0; i<m; i++) { cin >> c[i]; c[i] *= 2; }
    for(int i=0; i<n; i++) { cin >> d[i]; d[i] *= 2; }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if (abs(d[j]-c[i]) >= s) continue;
            long long meeting = (d[j]-c[i]+s)/2;
            auto it = lower_bound(vt.begin(), vt.end(), make_pair(meeting, 0));
            if (it == vt.end() || it->first == meeting) continue;;
            if (it->second == 2) {
                cout << "YES"; return 0;
            }
        }
    }
 
    // int idx=0;
    // for(int i=0; i<m; i++) {
    //     while(idx < n && abs(d[idx]-c[i]) >= s) idx++;
    //     for(int j=idx; j<n; j++) {
    //         if (abs(d[j]-c[i]) >= s) break;
    //         long long meeting = (d[j]-c[i]+s)/2;
    //         auto it = lower_bound(vt.begin(), vt.end(), make_pair(meeting, 0));
    //         if (it == vt.end() || it->first == meeting) continue;;
    //         if (it->second == 2) {
    //             cout << "YES"; return 0;
    //         }
    //     }
    // }
    cout << "NO";
    return 0;
}
