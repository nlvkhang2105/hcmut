#include<iostream>
#include<iomanip>
using namespace std;

double calculateAverage(double total, int count){
    double avg = total / count;
    return avg;
}
int main(){
    int n;
    cin >> n;
    if(n <= 0){
        cout << "Invalid number ";
    }
    double raceTimes[n-1];
    double fastTime = 0;
    double totalTime = 0;
    for(int i = 0; i < n; i++){
        cin >> raceTimes[i];
        if(raceTimes[i] > fastTime){
            fastTime = raceTimes[i];
        }
        totalTime += raceTimes[i];
    }
    double avg = calculateAverage(totalTime,n);
    return 0;
}