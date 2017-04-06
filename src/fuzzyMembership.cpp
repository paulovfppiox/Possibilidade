//#include "include/fuzzyMembership.h"

fuzzyMembership::fuzzyMembership()  {
    this->tam = 11;
    this->pert = new float[tam];
    this->elem = new float[tam];
    it = 0;
}

fuzzyMembership::fuzzyMembership(int tam)
{
    this->tam = tam;
    this->pert = new float[tam];
    this->elem = new float[tam];
    it = 0;
}

fuzzyMembership::~fuzzyMembership()
{
    //dtor
}

void fuzzyMembership::setUniverse(int tam)  {
    this->uni = new float[tam];
    this->uniTam = tam;

    /*
    for(int i=0; i<=uniTam; i++)
        uni[i] = i;
    */

    uni[0] = 150;
    int j = 5;

    for(int i=1; i<=uniTam; i++)       {
        uni[i] = uni[i-1] + j;
    }
}

void fuzzyMembership::addElem(float p, float e) {
    elem[it] = e;
    pert[it] = p;
    this->it++;
}

void fuzzyMembership::addElemPos(float p, float e, int pos) {
    elem[pos] = e;
    pert[pos] = p;
}


void fuzzyMembership::exibeConjunto()  {

    for(int i=0; i<tam; i++)
        cout << this->pert[i] << "|" << this->elem[i] << ", " << endl;

    cout << endl;
}

int fuzzyMembership::buscaElemento(float ele) {

   int id = 0;

   for(int i=0; i<tam; i++) {

        if (elem[i] != ele)
            id = -1;
        else if (elem[i] == ele)   {
            id = i;
            break;
        }
   }
return id;
}

fuzzyMembership* fuzzyMembership::AND(fuzzyMembership *setB)            {

    fuzzyMembership *setAB = new fuzzyMembership(uniTam); // vetor de resultado

    for(int i=0; i < uniTam; i++) {

        // Busca a posição do atual elemento do universo nos conjuntos fuzzy A e B
        int idA = this->buscaElemento(uni[i]);
        int idB = setB->buscaElemento(uni[i]);

        // caso elemento não encontrado adicionar pertinencia 0 e valor 0 na posicao i
        if ((idA < 0) and (idB < 0)) {
            setAB->addElemPos(0,0, i);
        }
        // se o elemento existir nos dois conjuntos
        else if ((idA >= 0) and (idB >= 0)) {

           if (this->pert[idA] > setB->pert[idB])  { // verificar quem é o maior
               setAB->addElemPos(this->pert[idA], this->elem[idA], i);
           } else {
               setAB->addElemPos(setB->pert[idB], setB->elem[idB], i);
           }
        // se o elemento existir em ao menos um dos dois conjuntos
        } else if (idA >= 0) {
               setAB->addElemPos(this->pert[idA], this->elem[idA], i);
        } else if (idB >= 0) {
               setAB->addElemPos(setB->pert[idB], setB->elem[idB], i);
        }
    }
return setAB;
}

fuzzyMembership* fuzzyMembership::OR(fuzzyMembership *setB)            {

    fuzzyMembership *setAB = new fuzzyMembership(uniTam);

    for(int i=0; i<=uniTam; i++) {

        int idA = this->buscaElemento(uni[i]);
        int idB = setB->buscaElemento(uni[i]);

        // elemento não encontrado
        if ((idA < 0) and (idB < 0)) {
            setAB->addElemPos(0,0, i);
        }
        // se o elemento existir nos dois conjuntos
        else if ((idA >= 0) and (idB >= 0)) {

           if (this->pert[idA] < setB->pert[idB])  { // verificar quem é o menor
               setAB->addElemPos(this->pert[idA], this->elem[idA], i);
           } else {
               setAB->addElemPos(setB->pert[idB], setB->elem[idB], i);
           }
        // se o elemento existir em ao menos um dos dois conjuntos
        } else if (idA >= 0) {
               setAB->addElemPos(this->pert[idA], this->elem[idA], i);
        } else if (idB >= 0) {
               setAB->addElemPos(setB->pert[idB], setB->elem[idB], i);
        }
    }
return setAB;
}

fuzzyMembership* fuzzyMembership::NOT() {

    fuzzyMembership *setNot = new fuzzyMembership(uniTam);

    for(int i=0; i < uniTam; i++) {

        int id = this->buscaElemento(uni[i]);

        // elemento não encontrado
        if (id < 0) {
            setNot->addElemPos(0, this->elem[i], i);
        }
        // se o elemento existir nos dois conjuntos
        else if (id >= 0) {
            setNot->pert[i] = 1.0 - this->pert[i];
            setNot->elem[i] = this->elem[i];
        }
    }
return setNot;
}

fuzzyMembership* fuzzyMembership::conditionalPos(fuzzyMembership *set)   {
    return this->OR(set);
}

fuzzyMembership* fuzzyMembership::conditionalNec(fuzzyMembership *set)   {
    return this->AND(set);
}

float fuzzyMembership::max() {

    float maior = -99999;

    for(int i=0; i<this->tam; i++)    {
        if (this->pert[i] > maior)
            maior = this->pert[i];
    }
    return maior;
}

float fuzzyMembership::min() {

    float menor = 9999;

    for(int i=0; i<this->tam; i++)    {
        if (this->pert[i] < menor)
            menor = this->pert[i];
    }
    return menor;
}
