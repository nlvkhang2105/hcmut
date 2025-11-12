#include<iostream>
using namespace std;

int main(){
    int angle;
    cin >> angle;
    if((angle >= 0) && (angle < 90)){
        cout << "First quadrant\n";
    } else if((angle >= 90) && (angle < 180)){
        cout << "Second quadrant\n";
    } else if((angle >= 180) && (angle < 270)){
        cout << "Third quadrant\n";
    } else if((angle >= 270) && (angle < 360)){
        cout << "Fourth quadrant\n";
    }
    return 0;
}