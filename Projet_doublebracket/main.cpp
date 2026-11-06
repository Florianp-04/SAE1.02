#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main() {
    struct participants { // structure participants
        string name;
        unsigned match; // permet de vérifier que le participant participe bien au match (comparer avec var struct match)
        string place; // pour faire le classement final au fur et à mesure (loose = place fixée)
        unsigned score; // pour stopper le BO3 au bout de 2 win contre 0
        bool win; // var changer quand joueur gagne
    };
    string name; // pour nommer les var de participants et des match

    struct match { // struct pour les match
        unsigned num; // stockage
        string namep1;
        string namep2;
    };

    for (unsigned i {0} ; i < 64 ; i++) { // declare les 64 participants
        name = 'P' + to_string(i+1);
        participants name;
        name.name = to_string(i+1);
    }

    for (unsigned i {0} ; i < 126 ; i++) { // declare les 126 match
        name = "match" + to_string(i+1);
        match name;
    }

    unsigned o {0};
    for (unsigned i {0} ; i < 32 ; i++) {
        match{i}.namep1 = P{o+1}; //  !!!!! comment utiliser o pour le nom de ma var !!!!!
        match{i}.namep2 = P{o+2};
        o = o + 2;
    }



    return 0;
}
