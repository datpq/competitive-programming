#include <bits/stdc++.h>

using namespace std;
int n;
vector<string> questions;
int cnt = 0;

int ask(string &q) {
    cout << "? " << q << endl;
    int ans; cin >> ans;
    return ans;
}

void respond(int a, int b) {
    cout << "! " << a << ' ' << b << endl;
}

bool check(int mid, vector<int> &indices) {
    string q(n, '0');
    for(int i=0; i<=mid; i++) {
        q[indices[i]] = '1';
    }
    int ans = ask(q);
    return ans % 2 == 1;
}

int firstTrue(int lo, int hi, vector<int> &indices) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, indices)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int getIndex(string &q, char c) {
    vector<int> indices;
    for(int i=0; i<n; i++) {
        if (q[i] == c) indices.push_back(i);
    }
    int idx = firstTrue(0, indices.size() - 1, indices);
    return indices[idx];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string row(n, ' ');
    for(int k=0; k<15; k++) {
        for(int i=0; i<n; i++) {
            row[i] = (i % (1<<(k+1)) < (1<<k)) ? '1' : '0';
        }
        questions.push_back(row);
    }
    for(int i=0; i<questions.size(); i++) {
        int ans = ask(questions[i]);
        if (ans % 2 == 0) continue;
        int idxA = getIndex(questions[i], '0');
        string q = questions[i];
        for(int j=i-1; j>=0; j--) {
            char c = questions[j][idxA];
            for(int k=0; k<n; k++) {
                if (questions[j][k] != c) {
                    q[k] = '0';
                }
            }
        }
        int idxB = getIndex(q, '1');
        respond(idxA, idxB);
        break;
    }
    return 0;
}
