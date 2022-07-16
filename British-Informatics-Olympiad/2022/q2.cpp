#include <iostream>
#include <numeric>
#include <memory.h>
#include <map>
#include <vector>

using namespace std;

class GameDrone {
    private:
        int r, b; //jumping steps of Red and Blue
        pair<int, int> redPos;
        pair<int, int> bluePos;
        map<pair<int, int>, int> colonies;

        map<pair<int, int>, pair<int, int>> sharedEdges;

        void share(pair<int, int> x, pair<int, int> y) {
            sharedEdges[x] = y;
            sharedEdges[y] = x;
        }

        void colonying(pair<int, int> pos, int val) {
            colonies[pos] = val;
            //if (colonies[pos] > 1) colonies[pos] = 1; //jump twice on an edge, treated like once
            //if (colonies[pos] < -1) colonies[pos] = -1; //jump twice on an edge, treated like once
            if (sharedEdges.count(pos)) {
                colonies[sharedEdges[pos]] = val;
                //if (colonies[sharedEdges[pos]] > 1) colonies[sharedEdges[pos]] = 1;
                //if (colonies[sharedEdges[pos]] < -1) colonies[sharedEdges[pos]] = -1;
            }
        }

        int getOwnership(int hexa) {
            int ans = 0;
            for (auto &x : colonies) {
                if (x.first.first == hexa) {
                    ans += x.second;
                }
            }
            if (ans > 1) ans = 1;
            else if (ans < -1) ans = -1;
            return ans;
        }

    public:
        GameDrone(int rmoves, int bmoves) {
            for(int i=1; i<=25; i++) {
                if ((i>=1 && i <= 5) || (i>=11 && i <= 15))
					share({ i, 3 }, { i + 5, 6 });
                else if ((i >= 6 && i < 10) || (i >= 16 && i < 20))
                    share({ i, 3 }, { i + 6, 6 });
                if ((i>1 && i <= 5) || (i>11 && i <= 15))
                    share({ i, 4 }, { i + 4, 1 });
                else if ((i >= 6 && i <= 10) || (i >= 16 && i <= 20))
                    share({ i, 4 }, { i + 5, 1 });
                if (i%5 != 0)
                    share({ i, 2 }, { i + 1, 5 });
            }
            r = rmoves; b = bmoves;
            redPos = { 1 - r, 0 }; // will be at (1,1) after the first jump
            bluePos = { 25 - b, 1 }; // will be at (25,6) after the first jump
        }

        void skirmish() {
            //red to jump
            redPos.first = (redPos.first + r) % 25;
            if (redPos.first == 0) redPos.first = 25;
            redPos.second = (redPos.second + 1) % 6;
            if (redPos.second == 0) redPos.second = 6;
            colonying(redPos, 1);

            //blue to jump
            bluePos.first = (bluePos.first + b) % 25;
            if (bluePos.first == 0) bluePos.first = 25;
            bluePos.second = (bluePos.second - 1) % 6;
            if (bluePos.second == 0) bluePos.second = 6;
            colonying(bluePos, -1);
        }

        void feud() {
            int maxGain = 0;
            for (int i = 1; i <= 25; i++) {
                int owner = getOwnership(i);
                for (int j = 1; j <= 6; j++) {

                }
            }
        }

        void printOwnerships() {
            int countRed = 0;
            int countBlue = 0;
            for (int i = 1; i <= 25; i++) {
                int owner = getOwnership(i);
                if (owner > 0) countRed++;
                else if (owner < 0) countBlue++;
            }
            cout << countRed << ' ' << countBlue;
        }
};

int main() {
    int r, b; cin >> r >> b;
    int skirs, feuds; cin >> skirs >> feuds;
    GameDrone gd(r, b);
    while (skirs--) gd.skirmish();

    gd.printOwnerships();

    return 0;
}