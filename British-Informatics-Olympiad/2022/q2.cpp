#include <iostream>
#include <numeric>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class GameDrone {
    private:
        int r, b; //jumping steps of Red and Blue
        pair<int, int> redPos;
        pair<int, int> bluePos;
        int colonies[26][7];
        map<pair<int, int>, pair<int, int>> sharedEdges;

        struct FuedMark {
            int controlsGained, controlsTaken, Num, Edge, Val;
            bool operator<(const FuedMark &fm) const {
                if (Val > 0) { //red
                    if (controlsGained < fm.controlsGained) return false;
                    if (controlsGained > fm.controlsGained) return true;
                    if (controlsTaken < fm.controlsTaken) return false;
                    if (controlsTaken > fm.controlsTaken) return true;
                    if (Num > fm.Num) return false;
                    if (Num < fm.Num) return true;
                    return Edge < fm.Edge;
                } else { //blue
                    if (controlsGained < fm.controlsGained) return false;
                    if (controlsGained > fm.controlsGained) return true;
                    if (controlsTaken < fm.controlsTaken) return false;
                    if (controlsTaken > fm.controlsTaken) return true;
                    if (Num < fm.Num) return false;
                    if (Num > fm.Num) return true;
                    return Edge > fm.Edge;
                }
            }
        };

        void share(pair<int, int> x, pair<int, int> y) {
            sharedEdges[x] = y;
            sharedEdges[y] = x;
        }

        void jump(pair<int, int> &pos, int step, int direction) {
            pos.first += step; pos.first %= 25;
            if (pos.first == 0) pos.first = 25;
            pos.second += direction; pos.second %= 6;
            if (pos.second == 0) pos.second = 6;
        }

        void colonying(pair<int, int> &pos, int val) {
            colonies[pos.first][pos.second] = val;
            if (sharedEdges.count(pos)) colonies[sharedEdges[pos].first][sharedEdges[pos].second] = val;
        }

        int getOwnership(int hexa) {
            int ans = 0;
            for(int i=1; i<=6; i++) ans += colonies[hexa][i];
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
            for(int i=0; i<=25; i++) for(int j=0; j<=6; j++) colonies[i][j]=0;
        }

        void skirmish() {
            //red to jump
            jump(redPos, r, 1);
            colonying(redPos, 1);

            //blue to jump
            jump(bluePos, b, -1);
            colonying(bluePos, -1);
        }

        void feud(int val) {
            vector<FuedMark> v;
            for (int i = 1; i <= 25; i++) {
                int owner = getOwnership(i);
                for (int j = 1; j <= 6; j++) {
                    if (colonies[i][j] != 0) continue;
                    FuedMark fm = {0, 0, i, j, val};
                    colonies[i][j] = val;
                    int newOwner = getOwnership(i);
                    if (newOwner == val && owner == 0) fm.controlsGained++;
                    else if (newOwner == 0 && owner == -val) fm.controlsTaken++;
                    if (sharedEdges.count({i, j})) {
                        pair<int, int> nextDoor = sharedEdges[{i, j}];
                        int ownerNextDoor = getOwnership(nextDoor.first);
                        colonies[nextDoor.first][nextDoor.second] = val;
                        int newOwnerNextDoor = getOwnership(nextDoor.first);
                        if (newOwnerNextDoor == val && ownerNextDoor == 0) fm.controlsGained++;
                        else if (newOwnerNextDoor == 0 && ownerNextDoor == -val) fm.controlsTaken++;
                        colonies[nextDoor.first][nextDoor.second] = 0;//restore value
                    }
                    colonies[i][j] = 0; //restore value
                    v.push_back(fm);
                }
            }
            sort(v.begin(), v.end());
            if (v.size() > 0) {
                pair<int, int> p = {v[0].Num, v[0].Edge};
                colonying(p, v[0].Val);
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
            cout << countRed << "\n" << countBlue << "\n";
        }
};

int main() {
    // while(true) {
    int r, b; cin >> r >> b;
    int skirs, feuds; cin >> skirs >> feuds;
    GameDrone gd(r, b);
    while (skirs--) gd.skirmish();
    while(feuds--) {
        gd.feud(1); gd.feud(-1);
    }
    gd.printOwnerships();
    // }

    return 0;
}