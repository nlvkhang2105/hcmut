#include<iostream>
#include<math.h>

using namespace std;
int main(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int i = 2;
    while(i < sqrt(number)){
        if(number % i == 0){
            cout << "NUH UH";
            return 1;
        }
        i++; 
    }
    return 0;
}