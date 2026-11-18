#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;

size_t PFC (size_t p1, size_t p2) {
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        string entreeP1;
        string entreeP2;
        if (!cin) {
            exit (1);
        }

        //cout << "P1 joue PFC : " << endl;
        getline(cin, entreeP1); // P1 JOUE EN PREMIER
        //cout << entreeP1 << endl;

        //cout << "P2 joue PFC : " << endl;
        getline(cin, entreeP2); // P2 JOUE SECOND
        //cout << entreeP2 << endl;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (entreeP1 == entreeP2){

            cout << "Egalité" << endl;

        }else if ((entreeP1 == "pierre" && entreeP2 == "ciseaux") ||
            (entreeP1 == "feuille" && entreeP2 == "pierre") ||
            (entreeP1 == "ciseaux" && entreeP2 == "feuille")) {
            return p1;
        }
        else if ((entreeP1 != "pierre" && entreeP1 != "feuille" && entreeP1 != "ciseaux") ||
                 (entreeP2 != "pierre" && entreeP2 != "feuille" && entreeP2 != "ciseaux")){
            cout << "ERREUR D'ENTRÉE PFC" << endl;
        }    
        else {
            return p2;
        }
    }
}

size_t POF (size_t p1, size_t p2) {
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // FACE GAGNERA TOUJOURS
    // P1 JOUERA TOUJOURS EN PREMIER, DONC IL EST RESPONSABLE DE LA VICTOIRE
    string entreeP1;
    //cout << "P1 doit choisir Pile ou Face : " << endl;
    getline(cin,entreeP1);
    //cout << entreeP1 << endl;
    //cin.ignore (1);
    if (entreeP1 == "face") {
    //    cin.ignore (1);
        return p1;
    }else {

        return p2;
    }
}

size_t getTheNumber (size_t p1, size_t p2) {
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    size_t number {3};
    size_t entreep1;
    size_t entreep2;
    while (true) {
        string tmp;
        //cout << "P1 choisit son nombre" << endl;
        getline (cin, tmp);
        entreep1 = atoll (tmp.c_str());
        //cout << entreep1 << endl;
        //cout << "P2 choisit son nombre" << endl;
        getline (cin, tmp);
        entreep2 = atoll (tmp.c_str());
        //cout << entreep2 << endl;
        if (entreep1 == entreep2) 
            continue;
            // DANS UN VRAI JEU FONCTIONNEL, LE NUMBER CHANGE DE FAÇON ALÉATOIRE
        if (entreep1 == number)
            return p1;
        else
            return p2;
    }
}

size_t match(size_t P1, size_t P2) {
    size_t scoreP1 {0};
    size_t scoreP2 {0};
    size_t gamePFC;
    size_t gamePOF;
    size_t gameGTN;
    bool runGamePFC {true};
    bool runGamePOF {true};
    bool runGameGTN {true};

    while (true) {
        if ((scoreP1 == 2) && (scoreP2 == 0 || scoreP2 == 1)) {
            return P1;
        }else if ((scoreP2 == 2) && (scoreP1 == 0 || scoreP1 == 1)) {
            return P2;
        }
        if (runGamePFC) {
            gamePFC = PFC(P1, P2);
            if (P1 == gamePFC){
                ++scoreP1;
                runGamePFC = false;
                continue;
            }else {
                ++scoreP2;
                runGamePFC = false;
                continue;
            }
        }
        if (runGamePOF) {
            gamePOF = POF(P1, P2);
            if (P1 == gamePOF){
                ++scoreP1;
                runGamePOF = false;
                continue;
            }else {
                ++scoreP2;
                runGamePOF = false;
                continue;
            }
        }
        if (runGameGTN) {
            gameGTN = getTheNumber(P1, P2);
            if (P1 == gameGTN){
                ++scoreP1;
                runGameGTN = false;
                continue;
            }else {
                ++scoreP2;
                runGameGTN = false;
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
        if (looserBracket.size() == 0) { //STARTER = 32 MATCH WINNER UNIQUEMENT
            //cout << "STARTER WINNER 32 MATCH >-------------<" << endl;
            for ( size_t i {1} ; i < winnerBracket.size() ; i=i+2) {
                indWinner = match(winnerBracket[i-1], winnerBracket[i]);
                indLooser = (indWinner == winnerBracket[i-1]) ? i : i-1;
                indStockage.push_back(indLooser);
                looserBracket.push_back(winnerBracket[indStockage[o]]);
                ++o;
                //cout << "#Match entre : " << winnerBracket[i-1] << " ET " << winnerBracket[i] << endl;
                //cout << "Gagnant ---> " << indWinner << endl;
                //cout << "Perdant -> " << winnerBracket[indLooser] << endl;
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

        //cout << "TOUR <-------------> " << tour << endl;
        //cout << "LOOSERBRACKET 1 >-------------<" << endl;
        
        if (winnerBracket.size() != 1) {
            for ( size_t i {1} ; i < looserBracket.size() ; i = i+2) {
                indWinner = match(looserBracket[i-1], looserBracket[i]);
                indLooser = (indWinner == looserBracket[i-1]) ? i : i-1;
                indStockage.push_back(indLooser);
                
                //cout << "#Match entre : " << looserBracket[i-1] << " ET " << looserBracket[i] << endl;
                //cout << "Gagnant ---> " << indWinner << endl;
                //cout << "Perdant -> " << looserBracket[indLooser] << endl;
            }
            // MATCH LOOSERBRACKET
            
            //cout << "WINNERBRACKET >-------------<" << endl;

            for ( size_t i {1} ; i < winnerBracket.size() ; i=i+2) {
                indWinner = match(winnerBracket[i-1], winnerBracket[i]);
                indLooser = (indWinner == winnerBracket[i-1]) ? i : i-1;
                indStockageInter.push_back(indLooser);
                looserBracket[indStockage[o]] = winnerBracket[indStockageInter[o]];
                ++o;
                //cout << "#Match entre : " << winnerBracket[i-1] << " ET " << winnerBracket[i] << endl;
                //cout << "Gagnant ---> " << indWinner << endl;
                //cout << "Perdant -> " << winnerBracket[indLooser] << endl;
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
        //cout << "LOOSERBRACKET 2 >-------------<" << endl;
        for ( size_t i {1} ; i < looserBracket.size() ; i = i+2) {
            indWinner = match(looserBracket[i-1], looserBracket[i]);
            indLooser = (indWinner == looserBracket[i-1]) ? i : i-1;
            indStockage.push_back(indLooser);
            //cout << "#Match entre : " << looserBracket[i-1] << " ET " << looserBracket[i] << endl;
            //cout << "Gagnant ---> " << indWinner << endl;
            //cout << "Perdant -> " << looserBracket[indLooser] << endl;
        } 
        // MATCH LOOSERBRACKET 2
        
        for ( size_t i = indStockage.size() ; i > 0 ; --i) {
                looserBracket.erase(looserBracket.begin() + indStockage[i-1]);
        }
        indStockage.clear();
        // SUPPRESSION PERDANT LOOSERBRACKET
        ++tour;
    }
    //cout << endl;
    //cout << "GRANDE FINALE >>-------------<< " << endl;
    indWinner = match(winnerBracket[0], looserBracket[0]);
    cout << "GRAND Gagnant ---> " << indWinner << endl;
    return 0;
}


