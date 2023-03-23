#include <bits/stdc++.h>
using namespace std;

int nbSportifs, nbReq;
const int MAX_N = 300*1000;
int maillot[MAX_N], inverse[MAX_N];

// inverse[x] : i tel que maillot[i] = x

set<int> mauvais;
void testMauvais(int pos) {
    // ATTENTION : pos peut valoir -1
    //pos = (pos + nbSportifs) % nbSportifs;
    if (pos == -1) {
        // Revenir à la fin du cercle
        pos = nbSportifs - 1;
    }
    int suiv = pos + 1;
    if (suiv == nbSportifs) {
        // Revenir au début du cercle
        suiv = 0;
    }
    int diff = maillot[suiv] - maillot[pos];
    if (diff != 1 && diff != -(nbSportifs-1)) {
        mauvais.insert(pos); // O(log N)
    } else {
        mauvais.erase(pos); // O(log N)
    }
}

void echange(int _n1, int _n2) {
    swap(inverse[_n1], inverse[_n2]);
    int pos1 = inverse[_n1], pos2 = inverse[_n2];
    swap(maillot[pos1], maillot[pos2]);
    // for pos in [pos1-1, pos1, pos2-1, pos2]
    for (int pos : {pos1-1, pos1, pos2-1, pos2}) {
        testMauvais(pos);
    }
    if (mauvais.empty()) {
        cout << "OUI\n";
    } else {
        cout << "NON\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> nbSportifs >> nbReq;
    for (int pos = 0; pos < nbSportifs; ++pos) {
        cin >> maillot[pos];
        --maillot[pos]; // 0-indexage
        inverse[maillot[pos]] = pos;
    }

    for (int pos = 0; pos < nbSportifs; ++pos) {
        testMauvais(pos);
    }

    for (int iReq = 0; iReq < nbReq; ++iReq) {
        int n1, n2;
        cin >> n1 >> n2;
        --n1; --n2; // 0-indexage
        echange(n1, n2);
    }
}
