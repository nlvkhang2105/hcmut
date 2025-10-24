#include<iostream>

using namespace std;
int main(){
    float a, b, c;
    cout << "Enter length of A: ";
    cin >> a;
    cout << "Enter length of B: ";
    cin >> b;
    cout << "Enter length of C: ";
    cin >> c;
    if(a <= 0 || b <= 0 || c <= 0){
        cout << "INVALID LENGTHS";
    } else if( (a + b > c) && (a + c > b) && (b + c > a)){
        cout << "VALID TRIANGLE";
    } else {
        cout << "NOT A TRIANGLE";
    }
    return 0;
}