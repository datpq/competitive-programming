#include <iostream>

using namespace std;

string parks;
long long ith, total;
int n, cars[16];
int chosen[16];

void search(int idx) {
	if (total >= ith) return;
	if (idx == parks.length()) {
		total++;
		if (total == ith) { // 3b || parks == "EECCGGAAAA"
			cout << parks << endl;
		}
	}
	else {
		char preferedSpace = 'A' + cars[idx];
		char c = preferedSpace;
		while (c > 'A' && chosen[c - 'A' - 1]) c--;
		for (; c <= preferedSpace; c++) {
			chosen[cars[idx]] = true;
			parks[idx] = c;
			search(idx + 1);
			chosen[cars[idx]] = false;
		}
	}
}

const int LEN = 16;
const int PREFERED_POSITIONS = 3;
long long P = 1;
int arr[] = { 1, 1 };
long long ans = 0;
void permute(int idx) {
	if (idx == PREFERED_POSITIONS - 1) {
		ans += P / (arr[0] * arr[1]);
	}
	else {
		for (int i = (idx == 0 ? 1 : arr[idx - 1] + 1); i < LEN; i++) {
			arr[idx] = i;
			permute(idx + 1);
		}
	}
}

int main() {
	string carPlc;
	cin >> carPlc >> ith;
	n = carPlc.length();
	string s(n, ' '); parks = s;
	memset(chosen, false, n * sizeof(bool));
	for (int i = 0; i < n; i++) cars[carPlc[i] - 'a'] = i;
	total = 0;
	search(0);

	//3b "ghcdabefij"

	// 3c
	// 2: opnmlkjihgfedcba ponmlkjihgfedcab (in reverse order and swap 2 first or 2 last characters)

	//3d 6165817614720
	//15! * (1/(2-1)(3-1) + 1/(2-1)(4-1) + 1/(2-1)(5-1) + ... + 1/(15-1)(16-1)
	//15! * (1/1*2 + 1/1*3 + ... + 1/14*15)
	for (int i = 1; i < LEN; i++) P *= i;
	permute(0);
	cout << ans << endl;

	return 0;
}