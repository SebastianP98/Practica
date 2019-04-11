#include <iostream>
#include <list>
using namespace std;
#include "Date.h"
#include "Carti.h"
#include "Resurse.h"
#include "VM.h"

// starea v-a fi doar 0-ptr nerezervat si 1 ptr rezervat

int main()
{


    Resurse *c1=new Carti("carte1","autor1","isbn1");
    cout<<"afisareina";
    Carti *c2=new Carti("carte2","autor2","isbn2");

    Carti *c3=new Carti("carte3","autor3","isbn3");


    Date *d1=new Date(11,2,2019);
    Date *d2=new Date(12,1,2007);
    Date *d3=new Date(1,4,1998);

    VM * v1=new VM("nume1","hostname1","ip1","port1","kvargs1",d1);

    VM * v2=new VM("nume2","hostname2","ip2","port2","kvargs2",d1);

    VM * v3=new VM("nume3","hostname3","ip3","port3","kvargs3",d1);
    list<Resurse*>l;
    l.push_back(c1);
    l.push_back(c2);
    l.push_back(c3);

    l.push_back(v1);
    l.push_back(v2);
    l.push_back(v3);

    cout<<"afisare";
    for(auto &x : l)
        x->afisare();
     int op;
     cin>>op;
     switch (op){
         case 1:{
         string d;
         cin >> d;
         for(auto &x : l)
            if(x->name == d)
            {
                x->returnare(d);
                x->afisare();
            }

         }
         break;
           case 2:{
           string d;
           cin >> d;
           for(auto &x : l)
                if(x->name == d)
                {
                    x->rezervare();
                    x->afisare();
                }
           }
           break;
           case 3:
            {
                string d;
                cin >> d;
                for(auto &x : l)
                    if(x->name == d)
                    {
                        x->anulare();
                        x->afisare();
                    }
            }
            break;
     }
}
