#include <iostream>


using namespace std;

int main() {

    cout << "oi";

/*    fuzzyMembership *muAlto = new fuzzyMembership(11);
    fuzzyMembership *muMedio = new fuzzyMembership(11);
    muAlto->setUniverse(11);
    muMedio->setUniverse(11);

    muAlto->addElem(0, 150); muAlto->addElem(0, 155); muAlto->addElem(0, 160);
    muAlto->addElem(0.167, 165); muAlto->addElem(0.333, 170); muAlto->addElem(0.5, 175);
    muAlto->addElem(0.667, 180); muAlto->addElem(0.83, 185); muAlto->addElem(1, 190);
    muAlto->addElem(1, 195); muAlto->addElem(1, 200);

    muMedio->addElem(0, 150); muMedio->addElem(0, 155); muMedio->addElem(0, 160);
    muMedio->addElem(0.333, 165); muMedio->addElem(0.667, 170); muMedio->addElem(1, 175);
    muMedio->addElem(0.667, 180); muMedio->addElem(0.333, 185); muMedio->addElem(0, 190);
    muMedio->addElem(0, 195); muMedio->addElem(0, 200);

    cout << "alto " << endl;
    muAlto->exibeConjunto();

    // Distr. de Possibilidade de Mr. X.
    fuzzyMembership *pi = new fuzzyMembership(11);
    pi->setUniverse(11);

    // Intervalo de altura
    int p1 = 180, p2 = 190;

    for(int i=150; i<=200; i+=5) {
           if ((i >= p1) and (i <= p2))
                pi->addElem(1, i);
           else
                pi->addElem(0, i);
    }
    cout << "possibilidade (pi) " << endl;
    pi->exibeConjunto();

    fuzzyMembership *umMenosPi = new fuzzyMembership(11);
    umMenosPi->setUniverse(11);
    umMenosPi = pi->NOT();
    cout << "nec: " << endl;
    umMenosPi->exibeConjunto();

    // possibilidade/necessidade condicionais
    fuzzyMembership *pos = new fuzzyMembership(11);
    fuzzyMembership *nec = new fuzzyMembership(11);
    pos->setUniverse(11);
    nec->setUniverse(11);

    pos = pi->conditionalPos(muAlto);
    float max_compat = pos->max();
    nec = muAlto->conditionalNec(umMenosPi);
    float min_compat = nec->min();
    cout << "Centroide: " << (max_compat + min_compat)/2 << endl;

    pos = pi->conditionalPos(muMedio);
    max_compat = pos->max();
    nec = muMedio->conditionalNec(umMenosPi);
    min_compat = nec->min();
    cout << "Centroide: " << (max_compat + min_compat)/2 << endl;
*/

};
