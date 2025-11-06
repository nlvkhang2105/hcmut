#include<iostream>

using namespace std;
int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if((number % 2 != 0) && (number % 3 != 0) && (number % 5 != 0) && (number % 7 != 0)){
        cout << "It's a prime number";
    } else cout << "NUH UH";
    return 0;
}