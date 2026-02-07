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
                    cout << "Character " << test << " exists, moving on..." << '\n';
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
    int sum = 0;
    bool perfNum = false;
    for(int i = 1; i < sqrt(shipHP); i++){
        if(shipHP % i == 0){
            if(i * i != shipHP){
                sum = sum + i + shipHP / i;
            } else sum +=i;
        }
    }
    if(sum == shipHP){
        perfNum = true;
        cout << "ShipHP is a perfect number" << '\n';
    } else cout << "ShipHP is not a perfect number" << '\n';
    if(perfNum && shipHP < 455){
        repairCost = ((repairCost + repairCost*0.5) * 3 + 1) / 2;
        return repairCost;
    } else return repairCost;
}

// Task 2
int conflictSimulation(
    char character[FIXED_CHARACTER][MAX_NAME], int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER],
    int shipHP, int repairCost){
        return 0;
    }

// Task 3
void resolveDuel(
    char character[FIXED_CHARACTER][MAX_NAME], int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER],
    int conflictIndex, int repairCost, char duel[FIXED_CHARACTER][MAX_NAME]){
        //TODO: Output assign to duel parameter
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
