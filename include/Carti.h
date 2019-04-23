#ifndef CARTI_H
#define CARTI_H
using namespace std;
#include <iostream>
#include "Resurse.h"
#include<string.h>

class Carti : public Resurse
{
    public:
        Carti(string name,string  autor, string isbn);
        Carti(string name,string  autor, string isbn,bool stare);
        virtual ~Carti();
        Carti & returnare(string  a);
        void afisare();
        string getnume(){return name;}
        string getisbn(){return isbn;}
        string getautor(){return autor;}
        friend ostream & operator<<(ostream & os,const Carti & p);
        void scriere(ostream & os);
        string gettype(){return "Carti";}
        ostream & afisare(ostream &);
    private:

        string  autor;
        string isbn;
};

#endif // CARTI_H
