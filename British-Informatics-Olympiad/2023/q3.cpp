#include <bits/stdc++.h>

using namespace std;

using Node = vector<string>;
const int N = 4;

vector<Node> adj(Node node) {
    vector<Node> ans;
    for(int i=0; i<N; i++) {
        if (node[i] == "") continue;
        for(int j=0; j<N; j++) {
            if (j==i) continue;
            Node child;
            for(int k=0; k<N; k++) {
                if (k==i) child.push_back(node[i].substr(0, node[i].size()-1));
                else if (k==j) child.push_back(node[j] + node[i].back());
                else child.push_back(node[k]);
            }
            ans.push_back(child);
        }
    }
    return ans;
}

void clear(queue<Node> &q) {
    queue<Node> empty;
    swap( q, empty );
}

int compute(vector<int> &pegs, int idx, int rem) {
    if (idx==8) return rem==0?1:0;
    int ans = 0;
    for(int i=0; i<=min(rem, pegs[idx]); i++) {
        ans += compute(pegs, idx+1, rem-i);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool subTaskA=true, subTaskB=true, subTaskC=true, subTaskD=true;

    set<Node> vis;
    map<Node, int> dis;
    queue<Node> q;
    bool found = false;

    if (subTaskA) {
        // for(int cnt=0; cnt<12; cnt++) {
        Node src(4), dest(4);
        for(auto &x: src) { cin >> x; if (x=="0") x=""; }
        for(auto &x: dest) { cin >> x; if (x=="0") x=""; }
        vis.clear(); dis.clear(); clear(q); found = false;
        vis.insert(src);
        q.push(src);
        while(!q.empty() && !found) {
            Node node=q.front(); q.pop();
            if (node == dest) break;
            for(auto child: adj(node)) {
                if (vis.count(child)) continue;
                dis[child] = dis[node]+1;
                q.push(child);
                vis.insert(child);
            }
        }
        cout << dis[dest] << endl;
        // }
    }
    if (subTaskB) {
        Node src = {"1", "2", "3", "4"};
        vis.clear(); dis.clear(); clear(q);
        vis.insert(src);
        q.push(src);
        while(!q.empty()) {
            Node node=q.front(); q.pop();
            for(auto child: adj(node)) {
                if (vis.count(child)) continue;
                dis[child] = dis[node]+1;
                q.push(child);
                vis.insert(child);
            }
        }
        int ans = 0;
        for(auto &x: vis) {
            if (adj(x).size()==9) {
                ans++;
            }
        }
        cout << "B. " << ans << endl;
        //cout << "B. " << 4*4*6*3 << endl;
    } if (subTaskC) {
        Node src = {"1", "2", "3", "4"};
        vis.clear(); dis.clear(); clear(q);
        vis.insert(src);
        q.push(src);
        while(!q.empty()) {
            Node node=q.front(); q.pop();
            if (dis[node] == 4) break;
            for(auto child: adj(node)) {
                if (vis.count(child)) continue;
                dis[child] = dis[node]+1;
                q.push(child);
                vis.insert(child);
            }
        }
        int cnt2=0, cnt4=0;
        for(auto x: dis) {
            if (x.second <= 2) cnt2++;
            if (x.second <= 4) cnt4++;
        }
        cout << "C. After 2 moves: " << cnt2 << endl;
        cout << "C. After 4 moves: " << cnt4 << endl;
    }
    if (subTaskD) {
        for(int i=0; i<(1<<24); i++) {
            vector<int> pegs(8);
            bool inOrder = true;
            for(int j=0; j<8; j++) {
                int h=1;
                h += ((i>>(3*j+0)&1) << 0);
                h += ((i>>(3*j+1)&1) << 1);
                h += ((i>>(3*j+2)&1) << 2);
                pegs[j] = h;
                if (j && pegs[j]<pegs[j-1]) inOrder = false;
            }
            if (!inOrder) continue;
            if (compute(pegs, 0, 8) == 2023) {
                for(auto &x: pegs) cout << x << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
