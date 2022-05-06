#include <iostream>
#include <memory.h>

using namespace std;

int getMedian(int arr[], int count) {
	int d = 0;
	for (int i = 0; i < 10; i++) {
		if (d + arr[i] >= (count+1) / 2)  return i;
		else d += arr[i];
	}
}

int main() {
	string s; cin >> s;
	int arr[10]; memset(arr, 0, 10*sizeof(int));
	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - '0']++;
		cout << getMedian(arr, i + 1);
	}
	return 0;
}