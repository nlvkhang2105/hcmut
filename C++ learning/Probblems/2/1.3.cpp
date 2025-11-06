#include<bits\stdc++.h>

using namespace std;
int main(){
    srand(time(NULL));
    int number = rand() % 101;
    cout << number << endl;
    int i;
    while(i != number){
        cout << "Enter a number: ";
        cin >> i;
        if(i < number){
            cout << "smol pp" << endl;
            continue;
        }
        if(i > number){
            cout << "pp too big" << endl;
            continue;
        }
    }
    cout << "yes" << endl;
}