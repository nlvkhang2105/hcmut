#include<iostream>
#include<string>

using namespace std;
int main(){
    string st1;
    string st2;
    string st;
    string arr[10000];
    getline(cin, st1);
    getline(cin, st2);
    if(st1 > st2){
        cout << "String 1 is greater than string 2";
    } else cout << "String 2 is greater than string 1";
    st = st1 + st2;
    int size = st.length();
    cout << size;
    for(int i = 0; i < st.size(); i++){
        
    }
    return 0;
}