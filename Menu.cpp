#include "Menu.h"

void Menu::showContainerMenu()
{
	while (true)
	{
		printLine(40);
		cout << left << "�������� ���������: " << endl;
		cout << "1 - Vector" << endl;
		cout << "2 - List" << endl;
		cout << "3 - Array" << endl;
		cout << "0 - �����" << endl;
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
	while (true)
	{
		cout << left << "����: " << endl;
		cout << "1 - ����� ������" << endl;
		cout << "2 - �������� ������" << endl;
		cout << "3 - ������� ������" << endl;
		cout << "4 - ������������� ������" << endl;
		cout << "5 - �����" << endl;
		cout << "6 - ����������" << endl;
		cout << "0 - �����" << endl;
		int choice = Validator::getIntVar(0, 6);
		switch (choice) {
		case 1:
			WebAppContainer::getInstance()->printContainer(cT);
			break;
		case 2:

			break;
		case 3:

			break;
		case 0:
			return;
		}
	}
}

