 
#include<bits/stdc++.h>
using namespace std;

#define int long long // On declare que dans ce probleme, on utilisera des long long plutot que des int.

const int MAX_CARTES=61,MAX_VAL=10000+5;
int nbCartes,somGlob;
vector<int> valTri;
int memo[2][MAX_CARTES*MAX_VAL];
int sommePossi[MAX_CARTES*MAX_VAL][MAX_CARTES];

signed main() { //A modifier lorsque vous faites #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>nbCartes;
    for (int i=0;i<nbCartes;i++) {
        int valNouv;
        cin>>valNouv;
        somGlob+=valNouv;
        valTri.push_back(valNouv);
    }
    sort(valTri.begin(),valTri.end());
    sommePossi[0][nbCartes]=1;
    for (int icol=nbCartes-1;icol>=0;icol--) {
        for (int ilig=0;ilig<=somGlob;ilig++) {
            sommePossi[ilig][icol]=sommePossi[ilig][icol+1]; //ne pas prendre la carte
            if (valTri[icol]<=ilig) {
                sommePossi[ilig][icol]+=sommePossi[ilig-valTri[icol]][icol+1]; //prendre la carte
            } 
        }
    }
    int rep=0,obj=somGlob/2;
    for (int icarte=0;icarte<nbCartes;icarte++) {
        for (int i=obj-valTri[icarte]+1;i<=obj;i++) {
            rep+=sommePossi[i][icarte+1];
        }
    }
    cout<<rep<<endl;
    return 0;
}
