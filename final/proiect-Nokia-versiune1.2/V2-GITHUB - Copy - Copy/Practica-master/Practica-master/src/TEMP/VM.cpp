#include "VM.h"
#include "Date.h"
using namespace std;
#include <iostream>
#include "Resurse.h"
#include <string.h>
VM::VM(string a,string b,string c,string d,string e,Date *g,int h):Resurse(a,h)
{

      hostname=b;
      ip=c;
      port=d;
      kvnargs=e;
      created=g;
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
  cout<<name;
   cout<<hostname<<" "<<ip<<" "<<port<<" "<<kvnargs<<*created;
}
