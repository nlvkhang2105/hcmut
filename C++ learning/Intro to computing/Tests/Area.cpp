#include <iostream>
using namespace std;
int main(){
    int r;
    double pi = 3.14;
    double A;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    A = r*r*pi;
    cout << "Area = "<< A;
    return 0;
}