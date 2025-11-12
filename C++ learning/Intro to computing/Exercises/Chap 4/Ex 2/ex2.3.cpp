#include<iostream>
#include<string>

using namespace std;
int main(){
    string id_card;
    int age;
    int fare;
    const int BASE_FARE = 20000;
    cout << "Enter your card ID (e.g., 12345-STUDENT, 56789-WORKER): ";
    getline(cin , id_card);
    cout << "Enter your age: ";
    cin >> age;
    string type = id_card.substr(6);
    if((type == "DISABLED") || (type == "CHILD" && age < 7) || (type == "ELDERLY" && age >= 60)){
        fare = BASE_FARE * 0.25;
    } else {
        fare = BASE_FARE;
    }
    cout << "Your fare is: " << fare;
    return 0;
}