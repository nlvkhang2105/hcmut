#include<iostream>
#include<string>
using namespace std;

int computeStamina(string moves, int hp, double breathingMastery) {
    unsigned long i;
    double reduction = 0;
    for(i = 0; i < moves.length(); i++){
        double costA = 1.0 - breathingMastery;
        double costB = 2.0 - breathingMastery;
        double costC = 3.0 - breathingMastery;
        string move = moves.substr(i,1);
        if(move == "A"){
            reduction += costA;
        }
        if(move == "B"){
            reduction += costB;
        }
        if(move == "C"){
            reduction += costC;
        }
    }
    double remaining = hp - reduction;
    if(remaining <= 0){
        return 0;
    } else return (int)remaining;
}

int main(){
    string combo;
    int hp;
    double breathingMastery;
    cin >> combo >> hp >> breathingMastery;
    cout << computeStamina(combo, hp, breathingMastery);
    return 0;
}