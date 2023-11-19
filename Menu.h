#pragma once
#include <iostream>
#include "WebAppContainer.h"
#include "Validator.h"

using namespace std;
class Menu
{
public:
	void showContainerMenu();
	void showUserMenu(ContainerType cT);

	void addWebApp(ContainerType cT);
	void removeWebApp(ContainerType cT);
	void editWebApp(ContainerType cT);
	void editMenu();
};

