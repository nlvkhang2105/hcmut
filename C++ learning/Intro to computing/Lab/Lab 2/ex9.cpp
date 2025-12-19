#include<iostream>

using namespace std;
int main(){
    double a, b, c, max;
    cin >> a >> b >> c;
    if((a > b) && (a > c)){
        cout << "Max is: " << a << '\n';
    } else if((b > c ) && (b > a)){
        cout << "Max is: " << b << '\n';
    } else if((c > a) && (c > b)){
        cout << "Max is: " << c << '\n';
    } 
    return 0;  
}