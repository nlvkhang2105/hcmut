#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double a(double radius){
    double area = M_PI * (radius*radius);
    return area;
}
double v(double radius){
    double volume = (4.0 / 3.0) * M_PI * (radius*radius*radius);
    return volume;
}
int main(){
    int radius;
    cout << "Radius: ";
    cin >> radius;
    double area = a(radius);
    double volume = v(radius);
    cout << "Area: " << fixed << setprecision(4) << area << '\n';
    cout << "Volume: " << fixed << setprecision(4) << volume;
    return 0;
}