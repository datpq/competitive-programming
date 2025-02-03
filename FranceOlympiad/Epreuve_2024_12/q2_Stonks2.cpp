#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, s; cin >> n >> s;
    vector<int> prefixMin(n), v(n); 
    for(int i=0; i<n; i++) cin >> v[i];
    prefixMin[n-1]=v[n-1];
    for(int i=n-2; i>=0; i--) prefixMin[i]=min(prefixMin[i+1], v[i]);
    int ans=0, cur=0;
    for(int i=0; i<n; i++) {
        cur+=s;
        ans += cur/prefixMin[i];
        cur%=prefixMin[i];
    }
    cout << ans;
    return 0;
}
