#include "trainingClasses.h"

trainingClasses::trainingClasses() {
    this->it = classes.begin();
}

void trainingClasses::addClasse(fuzzyMembership *c) {
    this->classes.push_back(c);
}

void trainingClasses::exibeClasses() {

    int num = 0;

    for(this->it = this->classes.begin(); it != this->classes.end(); it++)  {

        cout << "---- Classe -" << num << "---" << endl;

        fuzzyMembership c = (**it);
        c.exibeConjunto();
        cout << endl;
        num++;
    }
}

list<fuzzyMembership*> trainingClasses::getClasses()   {
    return this->classes;
}
