#include <bits/stdc++.h>
using namespace std;

const long long MAX_PRIX = 1e9;
int nbGuimauves, nbRequetes;
vector<long long> prix, sommePrefixePrix, sommeSuffixePrix;

// Retourner (nombre, somme)
pair<int, long long> enDessous(long long prixLimite, long long delta) {
    // Plus petit i bleu au dessus (strict. supérieur)
    int idxPref = upper_bound(prix.begin(), prix.end(), delta) - prix.begin();
    int taillePref = idxPref;
    
    long long sumPrefDelta = sommePrefixePrix[idxPref];

    // Plus petit i rouge en dessous
    // i.e. 2*prixLimite - prix[i] <= deltaLimite
    // prix[i] >= 2*prixLimite - deltaLimite
    int idxSuff = lower_bound(prix.begin(), prix.end(), 2*prixLimite - delta) - prix.begin();
    int tailleSuff = nbGuimauves - idxSuff;

    long long sumSuffDelta = 2*prixLimite*tailleSuff - sommeSuffixePrix[idxSuff];

    return make_pair(taillePref + tailleSuff,
        sumPrefDelta + sumSuffDelta);
}

long long solve(long long prixLimite, int nbAchats) {
    long long deltaLim;
    {
        long long low = -(MAX_PRIX + 5), high = prixLimite;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (enDessous(prixLimite, mid).first >= nbAchats) {
                // Il y a assez de guimauves en dessous
                high = mid; // pas besoin d'aller plus haut
            } else {
                low = mid+1; // obligé d'aller plus haut
            }
        }
        deltaLim = low;
    }
    // On prend les guimauves strictement en dessous
    auto strictDessous = enDessous(prixLimite, deltaLim - 1);
    long long somme = strictDessous.second;
    // On rajoute les guimauves pile poil à la limite
    // (qui donnent deltaLim)
    // Combien ils nous en manquent ?
    int nbManquantes = nbAchats - strictDessous.first;
    somme += nbManquantes * deltaLim;

    return somme;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> nbGuimauves >> nbRequetes;
    prix.resize(nbGuimauves);
    sommePrefixePrix.resize(nbGuimauves + 1);
    sommeSuffixePrix.resize(nbGuimauves + 1);

    for (int iGui = 0; iGui < nbGuimauves; ++iGui) {
        cin >> prix[iGui];
    }
    sort(prix.begin(), prix.end());
    // sommePrefixePrix[0] = 0
    // sommePrefixePrix[1] = prix[0]
    for (int iGui = 0; iGui < nbGuimauves; ++iGui) {
        sommePrefixePrix[iGui + 1] = sommePrefixePrix[iGui] + prix[iGui];
    }
    // sommeSuffixePrix[nbGuimauves] = 0
    for (int iGui = nbGuimauves - 1; iGui >= 0; --iGui) {
        sommeSuffixePrix[iGui] = sommeSuffixePrix[iGui + 1] + prix[iGui];
    }

    for (int iReq = 0; iReq < nbRequetes; ++iReq) {
        long long prixLimite;
        int nbAchats;
        cin >> prixLimite >> nbAchats;
        cout << solve(prixLimite, nbAchats) << '\n';
    }
}
