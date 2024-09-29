#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<pair<string, int>> v;

bool compareByPoints(pair<string, int> &x, pair<string, int> &y) {
	// return x.second * y.first.length() > y.second * x.first.length();
	return (x.second > y.second) ||
		(x.second == y.second && x.first.length() < y.first.length());
	// return x.second > y.second;
}
bool compareByLenDesc(pair<string, int> &x, pair<string, int> &y) {
	// return x.second * y.first.length() > y.second * x.first.length();
	return x.first.length() > y.first.length();
}

int countOccurences(string &s, string &sub) {
	int ans = 0, idx = -1;
	while((idx = s.find(sub, idx+1)) != -1) ans++;
	return ans;
}

string nouveauMot() {
	sort(v.begin(), v.end(), compareByLenDesc);
	for(int i=0; i<m; i++) {
		// for(int j=i+1; j<m; j++) {
		// 	if (v[i].first.find(v[j].first) != -1) {
		// 		v[i].second += v[j].second;
		// 	}
		// }
		for(int j=m-1; j>i; j--) {
			int cnt = countOccurences(v[i].first, v[j].first);
			v[i].second += cnt*v[j].second;
		}
	}
	sort(v.begin(), v.end(), compareByPoints);
	string s(n, 'A');
	int idxS = 0, idxM = 0;
	while (idxS < n) {
		while(idxM < m && v[idxM].first.length() + idxS > n) idxM++;
		//while(idxM < m-1 && (n-idxS)/v[idxM].first.length()*v[idxM].second < (n-idxS)/v[idxM+1].first.length()*v[idxM+1].second) idxM++;		
		if (idxM == m) break;
		for(int i=0; i<v[idxM].first.length(); i++) {
			s[idxS+i] = v[idxM].first[i];
		}
		idxS += v[idxM].first.length();
	}
	return s;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	// #ifndef ONLINE_JUDGE 
	// 	freopen("input.txt", "r", stdin); 
	// 	freopen("output.txt", "w", stdout); 
	// #endif
	cin >> n >> m;
	v.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	cout << nouveauMot() << endl;
	return 0;
}
