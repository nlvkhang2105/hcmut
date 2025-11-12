#include<iostream>
#include<math.h>

using namespace std;
int main(){
    const float POUNDS_TO_KILO = 0.45359237;
    const float INCHES_TO_METERS = 0.0254;
    float weight_pounds;
    float height_inches;
    float weight_kilo;
    float height_meters;
    bool unit_chooser;
    cout << "Choose your unit (0 for Metric, 1 for Imperial):";
    cin >> unit_chooser;
    if (unit_chooser == 1){
        cout << "Enter your height in inches: ";
        cin >> height_inches;
        cout << "Enter your weight in pounds: ";
        cin >> weight_pounds;
        weight_kilo = weight_pounds * POUNDS_TO_KILO;
        height_meters = height_inches * INCHES_TO_METERS;
    } else {
        cout << "Enter your height in meters: ";
        cin >> height_meters;
        cout << "Enter your weight in kilogram: ";
        cin >> weight_kilo;
    }
    float BMI = weight_kilo / (height_meters*height_meters);
    cout << "Your BMI is: " << BMI << endl;
    if (BMI < 18.5) {
        cout << "You are a walking skeleton";
    } else if (BMI >= 18.5 && BMI < 25.0){
        cout << "You are a normal nigga";
    } else if (BMI >= 25.0 && BMI < 30.0){
        cout << "Please do some exercises";
    } else (cout << "FATASS!!!");
    return 0;
}