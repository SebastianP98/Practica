#ifndef DATE_H
#define DATE_H
using namespace std;
#include <iostream>

class Date
{
    public:
        Date(int a,int b,int c);
        virtual ~Date();
        Date(const Date& p);
        friend ostream & operator<<(ostream& os,const Date& a);
    private:
        int zi;
        int luna;
        int an;
};

#endif // DATE_H
