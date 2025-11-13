#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void dectobin(int decimal){
    int bin[10000];
    int len = 0;
    while(decimal > 0){
        bin[len] = decimal % 2;
        decimal /= 2;
        len++;
    }
}
int main(){
    int decimal;
    int binary;
    string store;
    string out;
    cout << "Enter a decimal: ";
    cin >> decimal;
    int count = decimal;
    for(int i = 0; i < count / 2; i++){
        binary = decimal % 2;
        decimal = decimal / 2;
        store += to_string(binary);
    } 
    cout << store << '\n';
    reverse(store.begin(),store.end());
    return 0;
}