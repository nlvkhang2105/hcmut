#include<iostream>
#include<math.h>

using namespace std;
int main(){
    int number;
    int left;
    int right;
    int y;
    cout << "Enter left limit: ";
    cin >> left;
    cout << "Enter right limit: ";
    cin >> right;
    int r = left;
    //cout << "Enter a number: ";
    //cin >> number;
    int i = 2;
    for(;left <= right; left++){
        i = 2;
        while(i < sqrt(r)){
            if(r % i  0){
                cout << r;
                continue;
            }
            i++;
        }
    }
    return 0;
}