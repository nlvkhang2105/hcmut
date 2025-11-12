#include<bits\stdc++.h>

using namespace std;
int main(){
    int pass = 6967;
    int attempt = 1;
    int input;
    while (attempt < 3){
        cout << "Input:";
        cin >> input;
        if(input != pass){
            cout << "NUH UH" << endl;
            attempt++;
        }
        if(input == pass){
            cout << "Good";
            return 0;
        }
        cout << "Fuck off nigga";
    }
    return 0;
}