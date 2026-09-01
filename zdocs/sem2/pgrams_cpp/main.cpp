#include <iostream>

class mainMenu
{
    std::string auth;

public:
    mainMenu() : auth("Guest"){}
    void options() const
    {
        std::cout << "1. Orders\n";
        std::cout << "2. Customers\n";
        std::cout << "3. Management\n";
        std::cout << "4. Exit\n";
        int choice(0); std::cin >> choice;

        if (choice == 1) 
        {
            std::cout << "1. Take a new order\n";
            if (auth == "admin")
            {
                std::cout << "2. Edit an order\n";
                std::cout << "3. Delete an order\n";
            }
        }
    }
};