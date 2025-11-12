#include <iostream>
#include <math.h>     
#include <iomanip>   

using namespace std;
int main() {
    const double amplitude = 5.0;
    const double angleInDegrees = 30.0;
    double angleInRadians = angleInDegrees * (M_PI / 180.0);
    double height = amplitude * sin(angleInRadians);
    cout << "The Tsunami wave height is: ";
    cout << fixed << setprecision(2) << height << " meters." << endl;
    return 0;
}