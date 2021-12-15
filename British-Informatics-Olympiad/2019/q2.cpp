#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
deque<pair<int, int>> tracks;
int X, Y; int FaceX, FaceY;
int t;

bool move(char ins) {
	X += FaceX; Y += FaceY;
	tracks.push_front({ X, Y });
	int count = 0;
	do {
		count++;
		if (count > 1) ins = 'R';
		if (ins == 'L') {
			int tmp = FaceX;
			FaceX = FaceX == 0 ? -FaceY : 0;
			FaceY = FaceY == 0 ? tmp : 0;
		}
		else if (ins == 'R') {
			int tmp = FaceX;
			FaceX = FaceX == 0 ? FaceY : 0;
			FaceY = FaceY == 0 ? -tmp : 0;
		}
	} while (find(tracks.begin(), tracks.end(), make_pair( X + FaceX, Y + FaceY )) != tracks.end() && count<=4);
	if (tracks.size() >= t) tracks.pop_back();
	return count <= 4;
}

int main() {
	while (true) {
		int m; string instructions; cin >> t >> instructions >> m;
		tracks.clear();
		X = 0; Y = -1; FaceX = 0; FaceY = 1;
		bool stop = false;
		for (int i = 0; i < m; i++) {
			if (!move(instructions[i % instructions.length()])) {
				stop = true;
				break;
			}
		}
		if (!stop) {
			X += FaceX; Y += FaceY;
		}
		cout << '(' << X << ',' << Y << ')' << endl;
	}
	return 0;
}