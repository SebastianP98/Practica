#ifndef ADMIN_H
#define ADMIN_H
#include <list>
#include <vector>
#include <algorithm>
#include "customer.h"

class admin
{
private:
    std::string password_ = "Admin";
public:
    admin()
    {

    }
    void changePassword(std::string &password)
    {
        password_ = password;
    }
    bool verifyPassword(std::string &pass)
    {
        if(password_ == pass)
            return true;
        else
            return false;
    }
};

#endif /* ADMIN_H */

