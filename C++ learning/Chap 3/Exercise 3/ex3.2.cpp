#include <iostream>
#include <math.h>     
#include <iomanip>   

using namespace std;
int main() {
    double energy_GigaJoules;
    cout << "Enter the earthquake energy in Gigajoules: ";
    cin >> energy_GigaJoules;
    double energy_Joules = energy_GigaJoules * pow(10, 9);
    double magnitude = (log10(energy_Joules) - 4.8) / 1.5;
    cout << "The energy released was " << energy_GigaJoules << " gigajoules." << endl;
    cout << "The calculated magnitude (M) is: ";
    cout << fixed << setprecision(2) << magnitude << endl;
    return 0;
}