#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> R(N, vector<int>(N));
    for(int i=0; i<N; i++) for(int j=i; j<N; j++) cin >> R[i][j];
    vector<int> A(N);
    A[0]= 0; A[1] = R[0][1];
    for(int i=2; i<N; i++) {
        A[i] = A[i-1] + R[i-1][i];
        bool bad = false;
        for(int j=0; j<i; j++) {
            int mn = *min_element(A.begin()+j, A.begin()+i+1);
            int mx = *max_element(A.begin()+j, A.begin()+i+1);
            if (R[j][i] != mx - mn) {
                bad = true;
                break;
            }
        }
        if (bad) A[i] = A[i-1] - R[i-1][i];
    }
    for(int i=0; i<N-1; i++) cout << A[i] << " ";
    cout << A[N-1];
    // for(auto &a: A) cout << a << " ";
	return 0;
}
