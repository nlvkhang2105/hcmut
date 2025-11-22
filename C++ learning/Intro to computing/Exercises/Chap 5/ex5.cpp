#include<iostream>
#include<cmath>
using namespace std;

double calculateDistance(double x1, double y1, double x2,double y2){
    double d = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
    return d; 
}

int main(){
    double r;
    cout << "Enter the radar's effective range: ";
    cin >> r;
    int n;
    cout << "Enter the number of objects to track:";
    cin >> n;
    if(n <= 0){
        cout << "Invalid number of objects";
        return 0;
    }
    double xCoords[n];
    double yCoords[n];
    for(int i = 0; i < n; i++){
        cout << "Enter coordinates for object " << i << ":";
        cin >> xCoords[i] >> yCoords[i];
    }
    int inRangeCount = 0;
    double test;
    for(int i = 0; i < n; i++){
        test = calculateDistance(0,0,xCoords[i],yCoords[i]);
        if(test <= r){
            inRangeCount++;
        }
    }
    char index[inRangeCount];
    for(int i = 0; i < n; i++){
        test = calculateDistance(0,0,xCoords[i],yCoords[i]);
        if(test <= r){
            index[i] = (char)i;
        }
    }
    cout << "Total objects in range:" << inRangeCount << '\n';
    cout << "Indexes of in range objects: ";
    for(int i = 0; i < n; i++){
        cout << index[i];
    }
    return 0;
}