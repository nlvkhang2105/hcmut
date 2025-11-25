#include<iostream>
#include<string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    string word_in;
    string pronounce;
    string alphabet[14] = {"a", "e", "i", "o", "u", "p", "k", "h", "l", "m", "n", "w", " ", "\'"};
    cout << "Enter your Hawaiian word: ";
    getline(cin, word_in);
    transform(word_in.begin(), word_in.end(), word_in.begin(), [](unsigned char c){ return std::tolower(c); });
    for(int i = 0; i < word_in.length(); i++){ //check validity
        string test = word_in.substr(i,1);
        for(int j = 0; j < 26; j++){
            if(test == alphabet[j]){
                break;
            }
            if(j == 25){
                cout << "Invalid character at " << test << '\n';
                return 0;
            }
        }
    }
    cout << "Valid" << '\n';
    for(int i = 0; i < word_in.length(); i++){
        char test = word_in[i];
        switch(test){ //check consonants
            case 'p':
                pronounce += 'p';
                break;
            case 'k':
                pronounce += 'k';
                break;
            case 'h':
                pronounce += 'h';
                break;
            case 'l':
                pronounce += 'l';
                break;
            case 'm':
                pronounce += 'm';
                break;
            case 'n':
                pronounce += 'n';
                break;
            case 'w':
                if(i == 0){
                    pronounce += 'w';
                } else{
                    switch(word_in[i-1]){
                    case 'a': case 'u': case 'o':
                    pronounce += 'w';
                    break;
                    case 'i': case 'e':
                    pronounce += 'v';
                    break;
                }
                }
                break;
        }
        //bool vowelB4;
        //bool vowelAft;
        /*switch(word_in[i-1]){ //check vowel b4
            case 'p': case 'k': case 'h': case 'l': case 'm': case 'n': case 'w':
                vowelB4 = false;
                break;
            case 'a': case 'e': case 'i': case 'o': case 'u':
                vowelB4 = true;
                break;
        }*/
        bool group = false;
        if(i + 1 < word_in.length()){
            switch(word_in[i+1]){ //check vowel group
            case 'p': case 'k': case 'h': case 'l': case 'm': case 'n': case 'w': 
                group = false;
                break;
            case 'a': case 'e': case 'i': case 'o': case 'u':
                if(word_in[i] != word_in[i+1]){
                    group = true;
                } else group = false;
                break;
            default:
                group = false;
                break;
        } 
        }
        
    }
    cout << word_in;
    return 0;
}