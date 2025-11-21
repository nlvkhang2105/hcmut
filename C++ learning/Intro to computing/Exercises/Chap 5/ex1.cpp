#include<iostream>
using namespace std;

int main(){
    int quizScores[8];
    int sum = 0;
    int aces = 0;
    int fails = 0;
    for(int i = 0; i < 8; i++){
        cin >> quizScores[i];
        if(quizScores[i] == 10){
            aces++;
        } else if(quizScores[i] < 4){
            fails++;
        }
        sum += quizScores[i];
    }
    double avg = (double)sum / 8;
    cout << "Average: " << avg << '\n';
    cout << "Aces: " << aces << '\n';
    cout << "Fails: " << fails << '\n';
    return 0;
}
