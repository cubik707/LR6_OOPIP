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

void WebAppContainer::printContainer(ContainerType cT)
{
    int length = 89, i = 1;

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
        for (const auto& app : app_array) {
            cout << left << setw(5) << "| " + to_string(i++);
            app.print();
        }
        break;
    }
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
        }
    }
}

