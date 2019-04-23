#include "Customer.h"
#include "Admin.h"
#include "Resurse.h"
#include "VM.h"
#include "Carti.h"
#include "Date.h"


class MainMenu
{
    std::list<std::shared_ptr<Carti>> cartiPtrList;
    std::list<std::shared_ptr<VM>> VMPtrList;
public:
    MainMenu()
    {

    }
    std::list<std::shared_ptr<Carti>> &getCartiList()
    {
        return cartiPtrList;
    }
    std::list<std::shared_ptr<VM>> &getVMList()
    {
        return VMPtrList;
    }
    void addBook(Carti &x)
    {
        cartiPtrList.push_back(make_shared<Carti>(x));
    }
    void addVM(VM &x)
    {
        VMPtrList.push_back(make_shared<VM>(x));
    }
    virtual void menu();
};

class CustomerMenu : public MainMenu
{
    customers customers_;
public:
    void menu();
    void menuSpecificCustomer(std::shared_ptr<customer> & specificCustomer);
};

class AdminMenu : public MainMenu
{
    admin admins_;
public:
    void menu();
};
