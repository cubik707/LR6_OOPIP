#include "Menu.h"

void Menu::showContainerMenu()
{

	cout << left << "�������� ���������: " << endl;
	cout << "1 - �������������" << endl;
	cout << "2 - ������������" << endl;
	cout << "0 - �����" << endl;
	choice = validInt.getVar(0, 2);


	Inventory* inventory = Inventory::getInstance();
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
