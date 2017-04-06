#ifndef TRAININGCLASSES_H
#define TRAININGCLASSES_H
#include "fuzzyMembership.h"

#include<list>

class trainingClasses
{
   private: list<fuzzyMembership*> classes;
            list<fuzzyMembership*>::iterator it;

        trainingClasses();
        void addClasse(fuzzyMembership *c);
        void removeClasse(fuzzyMembership *c);
        void exibeClasses();
        list<fuzzyMembership*> getClasses();
};

#endif // TRAININGCLASSES_H
