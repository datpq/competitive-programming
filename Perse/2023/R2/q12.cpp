#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> visited;
vector<int> nxt, parent, ans;
int ans1 = 0, ans2 = 0;

void updateAns(int val, int delta = 1) {
    if (val > ans1) {
        ans1 = val; ans2 = delta;
    } else if (val == ans1) ans2+=delta;
}

void go(int node, int prev) {
    if (visited[node]) {
        if (ans[node]) {
            int cnt = ans[node];
            while (prev != -1) {
                ans[prev] = ++cnt; updateAns(cnt);
                prev = parent[prev];
            }
        } else {
            int tmpNode = prev;
            int cnt = 1;
            while (tmpNode != node) {
                tmpNode = parent[tmpNode];
                cnt++;
            }
            while (prev != node) {
                ans[prev] = cnt;
                prev = parent[prev];
            }
            ans[node] = cnt; updateAns(cnt, cnt);
            node = parent[node];
            while (node != -1) {
                ans[node] = ++cnt; updateAns(cnt);
                node = parent[node];
            }
        }
        return;
    }
    visited[node] = true;
    parent[node] = prev;
    go(nxt[node], node);
}

signed main() {
    cin >> n;
    nxt = vector<int>(n);
    visited = vector<bool>(n, false);
    for(int i=0; i<n; i++) {
        cin >> nxt[i]; nxt[i]--;
    }
    parent = vector<int>(n);
    ans = vector<int>(n, 0);
    for(int i=0; i<n; i++) {
        if (!visited[i]) go(i, -1);
    }
    cout << ans1 << "\n" << ans2;
    return 0;
}
