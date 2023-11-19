#include "Menu.h"
#include <Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Menu menu;
	menu.showContainerMenu();

	return 0;
}