#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    int slayerLevel;
    int hp;
    double breathingMastery;
    int hasTalisman;
    char timeOfDay;
    int demonPresence;
    int demonRank;
    double swordSharpness;
    int allyCount;
    int bossHP;
    int totalDamage;
    int specialMoveReady;
    cin >> slayerLevel >> hp >> breathingMastery >> hasTalisman >> timeOfDay >> demonPresence >> demonRank >> swordSharpness 
        >> allyCount >> bossHP >> totalDamage >> specialMoveReady;
    double power = (slayerLevel * 10) + (hp / 10) + (breathingMastery * 50);
    string demonslayerPower; //scene 1 prerequistes
    string gate_open;
    if (power >= 120){ 
        demonslayerPower = "Hashira";
    } else if(80 <= power < 120 ){
        demonslayerPower = "Elite";
    } else if(power < 80){
        demonslayerPower = "Novice";
    }
    cout << "[Scene 1] Rank: " << demonslayerPower << " (power = " << fixed << setprecision(1) << power << ")" << endl;  
    if(hasTalisman == 0){ //scene 2 prerequisites
        gate_open = "Denied: No talisman.";
    } else if((timeOfDay != 'D') && (timeOfDay != 'N')){
        gate_open = "Warning: invalid timeOfDay.";
    } else if((timeOfDay == 'N') && (demonPresence == 1)){
        gate_open = "Open silently.";
    } else gate_open = "Open cautiously.";
    cout << "[Scene 2] " << gate_open << endl;
    string strat; //scene 3 prerequisites
    double adv = (101- demonRank * 15) + swordSharpness * 0.4 + allyCount * 5; 
    if(adv >= 100){
        strat = "Engage head-on";
    } else if(60 <= adv < 100){
        strat = "Harass and probe";
    } else if(adv < 60) {
        strat = "Retreat and regroup";
    } else strat = "Retreat and regroup";
    cout << "[Scene 3] " << strat << " (adv = " << fixed << setprecision(1) << adv << ")" << "\n";
    double finalHP = bossHP - totalDamage; //scene 4 prerequisites
    string final;
    if(finalHP <= 0){
        final = "Boss defeated!";
    } else if((0 < finalHP <= 50) && (specialMoveReady == 1)){
        final = "Use special move to finish!";
    } else final = "Withdraw to heal.";
    cout << "[Scene 4] " << final << " (finalHP = " << (int)finalHP << ")" << endl;
    return 0;
}