#include<iostream>
#include<string>

using namespace std;
int main(){
    string st1;
    string st2;
    string st;
    string nospacest;
    string arr[10000];
    string reversed;
    getline(cin, st1);
    getline(cin, st2);
    if(st1 > st2){
        cout << "String 1 is greater than string 2" << endl;
    } else cout << "String 2 is greater than string 1" << endl;
    st = st1 + st2;
    int size = st.length();
    cout << "Size of string st is: " << size << endl;
    for(char c : st){
        if(c != ' '){
            nospacest += c;
        }
    }
    cout << nospacest << endl;
    for(int i = 0; i <= nospacest.length(); i++){
        string test = string(nospacest,i,1);
        arr[i] = test;
    }
    for(int i = nospacest.length(); i >= 0; i--){
        reversed += arr[i];
    }
    cout << reversed << endl;
    for(int i = 0; i < st2.size(); i++){
        for(int sublen = 1; sublen <= st2.size() - i; sublen++){
            if(st1 == st2.substr(i,sublen)){
                cout << "String 1 is a substring of string 2" << endl;
                break;
            }
        }
    }
    return 0;
}