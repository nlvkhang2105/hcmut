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
        if(conflictIndex == 255){
            return conflictIndex;
        }
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
        
        int skillLuffy = 0, skillUsopp = 0;
        char supChar[FIXED_CHARACTER][MAX_NAME];
        int support[FIXED_CHARACTER];
        int cost[FIXED_CHARACTER];
        int numSupports = 0;
        for(int i = 0; i < FIXED_CHARACTER; i++){
            string name = character[i];
            if(name.find("LUFFY") != string::npos){
                skillLuffy = skill[i];
            } else if(name.find("USOPP") != string::npos){
                skillUsopp = skill[i];
            } else {
                strcpy(supChar[numSupports], character[i]);
                support[numSupports] = skill[i];
                cost[numSupports] = (hp[i] % 10) + 1;
                numSupports++;
            }
        }
        int U = skillUsopp + (conflictIndex / 20) + (repairCost / 500);
        int bestCost = 999;
        int bestSize = 999;
        int bestMask = -1;
        int totalCombinations = 32;
        for (int mask = 0; mask < totalCombinations; mask++) {
            int currentSupport = 0;
            int currentCost = 0;
            int currentSize = 0;
            for (int j = 0; j < numSupports; j++) {
                if ((mask >> j) & 1) { 
                    currentSupport += support[j];
                    currentCost += cost[j];
                    currentSize++;
                }
            }
            if (skillLuffy + currentSupport >= U) {
                if (currentCost < bestCost || (currentCost == bestCost && currentSize < bestSize)) {
                    bestCost = currentCost;
                    bestSize = currentSize;
                    bestMask = mask;
                }
            }
        }
        for(int i = 0; i < FIXED_CHARACTER; i++){
            duel[i][0] = '\0';
        }
        int duelIndex = 0;
        if (bestMask != -1) {
            for (int j = 0; j < numSupports; j++) {
                if ((bestMask >> j) & 1) {
                    strcpy(duel[duelIndex], supChar[j]);
                    duelIndex++;
                }
            }
        }
    for (int i = 0; i < FIXED_CHARACTER; i++) {
        if (duel[i][0] != '\0') {
            cout << duel[i] << " ";
        }
    }
}
// Task 4
void decodeCP9Message(char character[FIXED_CHARACTER][MAX_NAME], 
    int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER], int conflictIndex, 
    int repairCost, char cipherText[], char resultText[]){
        int charSum = 0;
        int position = 0;
        int checksum_origin;
        int checksum;
        
        while(cipherText[position] != '#' && cipherText[position] != '\0'){
            charSum += (int)cipherText[position];
            position++;
        }
        checksum_origin = int(cipherText[position+1] - '0') * 10 + int(cipherText[position+2] - '0');
        checksum = charSum % 100;
        if(checksum != checksum_origin){
            strcpy(resultText,"\0");
            return;
        }
        int cipherLen = position + 1;
        int key = (conflictIndex + repairCost) % 26;
        int blockSize = (key % 5) + 4;
        int numBlocks = (cipherLen + blockSize - 1) / blockSize;
        char splittedBlocks[numBlocks][blockSize + 1];
        position = 0;
        for(int i = 0; i < numBlocks; i++){
            int charsLeft = cipherLen - position;
            int curBlockLen;
            if(charsLeft < blockSize){
                curBlockLen = charsLeft - 1;
            } else curBlockLen = blockSize;
            int j = curBlockLen - 1;
            while(j >= 0 && position < cipherLen && cipherText[position] != '#'){
                splittedBlocks[i][j] = cipherText[position];
                cout << "Reading " << cipherText[position] << " to coords " << i << ' ' << j << endl;
                j--;
                position++;
            }
            splittedBlocks[i][curBlockLen] = '\0';
        }
        cout << endl;
        char tempResult[numBlocks][blockSize + 1];
        bool isValid = false;
        for(int i = 0; i < numBlocks; i++){
            int tempChar; 
            char decodedChar;
            for(int j = 0; j < blockSize + 1; j++){
                int curChar = splittedBlocks[i][j];
                if(curChar >= 65 && curChar <= 90){
                    tempChar = curChar - 65;
                    tempChar -= key;
                    if(tempChar < 0) tempChar += 26;
                    decodedChar = tempChar + 65;
                } else if(curChar >= 97 && curChar <= 122){
                    tempChar = curChar - 97;
                    tempChar -= key;
                    if(tempChar < 0) tempChar += 26;
                    decodedChar = tempChar + 97;
                } else if(curChar >= 48 && curChar <= 57){
                    tempChar = curChar - 48;
                    tempChar -= (key % 10);
                    if(tempChar < 0) tempChar += 10;
                    decodedChar = tempChar + 48;
                } else decodedChar = curChar;
                tempResult[i][j] = decodedChar;
            }
            if(strstr(tempResult[i],"CP9") != NULL || strstr(tempResult[i],"ENIESLOBBY") != NULL){
                isValid = true;
            }
            if(i == 0){
                strcpy(resultText,tempResult[i]);
            } else strcat(resultText,tempResult[i]);
        }
        if(isValid){
            strcat(resultText,"_TRUE");
        } else strcat(resultText,"_FALSE");
        cout << resultText << endl;
    }

// Task 5
int analyzeDangerLimit(int grid[MAX_GRID][MAX_GRID], int rows, int cols){
    int dangerLimit = 0;
    int maxRowSum;
    int maxCell = grid[0][0];
    for(int i = 0; i < rows; i++){
        int rowSum = 0;
        for(int j = 0; j < cols; j++){
            if(grid[i][j] < 0){
                continue;
            }
            rowSum += grid[i][j];
            if(grid[i][j] > maxCell){
                maxCell = grid[i][j];
            }
        }
        if(i == 0 || rowSum > maxRowSum){
            maxRowSum = rowSum;
        }
    }
    dangerLimit = maxRowSum + maxCell;
    return dangerLimit;
}


bool evaluateRoute(int grid[MAX_GRID][MAX_GRID], int rows, int cols, int dangerLimit){
    return false;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
