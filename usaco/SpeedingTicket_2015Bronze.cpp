#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("speeding.in");
    ofstream ofs("speeding.out");
    int N, M; ifs >> N >> M;
    vector<int> seg1(N), speed1(N), seg2(M), speed2(M);
    for (int i = 0; i < N; i++) ifs >> seg1[i] >> speed1[i];
	for (int i = 0; i < M; i++) ifs >> seg2[i] >> speed2[i];
    int ans = 0;
    int idx1 = 0, idx2 = 0;
    int startSeg1 = 0, startSeg2 = 0;
    while (idx2 < M || idx1 < N) {
        if (startSeg1 + seg1[idx1] <= startSeg2) {
            startSeg1 += seg1[idx1++];
        } else if (startSeg2 + seg2[idx2] <= startSeg1) {
            startSeg2 += seg2[idx2++];
        } else {
            ans = max(ans, speed2[idx2] - speed1[idx1]);
            if (startSeg1 + seg1[idx1] < startSeg2 + seg2[idx2])
                startSeg1 += seg1[idx1++];
            else
                startSeg2 += seg2[idx2++];
        }
    }

    ofs << ans << "\n";
    return 0;
}
