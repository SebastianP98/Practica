#ifndef RESURSE_H
#define RESURSE_H
using namespace std;
#include <iostream>
class Resurse
{
    public:
        Resurse(string name);
        Resurse(string name,bool stare);
        virtual ~Resurse();
        //Resurse(const Resurse & p);
        Resurse();
        virtual Resurse& returnare(string a)=0;
        virtual void afisare()=0;
        void rezervare();
        void anulare();
        virtual string gettype(){return "Resurse";}

        friend ostream & operator<<(ostream & os,Resurse & p);

        bool getstare(){return stare;}
        virtual Resurse & getob(){}
        virtual ostream & afisare(ostream &);
        string  name;
        bool stare;
};

#endif // RESURSE_H
