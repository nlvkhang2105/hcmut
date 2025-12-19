#include<iostream>

using namespace std;
int main(){
    int grade;
    cin >> grade;
    if (grade >= 90){
        cout << 'A' << '\n';
    } else if((grade <= 89) && (grade >=80)){
        cout << 'B' << '\n';
    } else if((grade <= 79) && (grade >= 70)){
        cout << 'C' << "\n";
    } else if((grade <= 69) && (grade >= 60)){
        cout << 'D' << '\n';
    } else cout << 'F' << '\n';
    return 0;
}