#include "WebApp.h"

WebApp::WebApp()
    : name("-"), creator("-"), count_of_users(0), rating(0.0)
{
}

WebApp::WebApp(const string& name, const string& creator, int count_of_users, double rating)
	: name(name), creator(creator), count_of_users(count_of_users), rating(rating)
{
}

void WebApp::print() const
{
   cout.setf(ios::left);
   cout << "| " << setw(18) << name;
   cout << "| " << setw(20) << creator;
   cout << "| " << setw(13) << count_of_users;
   cout << "| " << fixed << setprecision(2) << setw(13) << rating << "|" << endl;
    cout.unsetf(ios::left);
}

ofstream& operator<<(ofstream& out, const WebApp& webApp)
{
    out << webApp.name << "|" << webApp.creator << "|" << webApp.count_of_users << "|" << webApp.rating << endl;
    return out;
}

ifstream& operator>>(ifstream& is, WebApp& webApp)
{
    getline(is, webApp.name, '|');
    getline(is, webApp.creator, '|');
    is >> webApp.count_of_users;
    is.ignore(1, '|');
    is >> webApp.rating;
    is.ignore(1, '\n');
    return is;
}
