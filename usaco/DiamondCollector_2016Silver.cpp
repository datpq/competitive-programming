#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_N = 50000;

int main() {
	ifstream ifs("diamond.in");
	ofstream ofs("diamond.out");
	int n, k; ifs >> n >> k;
	int arr[MAX_N];
	for (int i = 0; i < n; i++) ifs >> arr[i];
	sort(arr, arr + n);
	int prefixMax[MAX_N], subfixMax[MAX_N];

	int start = 0, end = 0;
	int best = 0;
	// 1 5 5 9 10 12 14 --> Prefix = 1 1 2 2 2 3 3
	while (end <= n && start < n) {
		if (end < n && arr[end] <= arr[start] + k) {
			best = max(best, end-start+1);
			prefixMax[end] = best;
			end++;
		}
		else {
			start++;
			best = max(best, end - start + 1);
		}
	}
	start = end = n - 1;
	best = 0;
	// 1 5 5 9 10 12 14 --> Subfix = 3 3 3 3 2 2 1
	while (end>= 0 && start>=-1) {
		if (start >= 0 && arr[end] <= arr[start] + k) {
			best = max(best, end - start + 1);
			subfixMax[start] = best;
			start--;
		}
		else {
			end--;
			best = max(best, end - start + 1);
		}
	}
	best = 0;
	for (int i = 0; i < n - 1; i++) best = max(best, prefixMax[i] + subfixMax[i + 1]);
	ofs << best << endl;
	return 0;
}