#include <iostream>

using namespace std;
const int N = 4;

int arr[N][N];
int solve(int i, int j, int who) {
	int ans = 0;
	if (i + 2 < N && arr[i][j] == who && arr[i + 1][j] == who && arr[i + 2][j] == who) ans++;
	if (j + 2 < N && arr[i][j] == who && arr[i][j + 1] == who && arr[i][j + 2] == who) ans++;
	if (i + 2 < N && j + 2 < N && arr[i][j] == who && arr[i + 1][j + 1] == who && arr[i + 2][j + 2] == who) ans++;
	if (i + 2 < N && j - 2 >= 0 && arr[i][j] == who && arr[i + 1][j - 1] == who && arr[i + 2][j - 2] == who) ans++;
	return ans;
}

int main() {
	int who = 1;
	for (int i = 0; i < N*N; i++) {
		char c, r; cin >> c >> r;
		arr[c - 'a'][r - '1'] = who;
		who = -who;
	}
	int score1 = 0, score2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			score1 += solve(i, j, 1);
			score2 += solve(i, j, -1);
		}
	}
	cout << score1 << '-' << score2;
	return 0;
}