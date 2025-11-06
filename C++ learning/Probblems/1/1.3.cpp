#include<iostream>

using namespace std;
int main(){
    int a;
    int b;
    int c;
    int x;
    int y;
    int z;
    cin >> a >> b >> c >> x >> y >> z;
    cout << (!(++a > b) && (c++ >= b)) << endl;
    cout << (x + y * 2 < z * 2 - 3 && y++ <= z) << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    return 0;
}