#ifndef FUZZYMEMBERSHIP_H
#define FUZZYMEMBERSHIP_H
#include <iostream>

using namespace std;

class fuzzyMembership
{
    public:
            int tam; // tamanho da funcao de pertinencia
            int uniTam; // tamanho do universo
            int it;
            float *elem;
            float *pert;
            float *uni;
    public:
        fuzzyMembership(int tam);
        fuzzyMembership();
        virtual ~fuzzyMembership();

        void addElem(float p, float e);
        void addElemPos(float p, float e, int pos);
        void exibeConjunto();
        int buscaElemento(float el);
        void setUniverse(int tam);
        fuzzyMembership* AND(fuzzyMembership *set);
        fuzzyMembership* OR(fuzzyMembership *set);
        fuzzyMembership* NOT();

        // Métodos que calculam as possibilidades condicionais
        fuzzyMembership* conditionalPos(fuzzyMembership *set);
        fuzzyMembership* conditionalNec(fuzzyMembership *set);

        float min();
        float max();
};
#endif // FUZZYMEMBERSHIP_H
