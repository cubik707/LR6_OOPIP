#pragma once
#include "WebApp.h"
#include "Validator.h"
#include <vector>
#include <list>
#include <array>
#include <iterator>
#include <algorithm>

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

	void editName(int index, ContainerType cT, string& name);
	void editCreator(int index, ContainerType cT, string& creator);
	void editCountOfUsers(int index, ContainerType cT, int count_of_users);
	void editRating(int index, ContainerType cT, double rating);

	int searchByName(const string& name, ContainerType cT);
	int searchByCreator(const string& creator, ContainerType cT);

	void sortByName(ContainerType cT);
	void sortByCreator(ContainerType cT);
	void sortByCountOfUsers(ContainerType cT);
	void sortByRating(ContainerType cT);
	
	void printContainer(ContainerType cT);
	void printTableFields(int length);
	void printContainerItem(ContainerType cT, int index);

	vector<WebApp>& getVector() {
		return apps_vector;
	}
	list<WebApp>& getList() {
		return apps_list;
	}
	array<WebApp, 20>& getArray() {
		return app_array;
	}
};

