#include<iostream>
/*sybau*/
using namespace std;
int main() {
        cout << "Hello World!" << endl;
        string name;
        string date_of_birth;
        short current_year;
        cout << "Please enter your name: ";
        getline(cin, name);
        cout << "Please enter your date of birth: ";
        cin >> date_of_birth;
        cout << "Please enter current year: ";
        cin >> current_year;  
        cout << "Name: " << name << endl << "Date of birth: " << date_of_birth << endl;
        cout << current_year << " - 2007 = " << current_year - 2007 << endl;
        system("pause");
        return 0;
}