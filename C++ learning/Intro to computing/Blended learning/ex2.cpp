#include<iostream>
#include<cmath>

using namespace std;
int main(){
    int n;
    int test;
    cout << "Enter a number: ";
    cin >> n;
    if(n % 2 != 0){
        cout << n << " is not a perfect number\n";
        return 0;
    } else{
        for(int i = 2; i < sqrt(n); i++){
            test = pow(2,i - 1) * (pow(2,i) - 1);
            if(test == n){
                cout << n << " is a perfect number\n";
            }
        }
    }
    return 0;
}