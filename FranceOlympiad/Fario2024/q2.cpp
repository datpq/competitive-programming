#include <bits/stdc++.h>
using namespace std;

const int INFINI = 1e9;

int nbRows, nbCols;
vector<vector<int>> matrix, val_avant, val_apres;

vector<pair<int, int>> intervals;

int max_sous[(1 << 21)];
int ajouts[(1 << 21)];

void push(int n) {
	max_sous[n] += ajouts[n];
	
	if(n < (1 << 20)) {
		ajouts[2 * n] += ajouts[n];
		ajouts[2 * n + 1] += ajouts[n];
	}
	
	ajouts[n] = 0;
}

int get_max(int deb, int fin, int n = 1, int d = 0, int f = (1 << 20)) {
	push(n);
	
	if(deb >= f || d >= fin) return 0;
	if(deb <= d && f <= fin) {
		return max_sous[n] + ajouts[n];
	}
	
	int m = (d + f) / 2;
	return max(
		get_max(deb, fin, 2 * n, d, m),
		get_max(deb, fin, 2 * n + 1, m, f)
	);
}

int add_inter(int deb, int fin, int ajout, int n = 1, int d = 0, int f = (1 << 20)) {
	push(n);
	
	if(deb >= f || d >= fin) return max_sous[n] + ajouts[n];
	if(deb <= d && f <= fin) {
		ajouts[n] += ajout;
		return max_sous[n] + ajouts[n];
	}
	
	int m = (d + f) / 2;
	
	max_sous[n] = max(
		add_inter(deb, fin, ajout, 2 * n, d, m),
		add_inter(deb, fin, ajout, 2 * n + 1, m, f)
	);
	
	return max_sous[n] + ajouts[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> nbRows >> nbCols;

	matrix = vector<vector<int>>(nbRows, vector<int>(nbCols, 0));
	val_avant = vector<vector<int>>(nbRows, vector<int>(nbCols, 1));
	val_apres = vector<vector<int>>(nbRows, vector<int>(nbCols, INFINI));
	
	for(int row = 0;row < nbRows;row++) {
		for(int col = 0;col < nbCols;col++) {
			cin >> matrix[row][col];
		}
	}
	
	for(int row = 0;row < nbRows;row++) {
		int last = 1;
		for(int col = 0;col < nbCols;col++) {
			if(matrix[row][col] != 0) {
				last = matrix[row][col];
			}
			val_avant[row][col] = last;
		}
	}
	
	for(int row = 0;row < nbRows;row++) {
		int last = INFINI;
		for(int col = nbCols - 1;col >= 0;col--) {
			if(matrix[row][col] != 0) {
				last = matrix[row][col];
			}
			val_apres[row][col] = last;
		}
	}
	
	vector<bool> row_inc(nbRows);
	int nbIncreasing = 0;
	
	for(int row = 0;row < nbRows;row++) {
		bool is_increasing = true;
		
		int last = 0;
		for(int col = 0;col < nbCols;col++) {
			if(matrix[row][col] != 0) {
				if(matrix[row][col] < last) {
					is_increasing = false;
					break;
				}
				last = matrix[row][col];
			}
		}
		
		row_inc[row] = is_increasing;
		if(is_increasing) nbIncreasing++;
	}
	
	vector<bool> can_constant(nbCols, true);
	
	int nbCanConstant = 0;
	for(int col = 0;col < nbCols;col++) {
		int last = 0;
		for(int row = 0;row < nbRows;row++) {
			if(matrix[row][col] != 0) {
				if(last != 0 && last != matrix[row][col]) {
					can_constant[col] = false;
					break;
				}
				last = matrix[row][col];
			}
		}
		
		if(can_constant[col]) {
			nbCanConstant++;
			
			int mini = 1, maxi = INFINI;
				
			for(int row = 0;row < nbRows;row++) {
				if(!row_inc[row] && matrix[row][col] == 0) continue;
				
				mini = max(mini, val_avant[row][col]);
				maxi = min(maxi, val_apres[row][col]);
			}
			
			if(mini <= maxi)
				intervals.push_back({mini, maxi});
		}
	}
	
	for(pair<int, int> inter : intervals) {
		//cerr << inter.first << " " << inter.second << endl;
		int maxi = get_max(0, inter.first + 1);
		int val = get_max(inter.first, inter.first + 1);
		
		add_inter(inter.first, inter.first + 1, maxi - val);
		add_inter(inter.first, inter.second + 1, 1);
	}
	
	if(nbIncreasing == 0) {
		cout << nbIncreasing << " " << nbCanConstant << endl;
	}
	else {
		cout << nbIncreasing << " " << get_max(0, (1 << 20)) << endl;
	}
	return 0;
}
