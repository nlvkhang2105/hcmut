#include<iostream>
using namespace std;

bool isPassable(int altitude){
    if(altitude < 100){
        return true;
    } else return false;
}

int main(){
    int terrainMap[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> terrainMap[i][j];
        }
    }
    
}