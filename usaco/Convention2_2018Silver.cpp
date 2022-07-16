#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

struct Edge {
	int Seniority;
	int Arrive;
	int EatingTime;
};
bool operator<(const Edge& x, const Edge& y) { return x.Seniority > y.Seniority; }

bool comp(const Edge &e1, const Edge &e2) { return e1.Arrive < e2.Arrive; }

int main() {
	ifstream ifs("convention2.in");
	ofstream ofs("convention2.out");
	int n; ifs >> n;
	vector<Edge> v(n);
	for (int i = 0; i < n; i++) {
		v[i].Seniority = i + 1;
		ifs >> v[i].Arrive >> v[i].EatingTime;
	}
	sort(v.begin(), v.end(), comp);
	int currentTime = 0;
	int idx = 0;
	int ans = 0;
	priority_queue<Edge> pq;
	while (!pq.empty() || idx < n) {
		if (pq.empty()) {
			currentTime = v[idx].Arrive;
		} else {
			const auto e = pq.top();
			pq.pop();
			ans = max(ans, currentTime - e.Arrive);
			currentTime = max(currentTime, e.Arrive) + e.EatingTime;
		}
		while (idx < n && v[idx].Arrive <= currentTime) {
			pq.push(v[idx]);
			idx++;
		}
	}
	ofs << ans;
	return 0;
}