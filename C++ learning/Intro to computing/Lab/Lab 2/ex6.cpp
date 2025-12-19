#include<iostream>

using namespace std;
int main(){
    char marr_code;
    cin >> marr_code;
    switch(marr_code){
        case 'M': case 'm':
            cout << "Individual is married\n";
            break;
        case 'D': case 'd':
            cout << "Individual is divorced\n";
            break;
        case 'W': case 'w':
            cout << "Individual is widowed\n";
            break;
        default:
            cout << "An invalid code was entered\n";
    }
    return 0;
}