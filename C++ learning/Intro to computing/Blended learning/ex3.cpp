#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void dectobin(int decimal){
    int bin[10000];
    int len = 0;
    string out;
    while(decimal > 0){
        bin[len] = decimal % 2;
        decimal /= 2;
        len++;
    }
    for(int i = len - 1; i >= 0; i--){
        out += to_string(bin[i]);
        cout << "The binary form is: " << out << '\n';
    }
}
int main(){
    int decimal;
    cout << "Enter a decimal: ";
    cin >> decimal;
    dectobin(decimal);
    return 0;
}