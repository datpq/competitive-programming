#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Container {
    int totAdd = 0;
    int delta = 0;
    int cntDown = 0, cntUp = 0;
    int sumDown = 0, sumUp = 0;

    vector<int> decaleMoi;
    int decal;

    Container(int n) : decaleMoi(2*n + 50, 0), decal(n + 25) {}

    void insereZeros(int newVals) {
        decaleMoi[decal + delta] += newVals;
        cntUp += newVals;
        sumUp += newVals * delta;
    }

    void decr() {
        --delta;
        int transfert = decaleMoi[decal + delta];
        cntDown -= transfert;
        sumDown -= transfert * delta;
        cntUp += transfert;
        sumUp += transfert * delta;
    }

    void incr() {
        int transfert = decaleMoi[decal + delta];
        cntDown += transfert;
        sumDown += transfert * delta;
        cntUp -= transfert;
        sumUp -= transfert * delta;
        ++delta;
    }

    int ans() {
        int sumAbs = (sumUp - cntUp*delta) - (sumDown - cntDown*delta);
        return (totAdd + sumAbs) / 2;
    }
};

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int nbProm, nbVoisins, mode;
    cin >> nbProm >> nbVoisins >> mode;

    Container ct(nbProm);

    int curLo = -1, curRi = -1;
    for (int iVoi = 0; iVoi < nbVoisins; ++iVoi) {
        int chien, lo, ri;
        cin >> chien >> lo >> ri;
        int newVals;
        if (iVoi == 0) {
            newVals = ri - lo + 1;
        } else {
            newVals = (curLo - lo) + (ri - curRi);
        }
        ct.insereZeros(newVals);
        curLo = lo, curRi = ri;

        if (chien == 0) {
            ct.decr();
        } else {
            ct.incr();
        }

        ct.totAdd += ri - lo + 1;
        if (mode || iVoi == nbVoisins - 1)
        cout << ct.ans() << '\n';
    }
}
