#include<iostream>

using namespace std;
int main(){
    int a, b, c, d;
    cout << "Please enter angle A of the quadrilateral: ";
    cin >> a;
    cout << "Please enter angle B of the quadrilateral: ";
    cin >> b;
    cout << "Please enter angle C of the quadrilateral: ";
    cin >> c;
    //cout << "Please enter angle D of the quadrilateral: ";
    //cin >> d;
    if(a == 90 && b == 90 && c == 90){
        cout << "Your shape is a rectangle";
    } else if( ((b == c) && (a == 180 - a)) || ((b == c) || (a == 180 - c))){
        cout << "Your shape is an parralellogram";
    } else if(a == 90 && b == 90 && ((c != 180 - a) || (c != 180 - b))){
        cout << "Your shape is a right trapezoid";
    } else if((b == c == 2 * b == 2 * c)){
        cout << "Your shape is an isosceles trapezoid";
    } else if(a + b + c + d == 360){
        cout << "Your shape is an cylindrical quadrilateral";
    } else cout << "Your shape is an irregular quadrilateral";
    return 0;
}