/*
* I use the simple permutation generation algorithm.
* always maintain the 3 values of a prefix: c2 is the smallest of a pair c1, c2 of the current prefix at which c1 < c2
* minChar is the minimum character of the current prefix
* it took 17s for the case 18 QPON and 15 minutes for the last case.
*/
#include <iostream>
#include <algorithm>
//#include <chrono>

using namespace std;

int ans;
string permutation;

bool validate(int len, char &c1, char &c2, char &minChar) {
	//cout << "validate.BEGIN.len=" << len << ",permutation=" << permutation.substr(0, len) << ",c1=" << c1 << ",c2=" << c2 << ",minChar=" << minChar << endl;
	bool result = true;
	if (len == 1) {
		c1 = c2 = 'Z';
		minChar = permutation[0];
	} else if (permutation[len - 1] < minChar) {
		minChar = permutation[len - 1];
	} else if (c2 == 'Z') {
		if (permutation[len - 1] > minChar) {
			c1 = minChar;
			c2 = permutation[len - 1];
		}
	} else if (permutation[len - 1] < c2) {
		if (permutation[len - 1] > c1) {
			c2 = permutation[len - 1];
		}
		else {
			c1 = minChar;
			c2 = permutation[len - 1];
		}
	} else {
		result = false;
	}
	//cout << "validate.END.len=" << len << ",permutation=" << permutation.substr(0, len) << ",c1=" << c1 << ",c2=" << c2 << ",minChar=" << minChar << ",result=" << result << endl;
	return result;
}

void permute(int startIdx, int endIdx, char c1, char c2, char minChar, char maxRestChar) {
	if (startIdx > endIdx) {
		ans++;
	} else {
		if (validate(startIdx, c1, c2, minChar)) {
			//char maxRestChar = *max_element(permutation.begin() + startIdx + 1, permutation.end());
			if (maxRestChar == permutation[startIdx - 1]) {
				maxRestChar = *max_element(permutation.begin() + startIdx, permutation.end());
			}
			if (c2 > maxRestChar) {
				for (int i = startIdx; i <= endIdx; i++) {
					// Swapping done 
					char oldC1 = c1; char oldC2 = c2; char oldMinChar = minChar; char oldMaxRestChar = maxRestChar;
					swap(permutation[startIdx], permutation[i]);

					// Recursion called
					permute(startIdx + 1, endIdx, c1, c2, minChar, maxRestChar);

					//backtrack 
					swap(permutation[startIdx], permutation[i]);
					c1 = oldC1; c2 = oldC2; minChar = oldMinChar; maxRestChar = oldMaxRestChar;
				}
			}
		}
	}
}

int main() {
	//using std::chrono::high_resolution_clock;
	//using std::chrono::duration_cast;
	//using std::chrono::duration;
	//using std::chrono::milliseconds;

	//while (true) {
	int l; string p;  cin >> l >> p;

	//auto t1 = high_resolution_clock::now();

	ans = 0;
	permutation = "";
	for (int i = 0; i < l; i++) {
		permutation.push_back('A' + i);
	}

	char c1 = 'Z', c2 = 'Z';
	char minChar = 'A';
	for (int i = 0; i < p.length(); i++) {
		for (int j = i + 1; j < l; j++) {
			if (permutation[j] == p[i]) {
				swap(permutation[j], permutation[i]);
				char oldC1 = c1; char oldC2 = c2; char oldMinChar = minChar;
				if (!validate(i + 1, c1, c2, minChar)) {
					cout << ans << endl;
					return 0;
				}
				if (i == p.length() - 1) {
					c1 = oldC1; c2 = oldC2; minChar = oldMinChar;
				}
				break;
			}
		}
	}

	char maxRestChar = permutation[p.length() - 1];
	permute(p.length(), l - 1, c1, c2, minChar, maxRestChar);

	cout << ans << endl;

	//auto t2 = high_resolution_clock::now();
	//auto ms_int = duration_cast<milliseconds>(t2 - t1);
	//cout << ms_int.count() << "ms" << endl;
	//}
	return 0;
}