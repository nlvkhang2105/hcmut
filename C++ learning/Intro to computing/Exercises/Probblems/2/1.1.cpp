#include<iostream>

using namespace std;
int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    long long int factorial = number;
    int i = number;
    while( i > 1){
        --i;
        factorial = factorial * i;
    }
    cout << factorial;
    return 0;
}