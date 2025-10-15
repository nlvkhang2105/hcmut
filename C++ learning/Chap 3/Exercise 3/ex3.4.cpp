#include <iostream>  
#include <math.h>     
#include <iomanip>   

using namespace std;
int main() {
    const double g = 9.81; 
    double water_depth;     
    double angle_degrees; 
    cout << "Enter the water depth (h) in meters: ";
    cin >> water_depth;
    cout << "Enter the seabed slope angle (alpha) in degrees: ";
    cin >> angle_degrees;
    double angle_rad = angle_degrees * (M_PI / 180.0);
    double wave_speed = sqrt(g * water_depth * tan(angle_rad));
    cout << "The approximate speed of the tsunami is: " << fixed << setprecision(2) << wave_speed << " m/s.";
    return 0; 
}