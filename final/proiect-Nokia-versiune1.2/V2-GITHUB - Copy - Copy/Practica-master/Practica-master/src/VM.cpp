#include "VM.h"
#include "Date.h"
using namespace std;
#include <iostream>
#include "Resurse.h"
#include <string.h>
#include <sstream>
#include <list>
VM::VM(string name,string hostname,string ip,string port,string kvnargs,Date *created):Resurse(name)
{

      this->hostname=hostname;
      this->ip=hostname;
      this->port=port;
      this->kvnargs=kvnargs;
      this->created=created;
}
VM::VM(string name,string hostname,string ip,string port,string kvnargs,Date *created,bool stare):Resurse(name,stare)
{

      this->hostname=hostname;
      this->ip=hostname;
      this->port=port;
      this->kvnargs=kvnargs;
      this->created=created;
}
/*VM::VM(const VM & p)
{
    if (name != NULL)
        strcpy(name,p.name);
    if (hostname != NULL)
        strcpy(hostname,p.hostname);
    if (ip!=NULL)
        strcpy(ip,p.ip);
    if (kvnargs!=NULL)
        strcpy(kvnargs,p.kvnargs);
    if (port!=NULL)
        strcpy(port,p.port);
    stare=p.stare;
}*/
VM& VM:: returnare(string  a)
{
     if( name==a)
          return * this;

}

VM::~VM()
{
    /* if (this->hostname!=NULL)
        delete[]this->hostname;
    if (this->ip!=NULL)
        delete[]this->ip;
    if (this->port!=NULL)
        delete[]this->port;
    if (this->kvnargs!=NULL)
        delete[]this->kvnargs;
        */
}
void VM::afisare()
{
    cout<<name << " ";
    cout<<hostname<<" "<<ip<<" "<<port<<" "<<kvnargs<< " " << *created<<" "<<stare << endl;
}
ostream & VM::afisare(ostream &o)
{
  o<<this->getcreated().zi<<","<<this->getcreated().luna<<","<<this->getcreated().an<<","<<this->getnume()<<","<<this->gethostname()<<","<<this->getip()<<","<<this->getport()<<","<<this->getkvnargs()<<","<<this->getstare();
return o;
}
ostream & operator<<(ostream & os,VM & p)
{

    return p.afisare(os);
}

void VM::scriere(ostream & os)
{
   os<<this->getcreated().zi<<","<<this-getcreated().luna<<","<<this->getcreated().an<<","<<this->getnume()<<","<<this->gethostname()<<","<<this->getip()<<","<<this->getport()<<","<<this->getkvnargs()<<","<<this->getstare()<<endl;

}

string VM::toString()
 {
     stringstream ss;
    ss<<getnume()<<" "<<getstare()<<" "<<this->getcreated().zi<<" "<<this->getcreated().luna<<" "<<this->getcreated().an<<" "<<this->gethostname()<<" "<<this->getip()<<" "<<this->getport()<<" "<<this->getkvnargs();
    string s=ss.str();
    return s;
}
bool VM ::operator()(list<shared_ptr<Resurse>>l,shared_ptr<VM> it)
{
   for(auto &a:l)

 if(a->toString()==it->toString())
     return false;
 return true;

}

bool VM::  func(list<shared_ptr<Resurse>>l,shared_ptr<VM>m)
{

    bool exist=[](list<shared_ptr<Resurse>> l,shared_ptr<VM> c)-> bool{

      for (auto &x:l)
        if (x->toString()==c->toString())
            return false;
      return true;
    }(l,m);
    return exist;

}
