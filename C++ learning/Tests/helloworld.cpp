#include<iostream>
#include<windows.h>
/*sybau*/
using namespace std;
int main() {
        cout << "Hello World!" << endl;
        string name;
        string date_of_birth;
        short current_year;
        int i1, i2, n;
        cout << "Please enter your name: ";
        getline(cin, name);
        cout << "Please enter your date of birth: ";
        cin >> date_of_birth;
        if (name == "Nguyễn Hiểu Lam" || name == "Nguyen Hieu Lam" || name == "hlam" || name == "nguyen hieu lam" || date_of_birth == "20/08/2008" || date_of_birth == "20-08-2008") {
                cout << "Hi baby!" << endl;
                //cout << "I miss you so much!" << endl;
                cout << "How many i_miss_you do u want baby: ";
                cin >> n;
                for (i1 = 0; i1 <= n; i1++){ 
                        cout << "I miss you so muchhhhhh"<< endl;
                        Sleep(5);
                }
                cout << "This is a program made by NLVK" << endl;
                system("pause");
                return 0;
        }
        cout << "Please enter current year: ";
        cin >> current_year;  
        cout << "Name: " << name << endl << "Date of birth: " << date_of_birth << endl;
        cout << current_year << " - 2007 = " << current_year - 2007 << endl;
        for (i2 = 0; i2 < 20; i2++){
                cout << name << endl;
                Sleep(10);
        }
        system("pause");
        return 0;
}