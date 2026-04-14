/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2026
* Date: 27.01.2026
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "water_seven.h"

using namespace std;

int main(int argc, const char * argv[]) {
    char character[FIXED_CHARACTER][MAX_NAME];
    int hp[FIXED_CHARACTER];
    int skill[FIXED_CHARACTER];
    char duel[FIXED_CHARACTER][MAX_NAME];
    int shipHP;
    int repairCost;
    int conflictIndex;
    char cipherText[70];
    char resultText[100];
    cout << FIXED_CHARACTER << '\n';
    if(argc < 2){
        cout << "Input file missing" << '\n';
        return 1;
    }
    // Check task 0
    cout << "----------TASK 0----------\n"; 
    bool can_run = readInput(argv[1], character, hp, skill, shipHP, repairCost);
    cout << "Task 0 results:" << '\n';
    cout << (can_run? "Can run" : "Can't run") << '\n';
    cout << "Characters: " << '\n';
    for(int i = 0; i < FIXED_CHARACTER; i++){
        if(character[i][0]=='\0'){
            continue;
        }
        cout << character[i] << char(32) << hp[i] << char(32) << skill[i] << '\n'; 
    }
    cout << "Going Merry: " << shipHP << char(32) << repairCost << '\n';
    cout << "----------END TASK 0----------\n\n";
    // Check task 1
    repairCost = damageEvaluation(shipHP, repairCost);
    cout << "----------TASK 1----------\n";
    cout << "The repair cost for the ship is: " << repairCost << '\n';
    cout << "----------END TASK 1----------\n\n";
    // Check task 2
    conflictIndex = conflictSimulation(character, hp, skill, shipHP, repairCost);
    cout << "----------TASK 2----------\n";
    cout << "The conflictindex is: " << conflictIndex << '\n';
    cout << "----------END TASK 2----------\n\n";
    // Check task 3
    cout << "----------TASK 3----------\n";
    resolveDuel(character, hp, skill, conflictIndex, repairCost, duel);
    cout << "\n----------END TASK 3----------\n\n";
    // Check task 4
    cout << "----------TASK 4----------\n";
    strcpy(cipherText,"ISNK4UH BTS #15");
    decodeCP9Message(character, hp, skill, 10, 21, cipherText, resultText);
    cout << "\n----------END TASK 4----------\n\n";
    // Check task 5
    cout << "----------TASK 5.1----------\n";
    int rows = 3;
    int cols = 3;
    int grid[MAX_GRID][MAX_GRID] = {
        {0, 1, 0},
        {1,-1, 1},
        {0, 0, 0}
    };
    int dangerLimit = analyzeDangerLimit(grid, rows, cols);
    cout << dangerLimit;
    cout << "\n----------END TASK 5.1----------\n\n";

    cout << "----------TASK 5.2----------\n";
    bool canGo = evaluateRoute(grid, rows, cols, dangerLimit);
    cout << canGo;
    cout << "\n----------END TASK 5.2----------\n\n";
    return 0;
}
