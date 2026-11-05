#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main() {
    vector<string> participants(64); // Vecteur pour stocker les 64 participants
    vector<string> matchOrdre(126); // Stockage de tous les participants par match, utile pour fonction match

    for (unsigned i {0} ; i < 64 ; i++) { // Defini les participants de 01 à 64
        if (i < 9) {
            participants[i] = '0' + to_string(i+1);
        }else {
            participants[i] = to_string(i+1);
        }
    }

    unsigned o {0};
    for (unsigned i {0} ; i < 32 ; i++) {
        matchOrdre[i] = participants[o] + participants[o+1];
        o = o + 2;
    }

    for (unsigned i {0} ; i < 32 ; i++) {
        cout << matchOrdre[i] << endl;

    }











    return 0;
}
