//2021 R2 11
#include <iostream>

using namespace std;

void printBoard(char board[8][8]) {
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void initializeBoard(char board[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((j % 2 == 0 && (i == 0 || i == 2)) || (j % 2 == 1 && i == 1)) {
				board[i][j] = 'w';
			}
			else if ((j % 2 == 1 && (i == 5 || i == 7)) || (j % 2 == 0 && i == 6)) {
				board[i][j] = 'b';
			}
			else {
				board[i][j] = '.';
			}
		}
	}
}

void move(char board[8][8]) {
	char x, y, z; cin >> x >> y >> z;
	int j = x - 'a'; int i = y - '1';
	
	char myColor = board[i][j];
	char otherColor = myColor == 'w' ? 'b' : 'w';
	bool whiteMove = myColor == 'w';
	int directionI = whiteMove ? 1 : -1;
	int directionJ = whiteMove ? (z == 'R' ? 1 : -1) : (z == 'R' ? -1 : 1);
	if (board[i + directionI][j + directionJ] == otherColor) {
		board[i + directionI][j + directionJ] = '.';
		board[i + 2* directionI][j + 2 * directionJ] = myColor;
	}
	else {
		board[i + directionI][j + directionJ] = myColor;
	}
	board[i][j] = '.';
}

int main() {
	char board[8][8];
	initializeBoard(board);

	int n; cin >> n;
	while (n--) {
		move(board);
	}

	printBoard(board);
	return 0;
}