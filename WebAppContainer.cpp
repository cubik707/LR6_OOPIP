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
            throw runtime_error("������ � �������� �����.");
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
    cout << setw(5) << "| �" << setw(20) << "| ��������";
    cout << setw(20) << "| ���������";
    cout << setw(15) << "| ������������";
    cout << setw(15) << "| �������" << "|" << endl;
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
        cout << "������������ ����� � array!" << endl;
    }
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

