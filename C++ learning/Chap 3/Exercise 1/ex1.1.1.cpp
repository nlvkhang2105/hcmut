#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    int a = 2; 
    int b = 0; 
    int c = 2; 
    int d = 5;
    a += 4;
    b = b - a;
    c += a + b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}