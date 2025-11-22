#include<iostream>
using namespace std;

bool isPassable(int altitude){
    if(altitude < 100){
        return true;
    }else return false;
}

int main(){
    int terrainMap[4][4];
    int passableCells = 0;
    bool test;
    cout << "Enter altitudes: ";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> terrainMap[i][j];
        }
    }
    int highestAltitude = terrainMap[0][0];
    int lowestAltitude = terrainMap[0][0];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            test = isPassable(terrainMap[i][j]);
            if(test){
                passableCells++;
            }
            if(terrainMap[i][j] > highestAltitude){
                highestAltitude = terrainMap[i][j];
            }
            if(terrainMap[i][j] < lowestAltitude){
                lowestAltitude = terrainMap[i][j];
            } 
        }
    }
    cout << "Highest altitude: " << highestAltitude << '\n';
    cout << "Lowest altitude: " << lowestAltitude << '\n';
    cout << "Passable cells: " << passableCells << '\n';
    return 0;
}