#include "MenuUI.h"

#include <iostream>
#include <string>

MenuUI::MenuUI(Services &services) : services(services) {}

void MenuUI::start()
{
    std::cout << "Build your Car" << std::endl;

    while (true)
    {
        std::string command;
        std::cin >> command;

        if (command.empty())
        {
            continue;
        }

        if (command == "add")
        {

            std::string bodyStyle;
            std::cout << "body style: ";
            std::cin >> bodyStyle;
            std::cout << std::endl;

            std::string engineType;
            std::cout << "engine type: ";
            std::cin >> engineType;
            std::cout << std::endl;

            int autonomy = 1;

            if (engineType == "Electric")
            {
                std::cout << "autonomty: ";
                std::cin >> autonomy;
                std::cout << std::endl;
            }

            this->services.addCar(bodyStyle, engineType, autonomy);
            Car addedCar = this->services.getLatestCarAdded();

            // we need to get the latest car added
            std::cout << "latest car added computed price: " << addedCar.computePrice() << std::endl;
        }
        else if (command == "cars")
        {
            std::vector<Car> cars = this->services.getCars();

            if (cars.size() == 0)
            {
                std::cout << "no cars" << std::endl;
                continue;
            }

            for (const Car &car : cars)
            {
                std::cout << "engine type: " << car.getEngineType() << std::endl;
                std::cout << "body style: " << car.getBodyStyle() << std::endl;
                std::cout << "car base price: " << car.getBasePrice() << std::endl;
                std::cout << "total price: " << car.computePrice() << std::endl;
                std::cout << std::endl;
            }
        }
    }
}