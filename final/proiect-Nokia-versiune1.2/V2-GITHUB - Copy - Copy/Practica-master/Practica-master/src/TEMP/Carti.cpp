  #include "Resurse.h"
using namespace std;
#include <iostream>
  #include "Carti.h"
#include <string.h>
Carti::Carti(string  a,string b,string  c,int d):Resurse(a,d)
{
     autor=b;
     isbn=c;

}
/*Carti::Carti(const Carti &p):Resurse(const Resurse& f)
{
   if (p.name!=NULL)
     strcpy(name,p.name);
   stare=p.stare;
   if (p.autor!=NULL)
     strcpy(autor,p.autor);
   if (p.isbn!=NULL)
     strcpy(isbn,p.isbn);

}
*/
 Carti & Carti:: returnare(string  a)
{


     if( name==a)
          return * this;
}

Carti::~Carti()
{
   /*if (this->name!=NULL)
        delete[]this->name;
    if (this->autor!=NULL)
        delete[]this->autor;
    if (this->isbn!=NULL)
        delete[]this->isbn;
        */
}
void Carti::afisare()
{
    cout<<"afisare";
  cout<<name;
   cout<<isbn<<" "<<autor;

}
