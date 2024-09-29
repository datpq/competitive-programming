#include <bits/stdc++.h>
using namespace std;

int X, Y, K, P;
int ecartMin = 201;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> X >> Y >> K >> P;

    // Situations atteignables en k étapes
    vector<vector<bool>> explores(101, vector<bool>(101, false));
    explores[0][0] = true;

    for(int k = 0;k < K;k++) {
        // Situations atteignables en k + 1 étapes
        vector<vector<bool>> suiv_explores(101, vector<bool>(101, false));

        for(int a = 0;a <= X;a++) {
            for(int b = 0;b <= Y;b++) {
                if(explores[a][b]) {
                    suiv_explores[a][b] = true;
                    suiv_explores[0][b] = true;
                    suiv_explores[a][0] = true;
                    suiv_explores[X][b] = true;
                    suiv_explores[a][Y] = true;

                    int t1 = min(a, Y - b);
                    int t2 = min(b, X - a);

                    suiv_explores[a - t1][b + t1] = true;
                    suiv_explores[a + t2][b - t2] = true;
                }
            }
        }

        explores = suiv_explores;
    }

    for(int a = 0;a <= X;a++) {
        for(int b = 0;b <= Y;b++) {
            if(explores[a][b]) {
                ecartMin = min(ecartMin, abs(P - a - b));
            }
        }
    }

    cout << ecartMin << endl;

    return 0;
}