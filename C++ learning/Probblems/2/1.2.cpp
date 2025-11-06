#include<iostream>
#include<string>

using namespace std;
int main(){
    string number;
    cout << "Enter a number: ";
    cin >> number;
    int length = number.length();
    int i = 1;
    int sum = 0;
    string digits;
    int sumdigits;
    while (i < length){
        i++;
        digits = number.substr(i,1);
        //sumdigits += 
        cout << stoi(digits);
    }
    return 0;
}