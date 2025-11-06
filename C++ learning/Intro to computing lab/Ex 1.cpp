#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    int a, b;
    float c;
    cin >> a >> b;
    c = a + b;
    cout << a << " + " << b << " = " << a + b << endl;
    c = a - b;
    cout << a << " - " << b << " = " << a - b << endl;
    c = a * b;
    cout << a << " * " << b << " = " << a * b << endl;
    c = a / (double)b;
    cout << fixed << setprecision(2) << a << " / " << b << " = "  << a / b << endl;
    return 0;
}
