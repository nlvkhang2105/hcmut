#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#define EXP 1e-6 //Hint: You may need to use this

int main(){
    double a,b,c;
    cin >> a >> b >> c;
    string start = "The triangle is ";
    if(a == b && b == c){
        cout << start << "Equilateral" << endl;
    } else if(a == b || b == c || a == c){
        if((abs(a*a + b*b - c*c) < EXP) || (abs(a*a - b*b + c*c) < EXP) || (abs(c*c + b*b - a*a) < EXP)){
            cout << start << "Right-angled Isosceles" << endl;
        } else cout << start << "Isosceles" << endl;
    } else if((c == sqrt(pow(a,2) + pow(b,2))) || (b == sqrt(pow(a,2) + pow(c,2))) || (a == sqrt(pow(c,2) + pow(b,2)))){
        cout << start << "Right-angled" << endl;
    } else cout << start << "Scalene" << endl;
}