#include <iostream>
#include <vector>

int payRate(char c) {
	return c == 'A' ? 4 : c == 'K' ? 3 : c == 'Q' ? 2 : c == 'J' ? 1 : 0;
}

using namespace std;

int main() {
	string sX, sY; int n; cin >> sX >> sY >> n;
	vector<char> X(sX.begin(), sX.end()), Y(sY.begin(), sY.end()), pile;
	bool Xturn = true; // true X, false Y
	while (n--) {
		int numOfCard = 1;
		bool isPaying = false;
		while((Xturn && X.size()) || (!Xturn && Y.size())) {
			numOfCard--;
			char card = Xturn ? X[0] : Y[0];
			if (Xturn) X.erase(X.begin()); else Y.erase(Y.begin());
			pile.push_back(card);
			if (payRate(card) > 0) {
				Xturn = !Xturn;
				numOfCard = payRate(card);
				isPaying = true;
			}
			else if (numOfCard == 0) {
				Xturn = !Xturn;
				numOfCard = 1;
				if (isPaying) {
					if (Xturn)
						X.insert(X.end(), pile.begin(), pile.end());
					else
						Y.insert(Y.end(), pile.begin(), pile.end());
					pile.clear();
					break;
				}
			}
		}
	}
	for (auto& c : X) cout << c;
	return 0;
}