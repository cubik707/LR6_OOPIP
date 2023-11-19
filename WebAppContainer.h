#pragma once
#include "WebApp.h"
#include "Validator.h"
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

	static WebAppContainer* instance;
	WebAppContainer() { current_arr_index = 0; };
public:
	static WebAppContainer* getInstance();
	WebAppContainer(const WebAppContainer&) = delete;
	WebAppContainer& operator=(WebAppContainer&) = delete;
	~WebAppContainer();

	void readFromFile(ContainerType cT);
	void fillContainer(ifstream& file, ContainerType cT);
	
	void printContainer(ContainerType cT);
	void printTableFields(int length);

};

