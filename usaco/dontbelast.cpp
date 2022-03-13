#include <fstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
	ifstream ifs("notlast.in");
	ofstream ofs("notlast.out");
	int t; ifs >> t;
	map<string, int> m = {
		{"Bessie", 0},
		{"Elsie", 0},
		{"Daisy", 0},
		{"Gertie", 0},
		{"Annabelle", 0},
		{"Maggie", 0},
		{"Henrietta", 0}
	};
	while (t--) {
		string name; int n; ifs >> name >> n;
		m[name] += n;
	}
	vector<pair<int, string>> v;
	for (auto& x : m) v.push_back({ x.second, x.first });
	sort(v.begin(), v.end());

	for (int i = 1; i < v.size(); i++) {
		if (v[i].first != v[0].first) {
			if (i == v.size() - 1 || v[i].first != v[i + 1].first) {
				ofs << v[i].second << endl;
				return 0;
			}
			else break;
		}
	}
	ofs << "Tie" << endl;
	return 0;
}