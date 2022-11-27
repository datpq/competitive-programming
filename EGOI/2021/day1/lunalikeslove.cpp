#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
vector<int> tree;
int N;
 
long long sum(int k) {
    long long s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}
 
void add(int k, int x) {
    while (k <= N) {
        tree[k] += x;
        k += k&-k;
    }
}
 
int main() {
    int n; cin >> n; N=2*n;
    vector<int> v(N+1);
    vector<pair<int, int>> couples(n+1, make_pair(0,0));
    tree = vector<int>(N+1, 0);
    for(int i=1; i<=N; i++) {
        cin >> v[i];
        if (couples[v[i]].first) couples[v[i]].second = i; else couples[v[i]].first = i;
    }
 
    long long ans = 0;
    for(int i=1; i<=N; i++) {
        if (couples[v[i]].first == i) add(i, 1);
        else {
            add(couples[v[i]].first, -1);
            ans+=sum(couples[v[i]].second) - sum(couples[v[i]].first);
        }
    }
    cout << ans+n;
    return 0;
}
