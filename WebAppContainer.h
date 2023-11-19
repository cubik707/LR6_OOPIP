#pragma once
#include "WebApp.h"
#include "Validator.h"
#include <vector>
#include <list>
#include <array>
#include <iterator>

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

	void addToVector(const WebApp& webApp);
	void addToList(const WebApp& webApp);
	void addToArray(const WebApp& webApp);

	void removeFromVector(int index);
	void removeFromList(int index);
	void removeFromArray(int index);

	int searchByName(const string& name, ContainerType cT);
	int findNameInVector(const string& name);
	int findNameInList(const string& name);
	int findNameInArray(const string& name);
	
	void printContainer(ContainerType cT);
	void printTableFields(int length);

};

