#ifndef RESURSE_H
#define RESURSE_H
using namespace std;
#include <iostream>
class Resurse
{
    public:
        Resurse(string name);
        virtual ~Resurse();
        //Resurse(const Resurse & p);
        Resurse();
        virtual Resurse& returnare(string a)=0;
        virtual void afisare()=0;
         void rezervare();
         void anulare();
        string  name;
        bool stare;
};

#endif // RESURSE_H
