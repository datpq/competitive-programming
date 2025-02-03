#include <bits/stdc++.h>
using namespace std;

int tailleEquipe, diffMax;
const int TAILLE_MAX = 60000;
const int ZERO = 20 * 60000;
int role_gauche[TAILLE_MAX], role_droite[TAILLE_MAX], indice[TAILLE_MAX];
bool eleve_elimine[TAILLE_MAX], role_elimine[TAILLE_MAX];
bool est_vu[TAILLE_MAX];
int nb_restants[TAILLE_MAX];

vector<int> eleves[TAILLE_MAX];

int force_gauche = 0, force_droite = 0;

void elimine_role(int iRole) {
    int iEleve = -1;
    for(int eleve : eleves[iRole]) {
        if(!eleve_elimine[eleve]) iEleve = eleve;   
    }
    eleve_elimine[iEleve] = true;
    role_elimine[iRole] = true;
    
    if(iRole < tailleEquipe) force_gauche += indice[iEleve];
    else force_droite += indice[iEleve];
    
    nb_restants[role_gauche[iEleve]] -= 1;
    nb_restants[role_droite[iEleve]] -= 1;
    
    if(nb_restants[role_gauche[iEleve]] == 1) {
        elimine_role(role_gauche[iEleve]);
    }
    if(nb_restants[role_droite[iEleve]] == 1) {
        elimine_role(role_droite[iEleve]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> tailleEquipe >> diffMax;
    
    for(int iEleve = 0;iEleve < 2 * tailleEquipe;iEleve++) {
        cin >> role_gauche[iEleve] >> role_droite[iEleve] >> indice[iEleve];
        role_gauche[iEleve]--; role_droite[iEleve]--;
        role_droite[iEleve] += tailleEquipe;
        eleves[role_gauche[iEleve]].push_back(iEleve);
        eleves[role_droite[iEleve]].push_back(iEleve);
        nb_restants[role_gauche[iEleve]]++;
        nb_restants[role_droite[iEleve]]++;
    }

    for(int iRole = 0;iRole < 2 * tailleEquipe;iRole++) {
        if(role_elimine[iRole]) continue;
        if(nb_restants[iRole] == 0) {
            cout << "NON" << endl;
            return 0;
        }
        else if(nb_restants[iRole] == 1) {
            elimine_role(iRole);
        }
    }
    
    for(int iRole = 0;iRole < 2 * tailleEquipe;iRole++) {
        if(role_elimine[iRole]) continue;
        if(nb_restants[iRole] != 2) {
            cout << "NON" << endl;
            return 0;
        }
        
        vector<int> eleves_restants;
        for(int eleve : eleves[iRole]) {
            if(!eleve_elimine[eleve]) {
                eleves_restants.push_back(eleve);
            }
        }
        eleves[iRole] = eleves_restants;
    }
    
    vector<int> deltas;
    
    for(int iRole = 0;iRole < 2 * tailleEquipe;iRole++) {
        if(role_elimine[iRole] || est_vu[iRole]) continue;
        
        int role_actuel = iRole;
        int eleve_actuel = eleves[iRole][0];
        
        int delta = 0;
        while(true) {
            if(role_actuel < tailleEquipe) delta += indice[eleve_actuel];
            else delta -= indice[eleve_actuel];
            
            int role_suivant = -1;
            if(role_gauche[eleve_actuel] != role_actuel) role_suivant = role_gauche[eleve_actuel];
            if(role_droite[eleve_actuel] != role_actuel) role_suivant = role_droite[eleve_actuel];
            
            int eleve_suivant = -1;
            for(int eleve : eleves[role_suivant]) {
                if(eleve != eleve_actuel) {
                    eleve_suivant = eleve;
                }
            }
            
            est_vu[role_actuel] = true;
            role_actuel = role_suivant;
            eleve_actuel = eleve_suivant;
            
            if(role_actuel == iRole) break;
        }
        
        deltas.push_back(abs(delta));
    }
    
    using Bitset = bitset<ZERO + 1>;
    Bitset bits;
    bits[0] = 1;
    
    int somme_totale = 0;
    for(int delta : deltas) {
        bits |= (bits << delta);
        somme_totale += delta;
    }
    
    for(int somme = 0;somme <= ZERO;somme++) {
        if(bits[somme] && abs((force_gauche + somme) - (force_droite + somme_totale - somme)) <= diffMax) {
            cout << "OUI" << endl;
            return 0;
        }
    }
    
    cout << "NON" << endl;
    return 0;
}