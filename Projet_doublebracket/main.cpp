#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct participants { // structure participants
    string name;
    unsigned num;
    unsigned match; // permet de vérifier que le participant participe bien au match (comparer avec var struct match)
    string place; // pour faire le classement final au fur et à mesure (loose = place fixée)
    unsigned score; // pour stopper le BO3 au bout de 2 win contre 0
    bool win; // var changer quand joueur gagne
};

struct match { // struct pour les match
    unsigned num; // stockage
    unsigned nump1; // id du p1
    unsigned nump2; // id du P2
};

void win(participants & p1, participants & p2) {
    if ((p1.score == 2 && p2.score == 0) ||
        (p1.score == 3 && (p2.score == 2 || p2.score == 1))) {
        p1.win = true;
        p1.score = 0;
        p2.score = 0;
    }

    if ((p2.score == 2 && p1.score == 0) ||
        (p2.score == 3 && (p1.score == 2 || p1.score == 1))){
        p2.win = true;
        p1.score = 0;
        p2.score = 0;
    }
}

void matchBO3(match & nextRoundWin, match & nextRoundLoose, participants p1, participants p2) {
    win(p1, p2);
    if (p1.win) { // si p1 gagne
        if (nextRoundWin.nump1 == 0) // si slot 1 est libre
            nextRoundWin.nump1 = p1.num;
        else
            nextRoundWin.nump2 = p1.num; // sinon slot 2
        if (nextRoundLoose.nump1 == 0) // si slot 1 est libre
            nextRoundLoose.nump1 = p2.num;
        else
            nextRoundLoose.nump2 = p2.num; // sinon slot 2
    }
    if (p1.win) { // si p1 gagne
        if (nextRoundWin.nump1 == 0) // si slot 1 est libre
            nextRoundWin.nump1 = p2.num;
        else
            nextRoundWin.nump2 = p2.num; // sinon slot 2
        if (nextRoundLoose.nump1 == 0) // si slot 1 est libre
            nextRoundLoose.nump1 = p1.num;
        else
            nextRoundLoose.nump2 = p1.num; // sinon slot 2
    }


}

int main() {

    vector <participants> P(64);
    vector <match> match(126);

    for (unsigned i {0} ; i < 64 ; i++) { // declare les 64 participants
        P[i].name = to_string(i+1);
        P[i].num = i;
    }

    for (unsigned i {0} ; i < 126 ; i++) { // declare les 126 match
        match[i].num = i+1;
    }

    for (unsigned i {0}, o {0} ; i < 32 ; i++, o = o + 2) { // Donne l'id de chaque P1 et P2 d'un match, à chaque premier 32 match
        match[i].nump1 = P[o].num;
        match[i].nump2 = P[o+1].num;
    }

    for (unsigned i {0} ; i < 32 ; i++) { // test
        cout << "MATCH : " << match[i].num << endl;
        cout << "P1 : " << match[i].nump1 << endl;
        cout << "P2 : " << match[i].nump2 << endl;
    }



    return 0;
}
