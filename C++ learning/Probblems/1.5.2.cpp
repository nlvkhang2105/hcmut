#include<iostream>
#include<math.h>

using namespace std;
int main(){
    float weight_pounds;
    float height_inches;
    cout << "Enter your height in inches: ";
    cin >> height_inches;
    cout << "Enter your weight in pounds: ";
    cin >> weight_pounds;
    const float weight_kilo = weight_pounds * 0.45359237;
    const float height_meters = height_inches * 0.0254;
    float BMI = weight_kilo / (height_meters*height_meters);
    cout << "Your BMI is: " << BMI << endl;
    if (BMI < 18.5) {
        cout << "You are a walking skeleton";
    } else if (BMI >= 18.5 && BMI < 25.0){
        cout << "You are a normal nigga";
    } else if (BMI >= 25.0 && BMI < 30.0){
        cout << "Please do some exercises";
    } else (cout <<  "FATASS!!!");
    return 0;
}