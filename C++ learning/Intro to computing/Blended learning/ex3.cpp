#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
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
    for(int i = 0 ; i < store.length() ; i--){
        out = store.substr(i);
        if(out.substr(0,1) == to_string(1)){
            cout << out << '\n';
        }
    } 
    return 0;
}