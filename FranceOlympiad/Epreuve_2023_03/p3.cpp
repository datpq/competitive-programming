#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INFINI = 1e18;
const int MAX_N = 505;
int numero[MAX_N][MAX_N];
vector<pair<int, int>> posByNum[MAX_N * MAX_N];
vector<int> minCoutLig;
vector<int> minCoutCol;
int cote, maxNum;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> cote >> maxNum;
	minCoutLig.assign(cote, INFINI);
	minCoutCol.assign(cote, INFINI);
	for (int lig = 0; lig < cote; ++lig) {
		for (int col = 0; col < cote; ++col) {
			cin >> numero[lig][col];
			--numero[lig][col]; // 0-index
			if (numero[lig][col] == 0) {
				minCoutLig[lig] = 0;
				minCoutCol[col] = 0;
			}
			posByNum[numero[lig][col]].emplace_back(lig, col);
		}
	}

	int ans = INFINI;
	for (int num = 0; num < maxNum; ++num) {
		// Je connais les couts des cases de numero k (par lig et col)
		// Je veux calculer les couts de k+1
		
		vector<int> nvLig(cote, INFINI), nvCol(cote, INFINI);
		for (auto situSuivante : posByNum[num+1]) { // f(k+1) tours
			int ligSuiv = situSuivante.first, colSuiv = situSuivante.second;
			// L'effort pour sauter d'une case aux coordonnées (x1, y1) à une case aux coordonnées (x2, y2)
			// vaut exactement min((x1 - x2)2, (y1 - y2)2)

			int bestTransition = INFINI;
			// Ici on essaie que la transition (x1-x2)^2
			for (int oldLig = 0; oldLig < cote; ++oldLig) {
				int delta = (ligSuiv - oldLig) * (ligSuiv - oldLig);
				bestTransition = min(bestTransition,
					minCoutLig[oldLig] + delta);			
			}

			// Ici on essaie que la transition (y1-y2)^2
			for (int oldCol = 0; oldCol < cote; ++oldCol) {
				int delta = (colSuiv - oldCol) * (colSuiv - oldCol);
				bestTransition = min(bestTransition,
					minCoutCol[oldCol] + delta);	
			}

			nvLig[ligSuiv] = min(
				nvLig[ligSuiv], // init a +inf
				bestTransition // tr. de lig ou col
			);

			nvCol[colSuiv] = min(
				nvCol[colSuiv],
				bestTransition // tr. de lig ou col
			);

			if (numero[ligSuiv][colSuiv] == maxNum-1) {
				ans = min(ans, bestTransition);
			}
		}
		minCoutLig = nvLig;
		minCoutCol = nvCol;
	}
	if (ans == INFINI) {
		ans = -1;
	}
	if (maxNum == 1) {
		ans = 0;
	}
	cout << ans << '\n';
}
