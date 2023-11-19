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
			addWebApp(cT);
			break;
		case 3:
			removeWebApp(cT);
			break;
		case 4:
			editWebApp(cT);
			break;
		case 5:
			searchWebApp(cT);
			break;
		case 6:
			
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
	cout << "������� �������� ���-����������: ";
	name = Validator::getValidStr();
	Validator::convert(name);

	cout << "������� �������������: ";
	creator = Validator::getValidStr();
	Validator::convert(creator);

	cout << "������� ���������� �������������: ";
	count_of_users = Validator::getIntVar(0, INT_MAX);

	cout << "������� ������� ����������: ";
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
	cout << "���-���������� ������� ���������!";
}

void Menu::removeWebApp(ContainerType cT)
{
	cout << "������� ��� ���-����������, ������� �� ������ �������: ";
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
		cout << "���������� ������� �������!" << endl;
	}
	else {
		cout << "������ ���������� ��� � ���� ������!" << endl;
	}
	return;
}

void Menu::editWebApp(ContainerType cT)
{
	cout << "������� ��� ���-����������, ������� �� ������ ��������: ";
	string name = Validator::getValidStr();
	Validator::convert(name);
	int index = WebAppContainer::getInstance()->searchByName(name, cT);
	if (index != -1) {
		editMenu(cT, index);
		cout << "���������� ������� �������!" << endl;
	}
	else {
		cout << "������ ���������� ��� � ���� ������!" << endl;
	}
	return;
}

void Menu::editMenu(ContainerType cT, int index)
{
	while (true)
	{
		cout << left << "��� �� ������ ��������? " << endl;
		cout << "1 - ���" << endl;
		cout << "2 - �������������" << endl;
		cout << "3 - ���������� �������������" << endl;
		cout << "4 - �������" << endl;
		cout << "0 - �����" << endl;
		int choice = Validator::getIntVar(0, 4);
		string name, creator;
		int count_of_users;
		double rating;
		switch (choice) {
		case 1:
			cout << "������� ����� ���: ";
			name = Validator::getValidStr();
			Validator::convert(name);
			WebAppContainer::getInstance()->editName(index, cT, name);
			break;
		case 2:
			cout << "������� ������ �������������: ";
			creator = Validator::getValidStr();
			Validator::convert(creator);
			WebAppContainer::getInstance()->editCreator(index, cT, creator);
			break;
		case 3:
			cout << "������� ����� ���������� �������������: ";
			count_of_users = Validator::getIntVar(0, INT_MAX);
			WebAppContainer::getInstance()->editCountOfUsers(index, cT, count_of_users);
			break;
		case 4:
			cout << "������� ����� ������: ";
			rating = Validator::getDoubleVar(0, 10);
			WebAppContainer::getInstance()->editRating(index, cT, rating);
			break;
		case 0:
			return;
		}
	}
}

void Menu::searchWebApp(ContainerType cT)
{
	while (true)
	{
		cout << left << "�� ���� �� ������ ���������� �����: " << endl;
		cout << "1 - ���" << endl;
		cout << "2 - �������������" << endl;
		cout << "0 - �����" << endl;
		int choice = Validator::getIntVar(0, 2);
		string name, creator;
		int index;
		switch (choice) {
		case 1:
			cout << "������� ����� ���: ";
			name = Validator::getValidStr();
			Validator::convert(name);
			index = WebAppContainer::getInstance()->searchByName(name, cT);
			if (index != -1) {
				WebAppContainer::getInstance()->printContainerItem(cT, index);
			}
			else {
				cout << "���������� � ����� ��������� �� �������!" << endl;
			}
			break;
		case 2:
			cout << "������� ������ �������������: ";
			creator = Validator::getValidStr();
			Validator::convert(creator);
			index = WebAppContainer::getInstance()->searchByCreator(creator, cT);
			if (index != -1) {
				WebAppContainer::getInstance()->printContainerItem(cT, index);
			}
			else {
				cout << "���������� � ����� �������������� �� �������!" << endl;
			}
			break;
		case 0:
			return;
		}
	}
}

