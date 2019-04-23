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
        VM(string name,string hostname,string ip,string port,string kvnargs,Date *created,bool stare);
        virtual ~VM();
        //VM(const VM &);
        VM& returnare(string);
         void afisare();
         friend ostream & operator<<(ostream & os,const Resurse & p);
         string gethostname(){return hostname;}
         string getnume(){return name;}
         string getip(){return ip;}
         string getport(){return port;}
         string getkvnargs(){return kvnargs;}
         Date & getcreated(){return  *created;}
         void scriere(ostream & os);
         string gettype(){return "VM";}
         ostream & afisare(ostream &);
        VM&  getob();
        //VM();
    private:
        string hostname;
        string ip;
        string  port;
        Date *created;
        string kvnargs;



};

#endif // VM_H
