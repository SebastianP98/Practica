#include "Date.h"
using namespace std;
#include <iostream>

Date::Date(int a,int b,int c)
{
     zi=a;
     luna=b;
     an=c;
}
Date::Date(const Date &p)
{
          zi=p.zi;
          luna=p.luna;
          an=p.an;
}
Date::~Date()
{

}
ostream & operator<<(ostream & os,const Date& a)
{
    os<<a.zi<<" "<<a.luna<<" "<<a.an;
    return os;
}
