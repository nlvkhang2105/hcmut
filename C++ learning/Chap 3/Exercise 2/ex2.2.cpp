#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    string name;
    string display_name = "* Name: ";
    string display_age = "* Age: ";
    string age;
    int width_name = 0;
    int width_age = 0;
    int starcount = 0;
    cout << "Please enter your name: ";  
    getline(cin,name);
    cout << "Please enter your age: ";
    cin >> age;
    cout << "Your name is: " << name << endl;
    cout << "Your age is: " << age << endl;
    for(int i = 0; i <= name.length() + 20; i++ ){
        cout << "*";
        starcount ++;
    }
    cout << endl;
    width_name = starcount - (display_name.length() + name.length());
    width_age = starcount - (display_age.length() + age.length());
    cout << display_name << name << setw(width_name) << "*" << endl;
    cout << display_age << age << setw(width_age) << "*" << endl;
    cout << setw(0);
    for(int i = 0; i <= name.length() + 20; i++ ){
        cout << "*";
    }
    cout << endl;
    system("pause");
}