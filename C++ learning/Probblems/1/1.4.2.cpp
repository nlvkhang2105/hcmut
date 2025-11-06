#include<iostream>
#include<string>

using namespace std;
int main(){
    string name;
    string test;
    string s[10000];
    getline(cin, name);
    for(int i = 0; i <= name.length(); i++){
        test = string(name,i,1);
        s[i] = test;
    }
    for(int i = name.length(); i >= 0; i--){
        cout << s[i];
    }
    return 0;
}