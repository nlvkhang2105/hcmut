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
    } else if (!(a + b > c) || !(a + c > b) || !(b + c > a)){
        cout << "NOT A TRIANGLE";
    } 
    if ((a == b) && (a == c)){
        cout << " The triangle is equilateral";
    }
    if(((a == b) && (b != c)) || (( b == c ) && (a != c)) || ((a == c) && (a != b))){
        cout << "The triangle is isosceles";
    } else cout << "The triangle is scalene";
    return 0;
}