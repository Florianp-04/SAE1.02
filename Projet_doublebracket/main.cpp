#include <iostream>
#include <vector>
#include <string>

using namespace std;

size_t PFC (size_t p1, size_t p2) {
    string entreeP1;
    string entreeP2;
    while (true) {
        cout << "P1 joue" << endl;
        cin >> entreeP1;
        cout << "P2 joue" << endl;
        cin >> entreeP2;
        if (entreeP1 == entreeP2){
            cout << "Egalité" << endl;
            continue;
        }else if ((entreeP1 == "pierre" && entreeP2 == "ciseaux") ||
            (entreeP1 == "feuille" && entreeP2 == "pierre") ||
            (entreeP1 == "ciseaux" && entreeP2 == "feuille")) {
            return p1;
        }else {
            return p2;
        }
    }
}

size_t match(size_t P1, size_t P2) {
    size_t scoreP1 {0};
    size_t scoreP2 {0};
    size_t gamePFC;
    bool runGamePFC {true};

    while (true) {
        if ((scoreP1 == 2) && (scoreP2 == 0 || scoreP2 == 1)) {
            return P1;
        }else if ((scoreP2 == 2) && (scoreP1 == 0 || scoreP1 == 1)) {
            return P2;
        }
        if (runGamePFC) {
            gamePFC = PFC(P1, P2);
            if (P1 == gamePFC){
                // ++scoreP1;
                scoreP1 = 2;
                runGamePFC = false;
                continue;
            }else {
                // ++scoreP2;
                runGamePFC = false;
                continue;
            }
        }
    }
}

int main () {
    vector <size_t> winnerBracket(64);
    for ( size_t i {0} ; i < winnerBracket.size() ; ++i) {
        winnerBracket[i] = i + 1;
    }
    vector <size_t> looserBracket;
    vector <size_t> indStockage;
    vector <size_t> indStockageInter;
    size_t o {0};
    size_t indWinner;
    size_t indLooser;
    size_t tour {1};
    
    
    while (winnerBracket.size() > 1 || looserBracket.size() > 1) {
        if (looserBracket.size() == 0) { // STARTER = 32 MATCH WINNER UNIQUEMENT
            cout << "STARTER WINNER 32 MATCH >-------------<" << endl;
            for ( size_t i {1} ; i < winnerBracket.size() ; i=i+2) {
                indWinner = match(winnerBracket[i-1], winnerBracket[i]);
                indLooser = (indWinner == winnerBracket[i-1]) ? i : i-1;
                indStockage.push_back(indLooser);
                looserBracket.push_back(winnerBracket[indStockage[o]]);
                ++o;
                cout << "#Match entre : " << winnerBracket[i-1] << " ET " << winnerBracket[i] << endl;
                cout << "Gagnant ---> " << indWinner << endl;
                cout << "Perdant -> " << winnerBracket[indLooser] << endl;
            } 
            o = 0;
            // MATCH WINNERBRACKET + AJOUT DANS LOOSERBRACKET
            
            for ( size_t i = indStockage.size() ; i > 0 ; --i) {
                winnerBracket.erase(winnerBracket.begin() + indStockage[i-1]);
            } 
            indStockage.clear();
            // SUPPRESSION DANS WINNERBRACKET
        }
        
        //** ---------------------------------------------- **/
        // DEBUT BOUCLE TOURNOI

        cout << "TOUR <-------------> " << tour << endl;
        cout << "LOOSERBRACKET 1 >-------------<" << endl;
        
        if (winnerBracket.size() != 1) {
            for ( size_t i {1} ; i < looserBracket.size() ; i = i+2) {
                indWinner = match(looserBracket[i-1], looserBracket[i]);
                indLooser = (indWinner == looserBracket[i-1]) ? i : i-1;
                indStockage.push_back(indLooser);
                
                cout << "#Match entre : " << looserBracket[i-1] << " ET " << looserBracket[i] << endl;
                cout << "Gagnant ---> " << indWinner << endl;
                cout << "Perdant -> " << looserBracket[indLooser] << endl;
            }
            // MATCH LOOSERBRACKET
            
            cout << "WINNERBRACKET >-------------<" << endl;
            
            for ( size_t i {1} ; i < winnerBracket.size() ; i=i+2) {
                indWinner = match(winnerBracket[i-1], winnerBracket[i]);
                indLooser = (indWinner == winnerBracket[i-1]) ? i : i-1;
                indStockageInter.push_back(indLooser);
                looserBracket[indStockage[o]] = winnerBracket[indStockageInter[o]];
                ++o;
                cout << "#Match entre : " << winnerBracket[i-1] << " ET " << winnerBracket[i] << endl;
                cout << "Gagnant ---> " << indWinner << endl;
                cout << "Perdant -> " << winnerBracket[indLooser] << endl;
            }
            o = 0;
            indStockage.clear();
            // MATCH WINNERBRACKET + AJOUT A PLACE DE PERDANT LOOSERBRACKET
            
            for ( size_t i = indStockageInter.size() ; i > 0 ; --i) {
                    winnerBracket.erase(winnerBracket.begin() + indStockageInter[i-1]);
            } 
            indStockageInter.clear();
            // SUPPRESION DANS WINNERBRACKET
        }
        cout << "LOOSERBRACKET 2 >-------------<" << endl;
        for ( size_t i {1} ; i < looserBracket.size() ; i = i+2) {
            indWinner = match(looserBracket[i-1], looserBracket[i]);
            indLooser = (indWinner == looserBracket[i-1]) ? i : i-1;
            indStockage.push_back(indLooser);
            cout << "#Match entre : " << looserBracket[i-1] << " ET " << looserBracket[i] << endl;
            cout << "Gagnant ---> " << indWinner << endl;
            cout << "Perdant -> " << looserBracket[indLooser] << endl;
        } 
        // MATCH LOOSERBRACKET 2
        
        for ( size_t i = indStockage.size() ; i > 0 ; --i) {
                looserBracket.erase(looserBracket.begin() + indStockage[i-1]);
        }
        indStockage.clear();
        // SUPPRESSION PERDANT LOOSERBRACKET

        ++tour;
        
    }
    cout << endl;
    cout << "GRANDE FINALE >>-------------<< " << endl;
    cout << "GRAND Gagnant ---> " << match(winnerBracket[0], looserBracket[0]) << endl;

    
    return 0;
}
