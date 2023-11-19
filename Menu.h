#pragma once
#include <iostream>
#include "WebAppContainer.h"
#include "Validator.h"

enum class ContainerType
{
	Vector,
	List,
	Array
};

using namespace std;
class Menu
{
public:
	void showContainerMenu();
	void showUserMenu(ContainerType cT);
};

