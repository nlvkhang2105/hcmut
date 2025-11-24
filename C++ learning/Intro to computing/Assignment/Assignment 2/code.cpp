#include<iostream>
#include<string>
using namespace std;

int main(){
    string word_in;
    string pronounce;
    string alphabet[26] = {"a", "e", "i", "o", "u", "p", "k", "h", "l", "m", "n", "w", "A","E","I","O","U","P","K","H","L","M","N","W"," ","\'"};
    cout << "Enter your Hawaiian word: ";
    cin >> pronounce;
    for(int i = 0; i < word_in.length(); i++){
        string test = word_in.substr(i,1);
        for(int j = 0; j < 26; j++){
            if(test == alphabet[i]){
                break;
            }
            if(j == 25){
                cout << "Invalid character at " << test << '\n';
                return 0;
            }
        }
        cout << "Valid";
    }
    return 0;
}