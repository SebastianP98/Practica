  #include "Resurse.h"
using namespace std;
#include <iostream>
  #include "Carti.h"
#include <string.h>
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
    cout<<isbn<<" "<<autor << endl;

}
ostream & operator<<(ostream &os,Carti & p)
{
    return p.afisare(os);
}

void Carti::scriere(ostream & os)
{
    os<<this->getnume()<<","<<this->getautor()<<" "<<this->getisbn()<<" "<<this->getstare();
}
