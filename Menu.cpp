#include "Menu.h"

void Menu::showContainerMenu()
{

	cout << left << "Выберите контейнер: " << endl;
	cout << "1 - Администратор" << endl;
	cout << "2 - Пользователь" << endl;
	cout << "0 - Выход" << endl;
	choice = validInt.getVar(0, 2);


	Inventory* inventory = Inventory::getInstance();
	switch (choice) {
	case 1:
		admin->displayMenu();
		break;
	case 2:
		cout << "Введите ваш бюджет: " << endl;
		budget = validDouble.getVar(0, INT_MAX);
		user->setBudget(budget);
		user->displayMenu();
		break;
	case 0:
		exit(0);
	}
}
