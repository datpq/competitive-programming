#include <bits/stdc++.h>
using namespace std;

struct Retour {
	bool has_beacon;
	int nb_needed;
};

int nbCities, nbBeacons;
vector<bool> isBeacon;
vector<vector<int>> neighbors;

Retour solve(int u, int parent = -1) {
	vector<Retour> rets;
	for(int v : neighbors[u]) {
		if(v == parent) continue;
		rets.push_back(solve(v, u));
	}
	
	if(rets.empty()) {
		return {isBeacon[u], 0};
	}
	else if(rets.size() == 1) {
		return {isBeacon[u] || rets[0].has_beacon, rets[0].nb_needed};
	}
	else {
		int sum_needed = 0;
		int nbWith = 0;
		
		for(Retour r : rets) {
			sum_needed += r.nb_needed;
			if(r.has_beacon) nbWith++;
		}
		
		sum_needed += max(0, (int)rets.size() - 1 - nbWith);
		
		return {true, sum_needed};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> nbCities >> nbBeacons;
	
	isBeacon = vector<bool>(nbCities, false);
	for(int iBeacon = 0;iBeacon < nbBeacons;iBeacon++) {
		int city;
		cin >> city; city--;
		isBeacon[city] = true;
	}
	
	neighbors.resize(nbCities);
	for(int iEdge = 0;iEdge < nbCities - 1;iEdge++) {
		int u, v;
		cin >> u >> v; u--; v--;
		neighbors[u].push_back(v);
		neighbors[v].push_back(u);
	}
	
	int root = -1;
	bool extrBeacon = false;
	for(int u = 0;u < nbCities;u++) {
		if(neighbors[u].size() >= 3) root = u;
		if(neighbors[u].size() == 1 && isBeacon[u]) extrBeacon = true;
	}
	
	if(root != -1) {
		cout << solve(root).nb_needed << endl;
	}
	else {
		if(nbBeacons >= 2 || extrBeacon) cout << 0 << endl;
		else cout << 1 << endl;
	}
	return 0;
}
