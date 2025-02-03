#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end()); 
    int mid = 0;
    for(int i=0; i<n; i++) mid+=v[i];
    mid/=2;
    int ans=0;
    for(int i=0; i<n; i++) {
        vector<int> dp(mid+1, 0); dp[0]=1;
        for(int j=i+1; j<n; j++) {
            for(int k=mid; k-v[j]>=0; k--) {    
                if(dp[k-v[j]]) dp[k]+=dp[k-v[j]];
            }
        }
        for(int j=mid-v[i]+1; j<=mid; j++) ans+=dp[j];
    }
    cout << ans;
    return 0;
}