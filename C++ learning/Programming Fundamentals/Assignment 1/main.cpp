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
    int shipHP;
    int repairCost;
    if(argc < 2){
        cout << "Input file missing" << '\n';
        return 1;
    }
    bool can_run = readInput(argv[1], character, hp, skill, shipHP, repairCost);
    // Check task 0
    cout << "Task 0 results:" << '\n';
    cout << (can_run? "Can run" : "Can't run") << '\n';
    cout << "Characters: " << '\n';
    for(int i = 0; i < FIXED_CHARACTER; i++){
        cout << character[i] << char(32) << hp[i] << char(32) << skill[i] << '\n'; 
    }
    cout << "Going Merry: " << shipHP << char(32) << repairCost << '\n';
    return 0;
}
