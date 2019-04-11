#ifndef VM_H
#define VM_H
#include "Date.h"
using namespace std;
#include <iostream>
#include "Resurse.h"
#include<string.h>
class VM:public Resurse
{
    public:
        VM(string name,string hostname,string ip,string port,string kvnargs,Date *created);
        virtual ~VM();
        //VM(const VM &);
        VM& returnare(string);
         void afisare();
        //VM();
    private:
        string hostname;
        string ip;
        string  port;
        Date *created;
        string kvnargs;


};

#endif // VM_H
