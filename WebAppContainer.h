#pragma once
#include "WebApp.h"
#include <vector>
#include <list>
#include <array>

enum class ContainerType
{
	Vector,
	List,
	Array
};

using namespace std;
class WebAppContainer
{
private:
	vector<WebApp> apps_vector;
	list<WebApp> apps_list;
	array<WebApp, 20> app_array;
	int current_arr_index;
public:
	void readFromFile(ContainerType cT);
	void fillContainer(ifstream& file, ContainerType cT);
};

