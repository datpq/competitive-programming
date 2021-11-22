//2021 R2 12
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>
#include <unordered_set>
#include <set>

using namespace std;

vector<tuple<int, int, int>> schedules[10000];
const int START_MIN = 5*60;
int earliest = INT_MAX;
int n;
set<pair<int, int>> alreadyPassed;

string intToTime(int t) {
	string hour = ("0" + to_string(t / 60)); hour = hour.substr(hour.length() - 2, 2);
	string minute = ("0" + to_string(t % 60)); minute = minute.substr(minute.length() - 2, 2);
	return hour + ":" + minute;
}

void DFS(int start, int currentTime) {
	if (start == n) return;
	if (alreadyPassed.count({ start, currentTime }) == 1) return;
	alreadyPassed.insert({ start, currentTime });
	unordered_set<int> seen;
	for(auto it : schedules[start]) {
		int endTime = get<0>(it);
		int startTime = get<1>(it);
		int destination = get<2>(it);

		if (endTime >= earliest) break;
		if (seen.count(destination) == 1) continue;
		if (startTime >= currentTime + 3) {
			if (destination == n) {
				earliest = endTime;
			}
			else {
				seen.insert(destination);
				DFS(destination, endTime);
			}
		}
	}
}

int main() {
	int Q; cin >> n >> Q;
	while (Q--) {
		int start, end; cin >> start >> end;
		int hour, minute; char c; cin >> hour >> c >> minute;
		int nStartTime = hour * 60 + minute;
		cin >> hour >> c >> minute;
		int nEndTime = hour * 60 + minute;
		if (nStartTime < START_MIN) continue;
		tuple<int, int, int> sch = { nEndTime, nStartTime, end };
		auto it = upper_bound(schedules[start].begin(), schedules[start].end(), sch);
		schedules[start].insert(it, sch);
	}

	DFS(1, START_MIN);
	cout << intToTime(earliest);

	return 0;
}