#include <iostream>
#include <string>

using namespace std;
int main() {
    string full_name; 
    int P;                
    cout << "Enter the Full Name: ";
    cin >> full_name;
    cout << "Enter the fixed length of the First Name (P): ";
    cin >> P;
    string first_name(full_name, 0, P);
    cout << "The First Name is: " << first_name <<   endl;
    return 0;
}