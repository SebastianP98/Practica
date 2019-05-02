#ifndef RESURSE_H
#define RESURSE_H
using namespace std;
#include <iostream>
#include <list>
#include <memory>
class Resurse
{
    public:
        Resurse(string name);
        Resurse(string name,bool stare);
        virtual ~Resurse();
        Resurse();
        virtual Resurse& returnare(string a)=0;
        virtual void afisare()=0;
        void rezervare();
        void anulare();
        virtual string gettype(){return "Resurse";}

        friend ostream & operator<<(ostream & os,Resurse & p);
        string getname(){return name; }
        bool getstare(){return stare;}
        virtual ostream & afisare(ostream &);
        virtual string toString();
        bool operator ()(list<shared_ptr<Resurse>>,shared_ptr<Resurse>);
         static bool  func(list<shared_ptr<Resurse>>,shared_ptr<Resurse>);
    protected :
        string  name;
        bool stare;
};

#endif // RESURSE_H
