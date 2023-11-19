#include "WebAppContainer.h"

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

