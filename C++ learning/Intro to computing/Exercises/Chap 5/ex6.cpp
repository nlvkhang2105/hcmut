#include<iostream>
#include<cmath>
using namespace std;

double getSquareDifference(double value, double mean){
    double diff = pow((value - mean),2);
    return diff;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    double data[n];
    int sum = 0;
    cout << "Enter " << n << " numbers: ";
    for(int i = 0; i < n; i++){
        cin >> data[i];
        sum += data[i];
    }
    double mean = sum / n;
    double sumOfSquares = 0.0;
    for(int i = 0; i < n; i++){
        double sqDiff = getSquareDifference(data[i], mean);
        sumOfSquares += sqDiff;
    }
    double variance = sumOfSquares / n;
    double stdDeviation = sqrt(variance);
    cout << "Mean:  " << mean << '\n';
    cout << "Standard Deviation: " << stdDeviation;
    return 0;
}