#include "Menu.h"

void Menu::showContainerMenu()
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
		admin->displayMenu();
		break;
	case 2:
		cout << "������� ��� ������: " << endl;
		budget = validDouble.getVar(0, INT_MAX);
		user->setBudget(budget);
		user->displayMenu();
		break;
	case 0:
		exit(0);
	}
}
