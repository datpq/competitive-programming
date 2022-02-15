#include <iostream>

using namespace std;

bool solve(int X, int Y) {
	int n; cin >> n;
	int arrX[50], arrY[50];
	for (int i = 0; i < n; i++) cin >> arrX[i] >> arrY[i];
	bool positiveFound = false;
	bool negativeFound = false;
	for (int i = 0; i < n; i++) {
		if (Y * arrX[i] == X * arrY[i]) return true;
		else if (Y * arrX[i] > X * arrY[i]) positiveFound = true;
		else negativeFound = true;
		if (negativeFound && positiveFound) return true;
	}
	return false;
}

int main() {
	int X, Y; cin >> X >> Y;
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		if (solve(X, Y)) cout << i << endl;
	}
	return 0;
}