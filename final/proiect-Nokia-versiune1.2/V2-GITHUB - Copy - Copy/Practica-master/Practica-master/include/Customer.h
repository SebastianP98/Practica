#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <memory>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include "admin.h"

class customer
{
private:
	std::map<int,std::string> CNPName_;
	int age_;
	std::map<std::string,std::string> creditentials_;
public:
	customer(std::map<int,std::string> CNPName, int age, std::map<std::string,std::string> creditentials)
        {
            CNPName_ = CNPName;
            age_ = age;
            creditentials_ = creditentials;
        }
	std::map<std::string,std::string> &getCreditentials()
	{
		return creditentials_;
	}
        std::string &getName()
        {
            return CNPName_.begin()->second;
        }
	std::string &getUsernameViaPassword(std::string &password)
	{
		return this->creditentials_[password];
	}
        std::string &getUsername()
        {
            return this->creditentials_.begin()->second;
        }
        void changePassword(std::string &newPass)
        {
            std::string temp;
            temp = creditentials_.begin()->second;
            creditentials_.clear();
            creditentials_.insert(std::pair<std::string,std::string>(newPass,temp));

        }
        void changeUsername(std::string &newUser)
        {
            creditentials_.begin()->second = newUser;
        }
};

class customers
{
public:
    customers()
    {

    }
	std::list<std::shared_ptr<customer>> customersPtrList;
	void addCustomer(std::shared_ptr<customer> &X)
	{
		customersPtrList.push_back(X);
	}
};

#endif /* CUSTOMER_H */

