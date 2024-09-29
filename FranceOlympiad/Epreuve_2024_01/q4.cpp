#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAX_PIO=16,MAX_METRE=100*1000+5;
int nbPio,nbMetre,rep=-1;
int qualPio[MAX_PIO];
int val[MAX_METRE];
int suiv[MAX_METRE][MAX_PIO];
int plusLoin[(1<<MAX_PIO)];
vector<int> possi;

int nbBits(int n) {
    int ans=0;
    while (n>0) {
        ans+=n%2;
        n/=2;
    }
    return ans;
}

vector<int> transfo(int n) {
    vector<int> ans;
    for (int i=0;i<nbPio;i++) {
        ans.push_back(n%2);
        n/=2;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>nbPio>>nbMetre;
    for (int i=0;i<nbPio;i++) {
        cin>>qualPio[i];
    }
    for (int i=0;i<nbMetre;i++) {
        cin>>val[i];
    }
    int effortCour,posCour;
    for (int j=0;j<nbPio;j++) {
        effortCour=0;
        posCour=nbMetre;
        for (int i=nbMetre-1;i>=0;i--) {
            effortCour+=val[i];
            while (effortCour>qualPio[j]) {
                posCour--;
                effortCour-=val[posCour];
            }
            suiv[i][j]=posCour;
        }
    }
    for (int i=0;i<(1<<nbPio);i++) {
        possi.push_back(i);
    }
    sort(possi.begin(),possi.end(),[&] (int a,int b) {
        return nbBits(a)>nbBits(b); //
    });
    vector<int> etat;
    int prop;
    for (int i:possi) {
        //cout<<i<<endl;
        etat=transfo(i);
        if (plusLoin[i]==nbMetre) {
            prop=0;
            for (int j=0;j<nbPio;j++) {
                if (etat[j]==1) {
                    prop+=qualPio[j];
                }
            }
            rep=max(prop,rep);
        }
        else {
            for (int j=0;j<nbPio;j++) {
                if (etat[j]==1) {
                    plusLoin[i-(1<<j)]=max(plusLoin[i-(1<<j)],suiv[plusLoin[i]][j]);
                }
            }
        }
    }
    cout<<rep<<endl;
    return 0;
}