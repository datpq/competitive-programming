#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

#define MAX_N2 10

using namespace std;

int visit(int room, vector<pair<int, bool>> connected[MAX_N2], bool oddTimesVisited[MAX_N2]) {
	oddTimesVisited[room] = !oddTimesVisited[room]; // parity of number of times visited
	if (oddTimesVisited[room]) {
		auto & ans = connected[room].front();
		ans.second = !ans.second; // parity of number of times left through this exit
		return ans.first; // return next room
	}
	else {
		for (int i = 0; i < connected[room].size(); i++) {
			if (connected[room][i].second) {
				auto & ans = i == connected[room].size() - 1 ? connected[room][i] : connected[room][i + 1];
				ans.second = !ans.second;
				return ans.first;
			}
		}
		auto& ans = connected[room].front();
		ans.second = !ans.second;
		return ans.first;
	}
}

int main() {
	//while (true) {

	string plan; cin >> plan;
	int n2 = plan.length() + 2;
	int p, q; cin >> p >> q;

	bool chosen[MAX_N2];
	memset(chosen, false, n2*sizeof(chosen[0]));
	bool oddTimesVisited[MAX_N2];
	memset(oddTimesVisited, false, n2 * sizeof(oddTimesVisited[0]));

	vector<pair<int, bool>> connected[MAX_N2]; // pair of exit and the parity, false for odd.
	string currentPlan = plan;
	for (int i = 0; i < n2; i++) {
		if (!chosen[i] && currentPlan.find(i + 'A') == string::npos) {
			connected[i].push_back({ currentPlan[0] - 'A', false});
			connected[currentPlan[0] - 'A'].push_back({ i, false });
			chosen[i] = true;
			i = -1; // restart from beginning
			currentPlan = currentPlan.substr(1, currentPlan.length() - 1);
			if (currentPlan == "") break;
		}
	}

	// 2 room left, need to be connected to each other
	int secondLastIdx = -1;
	for (int i = 0; i < n2; i++) {
		if (!chosen[i]) {
			if (secondLastIdx == -1) {
				secondLastIdx = i;
			} else {
				connected[secondLastIdx].push_back({ i, false });
				connected[i].push_back({ secondLastIdx, false });
				break;
			}
		}
	}

	for (int i = 0; i < n2; i++) {
		sort(connected[i].begin(), connected[i].end());
		for (auto& x : connected[i]) {
			cout << (char)(x.first + 'A');
		}
		cout << endl;
	}

	int move = 0;
	int room = 0;
	while (move < q) {
		room = visit(room, connected, oddTimesVisited);
		move++;
		if (move == p || move == q) cout << (char)(room + 'A');
	}
	cout << endl;

	//}

	return 0;
}