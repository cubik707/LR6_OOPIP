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
	while (true)
	{
		cout << left << "Меню: " << endl;
		cout << "1 - Вывод данных" << endl;
		cout << "2 - Добавить данные" << endl;
		cout << "3 - Удалить данные" << endl;
		cout << "4 - Редактировать данные" << endl;
		cout << "5 - Поиск" << endl;
		cout << "6 - Сортировка" << endl;
		cout << "0 - Назад" << endl;
		int choice = Validator::getIntVar(0, 6);
		switch (choice) {
		case 1:
			WebAppContainer::getInstance()->printContainer(cT);
			break;
		case 2:
			addWebApp(cT);
			break;
		case 3:

			break;
		case 0:
			return;
		}
	}
}

void Menu::addWebApp(ContainerType cT)
{
	string name, creator;
	int count_of_users;
	double ratity;
	cout << "Введите название веб-приложения: ";
	name = Validator::getValidStr();
	Validator::convert(name);

	cout << "Введите производителя: ";
	creator = Validator::getValidStr();
	Validator::convert(creator);

	cout << "Введите количество пользователей: ";
	count_of_users = Validator::getIntVar(0, INT_MAX);

	cout << "Введите рейтинг приложения: ";
	ratity = Validator::getDoubleVar(0, 10);
	WebApp webApp(name, creator, count_of_users, ratity);

	switch (cT) {
	case ContainerType::Vector:
		WebAppContainer::getInstance()->addToVector(webApp);
		break;
	case ContainerType::List:
		WebAppContainer::getInstance()->addToList(webApp);
		break;
	case ContainerType::Array:
		try
		{
			WebAppContainer::getInstance()->addToArray(webApp);
		}
		catch (const runtime_error& e)
		{
			cerr << e.what() << endl;
			return;
		}	
		break;
	}
	cout << "Веб-приложение успешно добавлено!";
}

void Menu::removeWebApp(ContainerType cT)
{
	cout << "Введите имя веб-приложения, которое вы хотите удалить: ";
	string name = Validator::getValidStr();
	Validator::convert(name);
	int index = WebAppContainer::getInstance()->searchByName(name, cT);
	if (index != -1) {
		switch (cT) {
		case ContainerType::Vector:
			WebAppContainer::getInstance()->removeFromVector(index);
			break;
		case ContainerType::List:
			WebAppContainer::getInstance()->removeFromList(index);
			break;
		case ContainerType::Array:
			WebAppContainer::getInstance()->removeFromArray(index);
			break;
		}
		cout << "Приложение успешно удалено!" << endl;
	}
	else {
		cout << "Такого приложения нет в базе данных!" << endl;
	}
	return;
}

