#include <bits/stdc++.h>

using namespace std;

signed main() {
    int N, K; cin >> N >> K;
    vector<int> v(N+1, 0);
    for(int i=0; i<K; i++) {
        int a, b; cin >> a >> b;
        v[a]++; if (b<N) v[b+1]--;
    }
    vector<int> freq(K+1, 0);
    for(int i=0; i<N; i++) {
        v[i+1]+=v[i];
        freq[v[i+1]]++;
    }
    int cnt = 0;
    for(int i=0; i<=K; i++) {
        cnt+=freq[i];
        if (cnt > N/2) {
            cout << i;
            return 0;
        }
    }
    return 0;
}
