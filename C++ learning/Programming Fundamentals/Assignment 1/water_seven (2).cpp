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
            }else if(test == "LUFFY" || test == "ZORO" || test == "USOPP" || test == "NAMI" || test == "CHOPPER" || test == "SANJI" || test == "ROBIN"){
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
            } else continue;
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
    if(sum == sum_of_digits && sum_of_digits > 0){
        perfNum = true;
    } 
    if(perfNum && shipHP < 455){
        repairCost = (repairCost * 3 + 1) / 2;
        ceil(repairCost);
        if(repairCost > 3000) repairCost = 3000;
        return repairCost;
    } else return ceil(repairCost);
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
        double conflictIndex = (double)skillL - (double)skillU + ((double)repairCost / 100.0) + ((500.0 - (double)shipHP) / 50.0);
        int count = 0;
        if(conflictIndex == 255){
            return conflictIndex;
        }
        while(count < 10){
            double id = fmod(conflictIndex,6.0);
            int idRounded = ceil(id);
            switch(idRounded){
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
            if(conflictIndex>= 255){
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
        int U = ceil(skillUsopp + (conflictIndex / 20.0) + (repairCost / 500.0));
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
        int duelIndex = 0;
        if (bestMask != -1) {
            for (int j = 0; j < numSupports; j++) {
                if ((bestMask >> j) & 1) {
                    strcpy(duel[duelIndex], supChar[j]);
                    duelIndex++;
                }
            }
        }
}
// Task 4
void decodeCP9Message(char character[FIXED_CHARACTER][MAX_NAME], 
    int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER], int conflictIndex, 
    int repairCost, char cipherText[], char resultText[]){
    // 1. Tìm độ dài chuỗi để xác định vị trí chính xác của phần checksum ở cuối
    int len = 0;
    while (cipherText[len] != '\0') {
        len++;
    }

    // Vị trí của ký tự '#' phân cách (luôn cách cuối 2 chữ số)
    int position = len - 3;
    int charSum = 0;

    // Tính checksum bằng cách duyệt chính xác đến vị trí '#' cuối cùng
    for (int i = 0; i < position; i++) {
        charSum += (int)cipherText[i];
    }

    int checksum_origin = (cipherText[position + 1] - '0') * 10 
                        + (cipherText[position + 2] - '0');

    int checksum = charSum % 100;

    if (checksum != checksum_origin) {
        resultText[0] = '\0';
        return;
    }

    // Độ dài phần cipher (trước '#')
    int cipherLen = position;

    int key = (conflictIndex + repairCost) % 26;
    int blockSize = (key % 5) + 4;

    int numBlocks = (cipherLen + blockSize - 1) / blockSize;

    char splittedBlocks[numBlocks][blockSize + 1];

    // Chia block + đảo ngược từng block
    int currentPos = 0;
    for (int i = 0; i < numBlocks; i++) {
        int charsLeft = cipherLen - currentPos;
        int curBlockLen = (charsLeft < blockSize) ? charsLeft : blockSize;

        int j = curBlockLen - 1;
        while (j >= 0 && currentPos < cipherLen) {
            splittedBlocks[i][j] = cipherText[currentPos];
            j--;
            currentPos++;
        }

        splittedBlocks[i][curBlockLen] = '\0'; // terminate
    }

    char tempResult[numBlocks][blockSize + 1];
    resultText[0] = '\0'; // 🔥 init 1 lần

    // Decode từng block
    for (int i = 0; i < numBlocks; i++) {
        int j = 0;

        for (; splittedBlocks[i][j] != '\0'; j++) {
            int curChar = splittedBlocks[i][j];
            int tempChar;
            char decodedChar;

            if (curChar >= 'A' && curChar <= 'Z') {
                tempChar = curChar - 'A';
                tempChar -= key;
                if (tempChar < 0) tempChar += 26;
                decodedChar = tempChar + 'A';
            }
            else if (curChar >= 'a' && curChar <= 'z') {
                tempChar = curChar - 'a';
                tempChar -= key;
                if (tempChar < 0) tempChar += 26;
                decodedChar = tempChar + 'a';
            }
            else if (curChar >= '0' && curChar <= '9') {
                tempChar = curChar - '0';
                tempChar -= (key % 10);
                if (tempChar < 0) tempChar += 10;
                decodedChar = tempChar + '0';
            }
            else {
                decodedChar = curChar;
            }

            tempResult[i][j] = decodedChar;
        }

        tempResult[i][j] = '\0'; // 🔥 terminate đúng

        // Ghép kết quả
        if (i == 0) {
            strcpy(resultText, tempResult[i]);
        } else {
            strcat(resultText, tempResult[i]);
        }
    }

    // 🔥 Check keyword TRÊN TOÀN BỘ CHUỖI ĐÃ GHÉP
    bool isValid = false;
    if (strstr(resultText, "CP9") != NULL || 
        strstr(resultText, "ENIESLOBBY") != NULL) {
        isValid = true;
    }

    // Append TRUE/FALSE
    if (isValid) {
        strcat(resultText, "_TRUE");
    } else {
        strcat(resultText, "_FALSE");
    }
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
    int costMap[rows][cols];
    if(grid[0][0] == -1 || grid[rows - 1][cols - 1] == -1){
        return false;
    }
    costMap[0][0] = grid[0][0];
    for(int i = 1; i < cols; i++){
        if(grid[0][i] == -1 || costMap[0][i-1] >= 9999){
            costMap[0][i] = 9999;
        } else {
            costMap[0][i] = costMap[0][i-1] + grid[0][i];
        }
    }
    for(int i = 1; i < rows; i++){
        if(grid[i][0] == -1 || costMap[i-1][0] >= 9999){
            costMap[i][0] = 9999;
        } else {
            costMap[i][0] = costMap[i-1][0] + grid[i][0];
        }
    }
    int i = 0;
    int j = 0;
    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if (grid[i][j] == -1) {
                costMap[i][j] = 9999;
            } else{
                int above = costMap[i-1][j];
                int left = costMap[i][j-1];
                costMap[i][j] = grid[i][j] + min(above,left);
            }
        }
    }
    if(costMap[rows-1][cols-1] <= dangerLimit){
        return true;
    } else return false;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
