#include <iostream>
#include <list>
using namespace std;
#include "Date.h"
#include "Carti.h"
#include "Resurse.h"
#include "VM.h"
#include <fstream>
#include <list>
// starea v-a fi doar 0-ptr nerezervat si 1 ptr rezervat
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
     string stare1;
     bool stare;
     string line;

      stringstream check1(line);
    string intermediate;
    cout<<"adaug"<<endl;
    while (!in.eof())
    {
        getline(in,line);
     stringstream check1(line);
    vector <string> tokens;
     while(getline(check1, intermediate,','))
       {
        tokens.push_back(intermediate);

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
    }
    in.close();
    cout<<"afisezzzzzzzzzz";

}
static void citireVM(string fis)
{
    bool stare;
    ifstream in;
    in.open(fis);
    string line;
   string intermediate;


   while (!in.eof())
    {
    getline(in,line);
     if(line=="")
     {
     cout<<"NUUUUUUUUUUUUUUUUUUUUUUUUU";
     in.close();
     }

    cout<<line<<endl;
    stringstream check1(line);
    vector <string> tokens;
    while(getline(check1, intermediate, ','))
    {
        tokens.push_back(intermediate);

    }


    stringstream geek(tokens[0]);

    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    geek >> x;

    // Now the variable x holds the value 12345
    //cout << "Value of x : " << x;


    stringstream geek1(tokens[1]);

    // The object has the value 12345 and stream
    // it to the integer x
    int y = 0;
    geek1 >> y;

    // Now the variable x holds the value 12345
    //cout << "Value of y : " << y;
    stringstream geek2(tokens[2]);


    // The object has the value 12345 and stream
    // it to the integer x
    int z = 0;
    geek2 >> z;


    // Now the variable x holds the value 12345
    //cout << "Value of z : " << z;


    // The object has the value 12345 and stream
    // it to the integer x

      if (tokens[8]=="true")
         stare=true;
      else
         stare=false;


    Date *dd=new Date(x,y,z);
    //VM *ob=new VM(tokens[3],tokens[4],tokens[5],tokens[6],tokens[7],dd,stare);
    //shared_ptr<Resurse>(ob);
    l.push_back(shared_ptr<VM>(new VM(tokens[3],tokens[4],tokens[5],tokens[6],tokens[7],dd,stare)));

    }
    in.close();
    cout<<"Gata"<<endl;

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
    l.push_back(shared_ptr<Carti>(new Carti("nume7","autor7","isbn7",true)));
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
      l.push_back(shared_ptr<VM>(new VM(nume,hostname,ip,port,kvnargs,data,true)));
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
    l.push_back(shared_ptr<Carti>(new Carti("nume5","autor5","isbn5",false)));
    Date * dd1=new Date(11,6,2018);
    l.push_back(shared_ptr<VM>(new VM("nume6","hostname6","ip6","port6","kvnargs6",dd1,true)));

    ofstream in;


    cout<<"AFISARE dupa aduagare"<<endl;
   for(auto &x : l)
        x->afisare();

   in.open("text1.txt");
   in.close();
   in.open("text2.txt");
   in.close();


          //cout<<typeid(dynamic_cast<shared_ptr<Carti>*>(x.get())).name()<<" "<<typeid(shared_ptr<Carti>*()).name()<<endl;
          //cout<<(typeid(x).name()==typeid(shared_ptr<Carti>*()).name());
          //if (typeid(x)==typeid(shared_ptr<Carti>*()))
         /*
         for(auto & x : l)
         {   cout<<endl;
        cout<<"acum este o afisare in plus   "<<dynamic_cast<shared_ptr<Carti>*>(x.get())<<endl;
        cout<<"acum verificam tipul"<<(typeid(x)==typeid(shared_ptr<Carti>*()))<<endl;
        if (dynamic_cast<shared_ptr<Carti>*>(x.get()))
        {
            in.open("text1.txt",ios::app);
           // cout<<"afisare "<<dynamic_cast<Carti*>(x.get())<<endl;
            in<<"afisarepppppppppppppppppppppppppppppp"<<endl;
            in<<x<<endl;
            cout<<"afisarekkkkkkkkkkkkkkkkkkkkkkkkkkkkk "<<x<<endl;
           // x->scriere();
           // cout<<"afisare"<<((shared_ptr<Carti>)x)->scriere()<<endl;
           in.close();
        }
        else
        {
            //if (dynamic_cast<shared_ptr<VM>*>(x.get()));
            //cout<<typeid(*x).name()<<" "<<typeid(shared_ptr<VM>()).name();
            if (typeid(*x).name()==typeid(shared_ptr<VM>()).name())
               {
                  cout<<"BUUUUUUUUUUUUUUUUUUUUUUNNNNNNNNNNNNNAAAAAAAAAAAA";
                  in.open("text2.txt",ios::app);
                  in<<"AFISARE****************";
                  in<<&x<<endl;
                  cout<<"afisare"<<&x<<typeid(x).name()<<shared_ptr<VM>()<<endl;
                  in.close();
               }
        }
        //cout<<"afisare "<<x->scriere()<<endl;
        //in<<"afisare "<<x->scriere()<<endl;

       }
       */
       for(auto & x : l)
       {
           if (x->gettype()=="Carti")
           {
            in.open("text1.txt",ios::app);
            in<<*x<<endl;
            in.close();
           }
           else
            if (x->gettype()=="VM")
           {

                  in.open("text2.txt",ios::app);
                  in<<*x<<endl;
                  in.close();

           }
       }





   /* shared_ptr< Carti >c1=new  shared_ptr <Carti>("carte1","autor1","isbn1");

    shared_ptr< Carti >c2=new shared_ptr <Carti >("carte2","autor2","isbn2");

    shared_ptr< Carti >c3=new shared_ptr <Carti >("carte3","autor3","isbn3");


    Date *d1=new Date(11,2,2019);
    Date *d2=new Date(12,1,2007);
    Date *d3=new Date(1,4,1998);

    shared_ptr< VM > v1=new shared_ptr<VM*>("nume1","hostname1","ip1","port1","kvargs1",d1);

    shared_ptr <VM > v2=new shared_ptr<VM*>("nume2","hostname2","ip2","port2","kvargs2",d1);

    shared_ptr <VM > v3=new  shared_ptr<VM*>("nume3","hostname3","ip3","port3","kvargs3",d1);

    l.push_back(c1);
    l.push_back(c2);
    l.push_back(c3);

    l.push_back(v1);
    l.push_back(v2);
    l.push_back(v3);

*/

     int op;

     int ok=1;
     while (ok)
     {
         cout<<"INTRODU OPTIUNEA"<<endl;
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
           case 4:
            {
                addlista();
            }
            break;

       }
       cout<<"Doriti sa iesiti?"<<endl;
            cin>>ok;

     }

     in.close();

}
