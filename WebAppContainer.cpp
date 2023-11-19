#include "WebAppContainer.h"

WebAppContainer* WebAppContainer::instance = nullptr;

WebAppContainer* WebAppContainer::getInstance() {
    if (instance == nullptr) {
        instance = new WebAppContainer();
    }
    return instance;
}

WebAppContainer::~WebAppContainer()
{
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

void WebAppContainer::readFromFile(ContainerType cT)
{
    ifstream file;
    try {
        file.open("webapps.txt");
        if (file.bad()) {
            throw runtime_error("Ошибка в открытии файла.");
        }
        if (file.good()) {
            fillContainer(file, cT);
        }

        file.close();
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        exit(0);
    }
}

void WebAppContainer::printTableFields(int length)
{
    printLine(length);
    cout << setw(5) << "| №" << setw(20) << "| Название";
    cout << setw(20) << "| Создатель";
    cout << setw(15) << "| Пользователи";
    cout << setw(15) << "| Рейтинг" << "|" << endl;
    printLine(length);
}

void WebAppContainer::addToList(const WebApp& webApp)
{
    apps_list.push_back(webApp);
}

void WebAppContainer::addToArray(const WebApp& webApp)
{
    if (current_arr_index < app_array.size()) {
        app_array[current_arr_index++] = webApp;
    }
    else {
        throw runtime_error("Недостаточно места в array!");
    }
}

void WebAppContainer::removeFromVector(int index) {
    if (index >= 0 && index < apps_vector.size()) {
        apps_vector.erase(apps_vector.begin() + index);
    }
}

void WebAppContainer::removeFromList(int index) {
    auto it = apps_list.begin();
    advance(it, index);
    if (it != apps_list.end()) {
        apps_list.erase(it);
    }
}

void WebAppContainer::removeFromArray(int index) {
    if (index >= 0 && index < current_arr_index) {
        for (int i = index; i < current_arr_index - 1; ++i) {
            app_array[i] = app_array[i + 1];
        }
        --current_arr_index;
    }
}

//void WebAppContainer::editInCointainer(int index, ContainerType cT, string& name)
//{
//    if (cT == ContainerType::Vector) {
//        if (index >= 0 && index < apps_vector.size()) {
//            apps_vector[index].setName(name);
//        }
//    }
//    if (cT == ContainerType::List) {
//        auto it = apps_list.begin();
//        advance(it, index);
//        if (it != apps_list.end()) {
//            it->setName(name);
//        }
//    }
//    if (cT == ContainerType::Array) {
//        if (index >= 0 && index < current_arr_index) {
//            app_array[index].setName(name);
//        }
//    }
//}


int WebAppContainer::searchByName(const string& name, ContainerType cT)
{
    switch (cT) {
    case ContainerType::Vector:
        return findNameInVector(name);
    case ContainerType::List:
        return findNameInList(name);
    case ContainerType::Array:
        return findNameInArray(name);
    }
}

int WebAppContainer::findNameInVector(const string& name) {
    auto it = find_if(apps_vector.begin(), apps_vector.end(),
        [&name](const WebApp& app) { return app.getName() == name; });
    if (it != apps_vector.end()) {
        return distance(apps_vector.begin(), it);
    }
    return -1;
}

int WebAppContainer::findNameInList(const string& name) {
    auto it = find_if(apps_list.begin(), apps_list.end(),
        [&name](const WebApp& app) { return app.getName() == name; });
    if (it != apps_list.end()) {
        return distance(apps_list.begin(), it);
    }
    return -1;
}

int WebAppContainer::findNameInArray(const string& name) {
    for (int i = 0; i < current_arr_index; ++i) {
        if (app_array[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

void WebAppContainer::printContainer(ContainerType cT)
{
    int length = 74, i = 1;

    printTableFields(length);

    switch (cT) {
    case ContainerType::Vector:
        for (auto& app : apps_vector) {
            cout << left << setw(5) << "| " + to_string(i++);
            app.print();
        }
        break;

    case ContainerType::List:
        for (auto& app : apps_list) {
            cout << left << setw(5) << "| " + to_string(i++);
            app.print();
        }
        break;

    case ContainerType::Array:
        for (int index = 0; index < current_arr_index; ++index) {
            cout << left << setw(5) << "| " + to_string(i++);
            app_array[index].print();
        }
        break;
    }
    printLine(length);
}

void WebAppContainer::addToVector(const WebApp& webApp)
{
    apps_vector.push_back(webApp);
}

void WebAppContainer::fillContainer(ifstream& file, ContainerType cT)
{
    WebApp webApp;
    if (cT == ContainerType::Vector) {
        apps_vector.clear();
        while (file >> webApp) {
            apps_vector.push_back(webApp);
        }
    }
    if (cT == ContainerType::List) {
        apps_list.clear();
        while (file >> webApp) {
            apps_list.push_back(webApp);
        }
    }
    if (cT == ContainerType::Array) {
        for (int i = 0; i < app_array.size() and file >> webApp; ++i) {
            app_array[i] = webApp;
            ++current_arr_index;
        }
    }
}

