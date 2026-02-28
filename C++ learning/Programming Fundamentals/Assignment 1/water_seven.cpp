#include "water_seven.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
//Task 0
bool readInput(
    const string &filename,
    char character[FIXED_CHARACTER][MAX_NAME], int hp[FIXED_CHARACTER], 
    int skill[FIXED_CHARACTER], int &shipHP, int &repairCost){
        ifstream inFile(filename);
        if(!inFile){
            return false;
        }
        string line;
        int i = 0;
        while(getline(inFile,line)){
            stringstream ss(line);
            string test;
            ss >> test;
            if(test.empty()) continue;
            if(test == "GOING_MERRY"){
                ss >> shipHP >> repairCost;
                if(shipHP < 0) shipHP = 0;
                if(shipHP > 1000) shipHP = 1000;
                if(repairCost < 0) repairCost = 0;
                if(repairCost > 3000) repairCost = 3000;
                continue;
            }else {
                int tempHP, tempSkill;
                ss >> tempHP >> tempSkill;
                if(tempHP < 0) tempHP = 0;
                if(tempHP > 1000) tempHP = 1000;
                if(tempSkill < 0) tempSkill = 0;
                if(tempSkill > 100) tempSkill = 100;
                int duplicate = -1;
                for(int j = 0; j < i; j++){
                    string temp = character[j];
                    if(test == temp){
                        duplicate = j;
                        break;
                    }   
                }
                if(duplicate == -1){
                    strcpy(character[i],test.c_str());
                    hp[i] = tempHP;
                    skill[i] = tempSkill;
                    i++;
                } else {
                    hp[duplicate] = tempHP;
                    skill[duplicate] = tempSkill;
                    continue;
                }
            }
        }
        inFile.close();
        for (int k = i; k < FIXED_CHARACTER; k++) {
            character[k][0] = '\0'; 
            hp[k] = 0;
            skill[k] = 0;
        }
        return true;
}



// Task 1
int damageEvaluation(int shipHP, int repairCost){
    int sum_of_digits = 0;
    int sum = 0;
    int tempHP = shipHP;
    while(tempHP != 0){
        sum_of_digits += tempHP % 10;
        tempHP /= 10;
    }
    bool perfNum = false;
    for(int i = 1; i < sum_of_digits; i++){
        if(sum_of_digits % i == 0){
            sum += i;
        }
    }
    if(sum == sum_of_digits){
        perfNum = true;
    } 
    if(perfNum && shipHP < 455){
        repairCost = (repairCost * 3 + 1) / 2;
        return repairCost;
    } else return repairCost;
}

// Task 2
int conflictSimulation(
    char character[FIXED_CHARACTER][MAX_NAME], int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER],
    int shipHP, int repairCost){
        int skillL;
        int skillU;
        for(int i = 0; i < FIXED_CHARACTER; i++){
            string temp_name = character[i];
            if(temp_name.find("LUFFY") != string::npos){
                skillL = skill[i];
            }
            if(temp_name.find("USOPP") != string::npos){
                skillU = skill[i];
            }
        }
        int conflictIndex = skillL - skillU + (repairCost / 100) + ((500 - shipHP) / 50);
        int id = conflictIndex % 6;
        int count = 0;
        while(count < 10){
            switch(id){
                case 0:
                    conflictIndex += 255;
                    break;
                case 1:
                    conflictIndex += 20;
                    break;
                case 2:
                    conflictIndex += 50;
                    break;
                case 3:
                    conflictIndex += 70;
                    break;
                case 4:
                    conflictIndex += 90;
                    break;
                case 5:
                    conflictIndex += 100;
                    break;
            }
            if(conflictIndex >= 255){
                break;
            } else count++;
        }
        return ceil(conflictIndex);
    }

// Task 3
void resolveDuel(
    char character[FIXED_CHARACTER][MAX_NAME], int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER],
    int conflictIndex, int repairCost, char duel[FIXED_CHARACTER][MAX_NAME]){
        int ID_main = 0;
        int ID_support = 0;
        int lufID, usID;
        char mainChar[2][MAX_NAME];
        int mainSkill[2];
        char supChar[FIXED_CHARACTER - 2][MAX_NAME];
        int support[FIXED_CHARACTER - 2];
        int cost[FIXED_CHARACTER - 2];
        int teamLuf;
        for(int i = 0; i < FIXED_CHARACTER; i++){
            string tempName = character[i];
            if(tempName == "LUFFY" || tempName == "USOPP"){
                strcpy(mainChar[ID_main],character[i]);
                mainSkill[ID_main] = skill[i];
                if(tempName == "LUFFY"){
                    lufID = ID_main;
                } else usID = ID_main;
                ID_main++;
            } else {
                strcpy(supChar[ID_support],character[i]);
                support[ID_support] = skill[i];
                cost[ID_support] = (hp[i] % 10) + 1;
                ID_support++;
            }
        }
        float UsPower = mainSkill[usID] + (conflictIndex / 20) + (repairCost / 500);
        for(int i = 0; i < FIXED_CHARACTER - 3; i++){
            int minIndex = i;
            int tempCost, tempSupVal;
            for(int j = i + 1; j < FIXED_CHARACTER - 2; j++){
                if(cost[j] < cost[minIndex]){
                    minIndex = j;
                }
            }
            swap(supChar[i],supChar[minIndex]);
            swap(support[i],support[minIndex]);
            swap(cost[i],cost[minIndex]);
        }
        int sumPower = 0;
        int current = 0;
        while(sumPower < UsPower){
            sumPower += support[current];
            strcpy(duel[current],supChar[current]);
            current++;
        }
        for(int i = 0; i <= current; i++){
            cout << duel[i] << '\n';
        }
    }

// Task 4
void decodeCP9Message(char character[FIXED_CHARACTER][MAX_NAME], 
    int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER], int conflictIndex, 
    int repairCost, char cipherText[], char resultText[]){
        //TODO: Output assign to resultText parameter
    }

// Task 5
int analyzeDangerLimit(int grid[MAX_GRID][MAX_GRID], int rows, int cols){
    return 0;
}


bool evaluateRoute(int grid[MAX_GRID][MAX_GRID], int rows, int cols, int dangerLimit){
    return false;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
