  #include "Resurse.h"
using namespace std;
#include <iostream>
  #include "Carti.h"
#include <string.h>
#include <sstream>
#include <list>
Carti::Carti(string  name,string autor,string  isbn):Resurse(name)
{
     this->autor=autor;
     this->isbn=isbn;

}
Carti::Carti(string  name,string autor,string  isbn,bool stare):Resurse(name,stare)
{
     this->autor=autor;
     this->isbn=isbn;

}

 Carti & Carti:: returnare(string  a)
{


     if( name==a)
          return * this;
}
ostream & Carti::afisare(ostream & o)
{

  o<<this->getnume()<<","<<this->getautor()<<","<<this->getisbn()<<","<<this->getstare();
  return o;
}
Carti::~Carti()
{

}
void Carti::afisare()
{
    cout<<"afisare ";
    cout<<name << " ";
    cout<<isbn<<" "<<autor <<" "<<stare<< endl;

}
ostream & operator<<(ostream &os,Carti & p)
{
    return p.afisare(os);
}

void Carti::scriere(ostream & os)
{
    os<<this->getnume()<<","<<this->getautor()<<" "<<this->getisbn()<<" "<<this->getstare();
}

string Carti::toString()
{
      stringstream ss;
      ss<<this->getnume()<<" "<<this->getautor()<<" "<<this->getisbn()<<" "<<this->getstare();
      string s=ss.str();

  return s;
}
bool Carti ::operator()(list<shared_ptr<Resurse>>l,shared_ptr<Carti> it)
{
   for(auto &a:l)

 if(a->toString()==it->toString())
     return false;
 return true;

}

 bool Carti::  func(list<shared_ptr<Resurse>>l,shared_ptr<Carti>c)
{
    //shared_ptr<Carti>c1=shared_ptr<Carti>(c);
    bool exist=[](list<shared_ptr<Resurse>>l,shared_ptr<Carti> c)-> bool{

      for (auto &x:l)
      {

       if (x->toString()==c->toString())
            return false;
      }
      return true;
    }(l,c);
return exist;

}
