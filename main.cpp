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


    Resurse *c1=new Carti("carte1","autor1","isbn1",0);
    cout<<"afisareina";
    Carti *c2=new Carti("carte2","autor2","isbn2",0);

    Carti *c3=new Carti("carte3","autor3","isbn3",0);


    Date *d1=new Date(11,2,2019);
    Date *d2=new Date(12,1,2007);
    Date *d3=new Date(1,4,1998);

    VM * v1=new VM("nume1","hostname1","ip1","port1","kvargs1",d1,0);

    VM * v2=new VM("nume2","hostname2","ip2","port2","kvargs2",d1,0);

    VM * v3=new VM("nume3","hostname3","ip3","port3","kvargs3",d1,0);
    //v3->afisare();
    list<Resurse*>l;
    l.push_back(c1);
    l.push_back(*c2);
    l.push_back(*c3);

    l.push_back(*v1);
    l.push_back(*v2);
    l.push_back(*v3);

    cout<<"afisare";
    for (list<Resurse> ::iterator it=l.begin();it!=l.end();it++)
        it->afisare();
     int op;
     cin>>op;
     switch (op){
         case 1:{string d; cin>>d;
            for (list<Resurse> ::iterator it1=l.begin();it1!=l.end();it1++)
                  if( it1->name==d)
                    {it1->returnare(d);
                     it1->afisare();}

           }
           case 2:{string d; cin>>d;
            for (list<Resurse> ::iterator it=l.begin();it!=l.end();it++)
                  if( it->name==d)
                    {
                        it->rezervare();
                        it->afisare();

                  }
           }
           case 3:{string d; cin>>d;
            for (list<Resurse> ::iterator it=l.begin();it!=l.end();it++)
                  if( it->name==d)
                    {
                        it->anulare();
                        it->afisare();

                  }
           }
     }
    //c1->afisare();





}
