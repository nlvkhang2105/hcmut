#include<iostream>

using namespace std;
int main(){
    int year;
    cin >> year;
    bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    cout << leap;
    if(leap){
        cout << "Leap year\n";
    } else if(!leap ){
        cout <<"Not leap\n";
    }
    return 0;
}