#include "Menu.h"

void Menu::showContainerMenu()
{
	while (true)
	{
		printLine(40);
		cout << left << "Выберите контейнер: " << endl;
		cout << "1 - Vector" << endl;
		cout << "2 - List" << endl;
		cout << "3 - Array" << endl;
		cout << "0 - Выход" << endl;
		printLine(40);
		int choice = Validator::getIntVar(0, 3);
		switch (choice) {
		case 1:
			WebAppContainer::getInstance()->readFromFile(ContainerType::Vector);
			showUserMenu(ContainerType::Vector);
			break;
		case 2:
			WebAppContainer::getInstance()->readFromFile(ContainerType::List);
			showUserMenu(ContainerType::List);
			break;
		case 3:
			WebAppContainer::getInstance()->readFromFile(ContainerType::Array);
			showUserMenu(ContainerType::Array);
			break;
		case 0:
			exit(0);
		}
	}	
}

void Menu::showUserMenu(ContainerType cT)
{

}
