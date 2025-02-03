#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAX_BUS=2000+5,INFINI=1000*1000*1000+5;
int nbBus;
int vitesse[MAX_BUS];
set<int> listeVit;
int corres[MAX_BUS];
unordered_map<int,int> hache;
int minJusqua[MAX_BUS];
int memo[MAX_BUS][MAX_BUS];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>nbBus;
    for (int i=1;i<=nbBus;i++) {
        cin>>vitesse[nbBus+1-i];
        listeVit.insert(vitesse[nbBus+1-i]);
    }
    listeVit.insert(INFINI);
    int idVit=0;
    for (int i:listeVit) {
        corres[idVit]=i;
        hache[i]=idVit;
        idVit++;
    }
    minJusqua[nbBus+1]=idVit-1;
    for (int i=nbBus;i>0;i--) {
        minJusqua[i]=min(minJusqua[i+1],hache[vitesse[i]]);
    }
    for (int i=1;i<=nbBus;i++) {
        int vitHache=hache[vitesse[i]];
        for (int j=0;j<idVit;j++) {
            // Dans la voie la moins rapide, il y a le vehicule le plus lent a droite, et dans l'autre voie, 
            // le vehicule le plus lent roule a une vitesse corres[j].
            memo[i][j]=min(memo[i-1][j]+max((int) 0,vitesse[i]-corres[minJusqua[i+1]]), // on va sur la file la plus lente
                           memo[i-1][min(j,vitHache)]+max((int) 0,vitesse[i]-corres[j]));
        }
    }
    cout<<memo[nbBus][idVit-1]<<endl;
    return 0;
}
