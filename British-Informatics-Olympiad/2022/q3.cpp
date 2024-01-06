#include <bits/stdc++.h>
#define int long long

using namespace std;

string parks;
int ith, total;
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
        int delta = 0;
		for (; c <= preferedSpace; c++) {
            if (delta && total+delta<ith) {
                total+=delta; continue;
            }
			chosen[cars[idx]] = true;
			parks[idx] = c;
            int oldTotal = total;
			search(idx + 1);
            delta = total-oldTotal;
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

signed main() {
	string carPlc;
	cin >> carPlc >> ith;
	n = carPlc.length();
	string s(n, ' '); parks = s;
	memset(chosen, false, n * sizeof(bool));
	for (int i = 0; i < n; i++) cars[carPlc[i] - 'a'] = i;
	total = 0;
	search(0);

	//3b "ghcdabefij"

	//3c
	//120 n*(n-1)/2. let's try with n=3,4:
	//n=3 bca, cab, acb. f(3)=3*2/2=3
	//n=4 (n=3)a, (...b) -> ((cdb)a, (dbc)a, (bdc)a), (dcab, dacb, adcb)). f(4)=f(3)+3=4*3/2
	//n=5 (n=4)a, (...b) -> f(5)= f(4)+4
	//n+1 (n)a, (...b) -> f(n+1)=f(n)+n

	//3d 6165817614720
	//15! * (1/(2-1)(3-1) + 1/(2-1)(4-1) + 1/(2-1)(5-1) + ... + 1/(15-1)(16-1)
	//15! * (1/1*2 + 1/1*3 + ... + 1/14*15)
	for (int i = 1; i < LEN; i++) P *= i;
	permute(0);
	cout << ans << endl;

	return 0;
}