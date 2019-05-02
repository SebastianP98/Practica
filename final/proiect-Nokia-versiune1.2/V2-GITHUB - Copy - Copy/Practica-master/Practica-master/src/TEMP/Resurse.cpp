#include "Resurse.h"
using namespace std;
#include <iostream>
#include <string.h>
Resurse::Resurse(string a,int b)
{
   name=a;
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
    stare=1;
}
void Resurse::anulare()
{
    stare=0;
}
