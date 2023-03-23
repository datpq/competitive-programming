#include <bits/stdc++.h>
#define int long long
#define sz(v) ((int)((v).size()))
using namespace std;

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int nbProm, nbVoisins, mode;
    cin >> nbProm >> nbVoisins >> mode;

    int curAns = 0;
    vector<int> _makeBlues(nbProm+1);
    vector<vector<pair<int, int>>> _makeJazz(nbProm+1);
    int firstJazz = 1e9;
    vector<pair<int, int>> saveQuery(nbVoisins);
    for (int iVoi = 0; iVoi < nbVoisins; ++iVoi) {
        int chien, lo, ri;
        cin >> chien >> lo >> ri;
        --lo; --ri;
        saveQuery[iVoi] = {lo, ri};
        if (chien == 0) {
            curAns += ri - lo + 1;
            ++_makeBlues[lo], --_makeBlues[ri+1];
            cout << curAns << '\n';
        } else {
            firstJazz = min(firstJazz, iVoi);
            _makeJazz[lo].push_back({iVoi, 1});
            _makeJazz[ri+1].push_back({iVoi, -1});
        }
    }
    vector<int> blues(nbProm);
    {
        int cur = 0;
        for (int iProm = 0; iProm < nbProm; ++iProm) {
            cur += _makeBlues[iProm];
            blues[iProm] = cur;
        }
    }
    vector<vector<int>> becomeJazz(nbVoisins);
    FT isJazz(nbProm+5);
    {
        FT ordSet(nbVoisins + 5);
        for (int iProm = 0; iProm < nbProm; ++iProm) {
            for (auto r : _makeJazz[iProm]) {
                ordSet.update(r.first, r.second);
            }
            int iVoi = ordSet.lower_bound(blues[iProm]);
            if (iVoi < firstJazz) {
                isJazz.update(iProm, 1);
            } else if (iVoi < nbVoisins) {
                becomeJazz[iVoi].push_back(iProm);
            }
        }
    }
    for (int iVoi = firstJazz; iVoi < nbVoisins; ++iVoi) {
        int lo = saveQuery[iVoi].first, ri = saveQuery[iVoi].second;
        curAns += isJazz.query(ri+1) - isJazz.query(lo);
        for (int prom : becomeJazz[iVoi]) {
            isJazz.update(prom, 1);
        }
        cout << curAns << '\n';
    }
}
