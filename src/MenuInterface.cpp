#include "MenuInterface.h"

void MainMenu::menu()
{
	int value;
	std::cout << "Select a number coresponding to your needs to continue:\n";
	std::cout << "1.Administrator mode!\n";
	std::cout << "2.Customer mode!\n";
	std::cout << "3.Exit!\n";
	std::cin >> value;
	if(value == 1)
	{
		AdminMenu menuA;
		menuA.menu();
	}
	else if(value == 2)
	{
		CustomerMenu menuC;
		menuC.menu();
	}
	else if(value == 3)
	{
		std::cout << "Thank you, we hope to see you again soon!\n";
		exit(1);
	}
	else
	{
		std::cout << "Please select a valid option!\n";
		this->menu();
	}
}

void CustomerMenu::menu()
{
	int value;
	std::cout << "\nHello dear customer!\n";
	std::cout << "Please select a number coresponding to your needs to continue:\n";
	std::cout << "1.Sign up!\n";
	std::cout << "2.Sign in!\n";
    std::cout << "3.Go back to previous menu!\n";
    std::cout << "4.Exit!\n";
	std::cin >> value;
	switch(value)
	{
		case 1 :
                {
                    std::string username, password,Name;
                    int CNP,Age;
                    std::map<int,std::string> CNPNam;
                    std::map<std::string,std::string> Cred;
                    std::cout << "\nEnter username: ";std::cin >> username;
                    std::cout << "\nEnter password: ";std::cin >> password;
                    std::cout << std::endl;
                    for(auto &x : customers_.customersPtrList)
                    {
                        if(x->getUsername() == username)
                        {
                            std::cout << "\nUsername already exists!Registration canceling!";
                            this->menu();
                        }
                    }
                    std::cout << "\nEnter CNP: ";std::cin >> CNP;
                    std::cout << "\nEnter Name: ";std::cin >> Name;
                    std::cout << "\nEnter Age: ";std::cin >> Age;
                    CNPNam.insert(std::pair<int,std::string>(CNP,Name));
                    Cred.insert(std::pair<std::string,std::string>(password,username));
                    customer newCustomer(CNPNam,Age,Cred);
                    std::shared_ptr<customer> Temp;
                    Temp = std::make_shared<customer>(newCustomer);
                    customers_.addCustomer(Temp);
                    this->menu();
                }
                break;
                case 2:
                {
                    int flag=0;
                    std::string signUsername, signPassword;
                    std::cout << "\nPlease add your username:";std::cin >> signUsername;
                    std::cout << "\nPlease add your password:";std::cin >> signPassword;
                    for(auto &y : customers_.customersPtrList)
                    {
                        if(y->getUsernameViaPassword(signPassword) == signUsername)
                        {
                            menuSpecificCustomer(y);
                            flag =1;
                        }
                    }
                    if(flag == 0)
                    {
                        std::cout << "\nUser not found, please register first!";
                        this->menu();
                    }
                }
                break;
                case 3:
                {
                    this->MainMenu::menu();
                }
                break;
                case 4:
                {
                    std::cout << "\nThank you, we hope to see you again soon!";
                    exit(1);
                }
	}
}

void AdminMenu::menu()
{
    std::string adminPassword;
    std::cout << "\nWhat is the password? ";
    std::cin >> adminPassword;
    if(admins_.verifyPassword(adminPassword))
    {
        int value1;
        std::cout << "\nWelcome admin, please one of the following operations: ";
        std::cout << "\n1. Add product";
        std::cout << "\n2. Change password";
        std::cout << "\n3. Return to main menu";
        std::cout << "\n4. Exit\n";
        std::cin >> value1;
        switch(value1)
        {
            case 1:
            {
                int value2;
                std::cout << "\nWhat resource would you like to add ?";
                std::cout << "\n5. Add VMs";
                std::cout << "\n6. Add Books\n";
                std::cin >> value2;
                switch(value2);
                {
                    case 5:
                    {
                        std::string name;
                        std::string author;
                        std::string isbn;
                        std::cin >> name;
                        std::cin >> author;
                        std::cin >> isbn;
                        Carti carte(name,author,isbn);
                        this->addBook(carte);
                    }
                    break;
                    case 6:
                    {
                            std::string name;
                            std::string hostname;
                            std::string ip;
                            std::string  port;
                            Date *created;
                            std::string kvnargs;
                            std::cout << "\nName: ";std::cin >> name;
                            std::cout << "\nHostname: ";std::cin >> hostname;
                            std::cout << "\nIP: ";std::cin >> ip;
                            std::cout << "\nPort: ";std::cin >> port;
                            int d,m,y;
                            std::cout << "\nDay the VM was requested ";cin >> d;
                            std::cout << "\nMonth the VM was requested ";cin >> m;
                            std::cout << "\nYear the VM was requested ";cin >> y;
                            created = new Date(d,m,y);
                            std::cout << "\nKvnargs: ";std::cin >> kvnargs;
                            VM vmDeCreat(name,hostname,ip,port,kvnargs,created);
                            this->addVM(vmDeCreat);
                    }
                }
            }
            break;
            case 2:
            {
                std::string newPass;
                std::cout << "\nPick a new password: ";
                std::cin >> newPass;
                admins_.changePassword(newPass);
                this->menu();
            }
            break;
            case 3:
            {
                this->MainMenu::menu();
            }
            break;
            case 4:
            {
                std::cout << "Thank you, we hope to see you again soon!\n";
                exit(1);
            }
            break;
        }
    }
    else
    {
        std::cout << "\nPassword incorrect!";
        this->menu();
    }
}

void CustomerMenu::menuSpecificCustomer(std::shared_ptr<customer> & specificCustomer)
{
    int value;
    std::cout << "\nPick an item from the menu below Mr/Mrs." << specificCustomer->getName();
    std::cout << "\n1.Rent a product\n";
    std::cout << "2.Account settings\n";
    std::cout << "3.Return to main menu!\n";
    std::cout << "4.Exit!\n";
    std::cin >> value;
    switch(value)
    {
        /*case 1:
        {
            int rentedCar;
            rentedCar = listOfCars.showCars();
            if(rentedCar >= 0)
            {
                std::list<car>::iterator it = listOfCars.carList.begin();
                if(rentedCar >= 1)
                {
                    while(rentedCar > 0)
                    {
                        it++;
                        rentedCar--;
                    }
                }
                if(it->numberInStock_ > 0)
                {
                    it->buy();
                    std::cout << "\nThank you for renting the car! The car will arrive at your doorsteps and the driver will recieve the payment!";
                    menuSpecificCustomer();
                }
                else
                {
                    std::cout << "\nNo more cars in stock, please select another car!";
                    menuSpecificCustomer();
                }
            }
            else
                menuSpecificCustomer();
        }
        break;*/
        case 1:
        {
            std::cout << "\nWhat would you like to rent ? ";
            std::cout << "\n1.Books ";
            std::cout << "\n2.Virtual Machines(VMs)\n";
            int value;
            std::cin >> value;
            switch(value)
            {
                case 1:
                {
                    for(auto &x : this->getCartiList())
                    {
                        x->afisare();
                    }
                }
                break;
                case 2:
                {
                    for(auto &x : this->getVMList())
                    {
                        x->afisare();
                    }
                }
                break;
            }
        }
        break;
        case 2:
        {
            int valueCase3;
            std::cout << "\n1.Change password";
            std::cout << "\n2.Change username\n";
            std::cin >> valueCase3;
            if(valueCase3 == 1)
            {
                std::string newPass;
                std::cout << "\nAdd the new password: ";
                std::cin >> newPass;
                specificCustomer->changePassword(newPass);
            }
            if(valueCase3 == 2)
            {
                std::string newUser;
                std::cout << "\nAdd the new username: ";
                std::cin >> newUser;
                specificCustomer->changeUsername(newUser);
            }
            menuSpecificCustomer(specificCustomer);
        }
        break;
        case 3:
        {
            menu();
        }
        break;
        case 4:
        {
            std::cout << "Thank you, we hope to see you again soon!\n";
	    exit(1);
        }
    }
}
