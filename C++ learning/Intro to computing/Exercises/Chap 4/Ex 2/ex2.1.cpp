#include<iostream>

using namespace std;
int main(){
    int score;
    cout << "Please enter the students's score: ";
    cin >> score;
    if (score >= 90){
        cout << "The student is eligible for scholarship";
    } else {
        cout << "The student is not eligible for scholarship";
    }
    return 0;
}