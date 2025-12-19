#include<bits/stdc++.h>

using namespace std;
bool checkprime(int number){
    if(number < 2) return false;
    for(int i = 2; i <= sqrt(number); i++){
        if(number % i == 0){
            return false;
        }
    } 
    return true;
} 
int main(){
    int number;
    cin >> number;
    if(checkprime(number)){
        cout << "Is a prime number";
    } else cout << "Not a prime number";
    return 0; 
}