#include<iostream>
#include<iomanip>
using namespace std;

double calculateAverage(double total, int count){
    double avg = total / count;
    return avg;
}
int main(){
    int n;
    cout << "Enter the number of runners: ";
    cin >> n;
    if(n <= 0){
        cout << "Invalid number ";
        return 0;
    }
    double raceTimes[n];
    double totalTime = 0;
    cout << "Enter the runner's times: ";
    for(int i = 0; i < n; i++){
        cin >> raceTimes[i];
    }
    double fastTime = raceTimes[0];
    double slowTime = raceTimes[0];
    for(int i = 0; i < n; i++){
        if(raceTimes[i] < fastTime){
            fastTime = raceTimes[i];
        } 
        if(raceTimes[i] > slowTime){
            slowTime = raceTimes[i];
        }
        totalTime += raceTimes[i];
    }
    double avg = calculateAverage(totalTime,n);
    cout << fixed << setprecision(2) << "Fastest time: " << fastTime << '\n';
    cout << fixed << setprecision(2) << "Slowest time: " << slowTime << '\n';
    cout << fixed << setprecision(2) << "Average time: " << avg << '\n';
    return 0;
}