#include "Resurse.h"
using namespace std;
#include <iostream>
#include <string.h>
Resurse::Resurse(string name)
{
   this->name=name;
   stare=0;

}

Resurse::Resurse(string name,bool stare)
{
   this->name=name;
   this->stare=stare;

}
Resurse::~Resurse()
{

}

void Resurse::rezervare()
{
    stare=true;
}
void Resurse::anulare()
{
    stare=false;
}
ostream & Resurse::afisare(ostream &o)
{
o<<this->name<<"  "<<this->stare;
return o;

}
ostream  & operator<<(ostream & os,Resurse &r)
{
 return r.afisare(os);
}
