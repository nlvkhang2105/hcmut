#include<iostream>
#include<string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    string word_in;
    string pronounce;
    string alphabet[14] = {"a", "e", "i", "o", "u", "p", "k", "h", "l", "m", "n", "w", " ", "\'"};
    unsigned int i;
    getline(cin, word_in);
    string word_origin = word_in;
    transform(word_in.begin(), word_in.end(), word_in.begin(), [](unsigned char c){ return std::tolower(c); });
    for(i = 0; i < word_in.length(); i++){
        
    }
    for(i = 0; i < word_in.length(); i++){ //check validity
        string test = word_in.substr(i,1);
        for(int j = 0; j < 16; j++){
            if(test == alphabet[j]){
                break;
            }
            if(j == 15){
                cout << word_origin << " contains invalid characters." << '\n';
                return 0;
            }
        }
    }
    for(i = 0; i < word_in.length(); i++){
        char test = word_in[i];
        bool group = false;
        switch(test){ //check consonants and special characters
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
            case ' ':
                pronounce += ' ';
                break;
            case '\'':
                pronounce += '\'';
                break;
        }
        switch(test){
            case 'a':
                if (word_in[i+1] == 'i' || word_in[i+1] == 'e') {
                    pronounce += "eye";
                    group = true;
                } else if (word_in[i+1] == 'o' || word_in[i+1] == 'u') {
                    pronounce += "ow";
                    group = true;
                } else {
                    pronounce += "ah";
                }
                break;
            case 'e':
                if (word_in[i+1] == 'i') {
                    pronounce += "ay";
                    group = true;
                } else if (word_in[i+1] == 'u') {
                    pronounce += "eh-oo";
                    group = true;
                } else {
                    pronounce += "eh";
                }
                break;
            case 'i':
                if (word_in[i+1] == 'u') {
                    pronounce += "ew";
                    group = true;
                } else {
                    pronounce += "ee";
                }
                break;
            case 'o':
                if (word_in[i+1] == 'i') {
                    pronounce += "oy";
                    group = true;
                } else if(word_in[i+1] == 'u') {
                    pronounce += "ow"; 
                    group = true;
                } else{
                    pronounce += "oh";
                }
                break;
            case 'u':
                if (word_in[i+1] == 'i') {
                    pronounce += "ooey";
                    group = true;
                } else{
                    pronounce += "oo";
                }
                break;
        }
        if (group) {
            i++;
        }
        if (i + 1 < word_in.length() && word_in[i+1] != ' ' && word_in[i+1] != '\'' && word_in[i] != ' ' && word_in[i] != '\'' && test != 'p' && test != 'k' && test != 'h' && test != 'l' && test != 'm' && test != 'n' && test != 'w') {
            pronounce += "-";
        }
    }
    cout << pronounce << '\n';
    return 0;
}