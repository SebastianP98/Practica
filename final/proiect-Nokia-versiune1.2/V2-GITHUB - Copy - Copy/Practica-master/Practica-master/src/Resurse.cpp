#include "Resurse.h"
using namespace std;
#include <iostream>
#include <string.h>
#include <sstream>
#include <list>
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

string Resurse::toString()
{
    stringstream ss;
    ss<<name<<" "<<stare<<endl;
    string s=ss.str();
    return s;
}
bool Resurse ::operator()(list<shared_ptr<Resurse>>l,shared_ptr<Resurse> it)
{
   for(auto &a:l)

 if(a->toString()==it->toString())
     return false;
 return true;

}

bool Resurse::  func(list<shared_ptr<Resurse>>l,shared_ptr<Resurse>r)
{

    bool exist=[](list<shared_ptr<Resurse>> l,shared_ptr<Resurse> c)-> bool{

      for (auto &x:l)
        if (x->toString()==c->toString())
            return false;
      return true;
    }(l,r);
   return exist;



}
