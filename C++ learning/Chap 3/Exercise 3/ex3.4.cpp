#include <iostream>  
#include <math.h>     
#include <iomanip>   

using namespace std;
int main() {
    const double g = 9.81; 
    double waterDepth;     
    double angleInDegrees; 
    cout << "Enter the water depth (h) in meters: ";
    cin >> waterDepth;
    cout << "Enter the seabed slope angle (alpha) in degrees: ";
    cin >> angleInDegrees;
    double angleInRadians = angleInDegrees * (M_PI / 180.0);
    double waveSpeed = sqrt(g * waterDepth * tan(angleInRadians));
    cout << "The approximate speed of the tsunami is: " << fixed << setprecision(2) << waveSpeed << " m/s.";
    return 0; 
}