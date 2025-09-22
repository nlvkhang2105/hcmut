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
        if (name == "Nguyễn Hiểu Lam" || name == "Nguyen Hieu Lam" || name == "hlam" || name == "nguyen hieu lam") {
                cout << "Hi baby!" << endl;
                cout << "I miss you so much!" << endl;
                cout << "This is a program made by me" << endl;
                system("pause");
                return 0;
        }
        cout << "Please enter your date of birth: ";
        cin >> date_of_birth;
        cout << "Please enter current year: ";
        cin >> current_year;  
        cout << "Name: " << name << endl << "Date of birth: " << date_of_birth << endl;
        cout << current_year << " - 2007 = " << current_year - 2007 << endl;
        system("pause");
        return 0;
}