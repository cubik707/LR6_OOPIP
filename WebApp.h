#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
class WebApp
{
private:
	string name;
	string creator;
	int count_of_users;
	double rating;
public:
	WebApp(const string& name, const string& creator, int count_of_users, double rating);

    // Геттеры
    string getName() const { return name; }
    string getCreator() const { return creator; }
    int getCountOfUsers() const { return count_of_users; }
    double getRating() const { return rating; }
    // Сеттеры
    void setName(const string& newName) { name = newName; }
    void setCreator(const string& newCreator) { creator = newCreator; }
    void setCountOfUsers(int newCount) { count_of_users = newCount; }
    void setRating(double newRating) { rating = newRating; }

    void print() const;

    friend ofstream& operator<< (ofstream& out, const WebApp& webApp);
    friend ifstream& operator>> (ifstream& is, WebApp& webApp);
};

