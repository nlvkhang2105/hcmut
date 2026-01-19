#include<iostream>

using namespace std;

int main(){
    int month;
    int days;
    cin >> month;
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 2:
            days = 28;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
    }
    cout << "Month: " << month << '\n';
    cout << "Days: " << days << '\n';
    return 0;
}