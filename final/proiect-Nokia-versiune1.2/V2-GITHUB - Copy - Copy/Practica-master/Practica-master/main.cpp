#include <iostream>
#include <list>
using namespace std;
#include "Date.h"
#include "Carti.h"
#include "Resurse.h"
#include "VM.h"
#include <fstream>
#include <list>
#include <algorithm>
#include <iterator>
// starea v-a fi doar 0-ptr nerezervat si 1 ptr rezervat
// optiunea cu care continui este 1 si daca vrei sa termini este 0!!!!!!!!!!!!!!!
#include <memory>
#include <sstream>
#include <vector>
list<shared_ptr<Resurse>>l;
static void citireCarti(string fis)
{    ifstream in;
     in.open(fis);
     string nume;
     string autor;
     string isbn;
     string  stare1;
     bool stare;
     string token;
     string line;
     string delimiter="\n";
    while ( getline(in,line,';'))
    {
     stringstream check1(line);
     cout<<"*"<<line<<"*"<<endl;
     string intermediate;
     int pos1 = line.find(delimiter);
     line.erase(0, pos1 + delimiter.length());
     if(line=="")
     in.close();
     else{
    stringstream check1(line);
    vector <string> tokens;
     while(getline(check1, intermediate,','))
       {
        tokens.push_back(intermediate);
        cout<<"*"<<intermediate<<"*"<<endl;
       }
    vector<string>::iterator it=tokens.begin();
    nume=it[0];
    autor=it[1];
    isbn=it[2];
    stare1=it[3];
    if (stare1=="true")
        stare=1;
    else
        stare=0;
    //Carti* ob=new Carti(nume,autor,isbn,stare);
    l.push_back(shared_ptr<Carti>(new Carti(nume,autor,isbn,stare)));
    cout<<"urmeaza afisare"<<"*"<<line<<"*";
    }
    }
    in.close();
}
static void citireVM(string fis)
{
    bool stare;
    ifstream in;
    in.open(fis);
    string line;
   string intermediate;
   string delimiter="\n";

   while (getline(in,line,';'))
    {
     stringstream check1(line);
     int pos1 = line.find(delimiter);
     line.erase(0, pos1 + delimiter.length());
     if(line=="")
     in.close();
    else
    {
    stringstream check1(line);
    vector <string> tokens;
    while(getline(check1, intermediate, ','))
    {
        tokens.push_back(intermediate);

    }
    stringstream geek(tokens[0]);
    int x = 0;
    geek >> x;
    stringstream geek1(tokens[1]);
    int y = 0;
    geek1 >> y;
    stringstream geek2(tokens[2]);
    int z = 0;
    geek2 >> z;
    if (tokens[8]=="true")
         stare=true;
      else
         stare=false;
    Date *dd=new Date(x,y,z);
    l.push_back(shared_ptr<VM>(new VM(tokens[3],tokens[4],tokens[5],tokens[6],tokens[7],dd,stare)));
    }
   }
     in.close();

}
void addlista()
{
     string tip,nume,autor,isbn,hostname,ip,port,kvnargs;
    int zi,luna,an;

    cout<<"alege ce vrei sa introduci(date despre carti sau VM-uri->CARTE/VM)"<<endl;
    cin>>tip;
    if (tip=="CARTE")
   {
    cout<<"Introdu nume"<<endl;
    cin>>nume;
    cout<<"Introdu autor"<<endl;
    cin>>autor;
    cout<<"Introdu isbn"<<endl;
    cin>>isbn;
    shared_ptr<Carti>c1=shared_ptr<Carti>(new Carti(nume,autor,isbn,false));
    cout<<"panaa aici"<<endl;

    if (Carti::func(l,c1)==1)
     l.push_back(shared_ptr<Carti>(c1));
    else
     cout<<"Se repeta resursa "<<endl;

   }
   else
   {
      cout<<"Introdu nume"<<endl;
      cin>>nume;
      cout<<"Introdu hostname"<<endl;
      cin>>hostname;
      cout<<"Introdu ip"<<endl;
      cin>>ip;
      cout<<"Introdu port"<<endl;
      cin>>port;
      cout<<"Introdu kvnargs"<<endl;
      cin>>kvnargs;
      cout<<"Introdu data crearii(zi)"<<endl;
      cin>>zi;
      cout<<"Introdu data crearii(luna)"<<endl;
      cin>>luna;
      cout<<"Introdu data crearii(an)"<<endl;
      cin>>an;
      Date *data=new Date(zi,luna,an);
      shared_ptr<VM>c1=shared_ptr<VM>(new VM(nume,hostname,ip,port,kvnargs,data,false));
        if (VM::func(l,c1)==1)
          l.push_back(shared_ptr<VM>(c1));
        else
          cout<<"Se repeta resursa "<<endl;


   }
}


int main()
{


    citireCarti("text1.txt");
    cout<<"Lungime"<<l.size();

     for(auto &x : l)
        x->afisare();

    citireVM("text2.txt");
    cout<<"Lungime"<<l.size()<<endl;

    cout<<"URMEAZA AFISAREA"<<endl;
    for(auto &x : l)
        x->afisare();

    ofstream in;


    cout<<"AFISARE dupa aduagare"<<endl;
   for(auto &x : l)
        x->afisare();
   in.open("text1.txt");
   in.close();
   in.open("text2.txt");
   in.close();
     int op;
     int ok=1;
     while (ok)
     {
         cout<<endl<<"1.returnare"<<endl<<"2.rezervare"<<endl<<"3.anulare"<<endl<<"4.adaugare lista"<<endl<<"5.afisare"<<endl<<"INTRODU OPTIUNEA"<<endl;
    cin>>op;

     switch (op){
         case 1:{
         string d;
         cout<<"INTRODU numele produsului dorit sa-l returnezi"<<endl;
         cin >> d;
         for(auto &x : l)
            if(x->getname() == d)
            {
                x->returnare(d);
                x->afisare();
            }

         }
         break;
           case 2:{
           string d;
           cout<<"INTRODU numele produsului dorit sa-l rezervi"<<endl;
           cin >> d;
           for(auto &x : l)
                if(x->getname() == d)
                {
                    x->rezervare();
                    x->afisare();
                }
           }
           break;
           case 3:
            {
                string d;
                cout<<"INTRODU numele produsului dorit sa-l anulezi"<<endl;
                cin >> d;
                for(auto &x : l)
                    if(x->getname() == d)
                    {
                        x->anulare();
                        x->afisare();
                    }
            }
            break;
           case 4:
            {
                addlista();
            }
            break;
           case 5:
            {
                 for(auto &x : l)
                  x->afisare();
            }
            break;

       }
       cout<<"Doriti sa iesiti?(1-continuare,0-iesire)"<<endl;
            cin>>ok;

     }
      for(auto & x : l)
       {
           if (x->gettype()=="Carti")
           {
            in.open("text1.txt",ios::app);
            in<<*x<<";\n";
            in.close();
           }
           else
            if (x->gettype()=="VM")
           {

                  in.open("text2.txt",ios::app);
                  in<<*x<<";\n";
                  in.close();

           }
       }

     in.close();

}
