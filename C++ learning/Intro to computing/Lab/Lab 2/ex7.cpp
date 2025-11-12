#include<iostream>

using namespace std;
int main(){
    char choice;
    double temp_in;
    double c_temp;
    double f_temp;
    cin >> choice >> temp_in;
    switch(choice){
        case 'C': case 'c':
            f_temp = ((9 / 5) * temp_in) + 32;
            cout << f_temp;
        case 'F': case 'f':
            c_temp = ((5 / 9) * (temp_in - 32));
            cout << c_temp;
        default:
            return 0;
    }
    return 0;

}