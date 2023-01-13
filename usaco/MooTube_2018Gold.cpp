#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

struct Qry {
    int k, node, index, ans;
};

bool compByK(Qry a, Qry b) {
    return a.k < b.k;
};

bool compByIdx(Qry a, Qry b) {
    return a.index < b.index;
};

signed main() {
    ifstream ifs("mootube.in");
    ofstream ofs("mootube.out");
    int n, q; ifs >> n >> q;
    vector<tuple<int, int, int>> edges;
    for(int i=0; i<n-1; i++) {
        int a, b, c; ifs >> a >> b >> c; a--; b--;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());

    vector<Qry> queries;
    for(int i=0; i<q; i++) {
        int k, node; ifs >> k >> node; node--;
        queries.push_back({k, node, i, 0});
    }
    sort(queries.begin(), queries.end(), compByK);
    DSU dsu(n);
    int edgeIdx = n-2;
    for(int i=q-1; i>=0; i--) {
        while(edgeIdx >= 0 && get<0>(edges[edgeIdx]) >= queries[i].k) {
            auto [c, a, b] = edges[edgeIdx];
            dsu.unite(a, b);
            edgeIdx--;
        }
        queries[i].ans = dsu.size(queries[i].node)-1;
    }
    sort(queries.begin(), queries.end(), compByIdx);
    for(auto qry: queries) ofs << qry.ans << "\n";
    return 0;
}
