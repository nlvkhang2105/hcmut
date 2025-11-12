#include<iostream>
#include<math.h>

using namespace std;
int main(){
    float a, b, c, x1, x2, x;
    cout << "ax^2 + bx + c" << endl;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    float delta;
    delta = (pow(b,2)) - (4 * a * c);
    if( delta > 0){
        x1 = (- b + sqrt(delta)) / 2 * a;
        x2 = (- b - sqrt(delta)) / 2 * a;
        cout << "The equation has 2 real roots: " << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }else if( delta == 0){
        x = -b / (2 * a);
        cout << "The equation has one real root" << endl;
        cout << "x = " << x << endl;
    } else cout << "The equa tion has no real root (delta < 0)";
    return 0;
}