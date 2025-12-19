#include<iostream>

using namespace std;
int main(){
    int age;
    cout << "Please enter your age: ";
    cin >> age;
    if(age >= 18){
        cout << "You can join the event";
    } else if(age <= 18){
        bool permission;
        cout << "Do you have parent permission? (0 for no, 1 for yes): ";
        cin >> permission;
        if (permission){
            cout << "You can join with permission";
        } else cout << "You cannot join the event";
    } 
    return 0;
}