#include "Resurse.h"
using namespace std;
#include <iostream>
#include <string.h>
Resurse::Resurse(string name)
{
   this->name=name;
   stare=0;

}
/*Resurse::Resurse(const Resurse & p)
{
    if (p.name==NULL)
        ;
    else
        name=p.name;
    stare=p.stare;
}
*/
Resurse::~Resurse()
{
    /*if (this->name!=NULL)
        delete[]this->name;
        */
}

void Resurse::rezervare()
{
    stare=true;
}
void Resurse::anulare()
{
    stare=false;
}
