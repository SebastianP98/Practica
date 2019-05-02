#ifndef CARTI_H
#define CARTI_H
using namespace std;
#include <iostream>
#include "Resurse.h"
#include<string.h>
class Carti:public Resurse
{
    public:
        Carti(string a,string  b, string c ,int d);
        Carti(const Carti &p);
        //Carti();
        virtual ~Carti();
        Carti & returnare(string  a);
        void afisare();

    private:
        string  autor;
        string isbn;
};

#endif // CARTI_H
