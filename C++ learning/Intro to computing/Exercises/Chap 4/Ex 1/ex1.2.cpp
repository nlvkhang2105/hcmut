#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    int wind = 130;
    int pressure = 985;
    int rain = 220;
    float river = 4.6;
    bool tide = true;
    bool strongstorm = (wind >= 120) && (pressure <= 980);
    //cin >> rain >> river >> tide;
    bool floodrisk = (rain > 200) || ((river > 4.5) && tide);
    bool safe = (!strongstorm && !floodrisk);
    cout << "Floodrisk: "  << floodrisk << endl;
    cout << "Strongstorm: " << strongstorm << endl;
    cout << "Safety: " << safe;
    return 0;
}