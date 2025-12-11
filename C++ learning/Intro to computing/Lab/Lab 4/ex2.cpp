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
    int syllable = 0;
    
    getline(cin, word_in);
    
    string word_origin = word_in; 
    
    transform(word_in.begin(), word_in.end(), word_in.begin(), [](unsigned char c){ return std::tolower(c); });
    
    for(i = 0; i < word_in.length(); i++){ 
        string test = word_in.substr(i,1);
        for(int j = 0; j < 14; j++){
            if(test == alphabet[j]){
                break;
            }
            if(j == 13){
                cout << -1;
                return 0;
            }
        }
    }
    for(i = 0; i < word_in.length(); i++){
        char test = word_in[i];
        bool group = false;
        
        switch(test){ 
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
            case ' ': 
                pronounce += ' '; 
                break;
            case '\'': 
                pronounce += '\''; 
                break;
            
            case 'w':
                if(i == 0){
                    pronounce += 'w';
                } else {
                    switch(word_in[i-1]){
                        case 'a': case 'u': case 'o':
                            pronounce += 'w';
                            break;
                        case 'i': case 'e':
                            pronounce += 'v';
                            break;
                        default:
                            pronounce += 'w';
                            break;
                    }
                }
                break;
        }
        
        switch(test){
            case 'a':
                if (i+1 < word_in.length() && (word_in[i+1] == 'i' || word_in[i+1] == 'e')) {
                    pronounce += "eye"; 
                    group = true; 
                    syllable++;
                } else if (i+1 < word_in.length() && (word_in[i+1] == 'o' || word_in[i+1] == 'u')) {
                    pronounce += "ow"; 
                    group = true; 
                    syllable++;
                } else { 
                    pronounce += "ah";
                    syllable++; 
                }
                break;
            case 'e':
                if (i+1 < word_in.length() && word_in[i+1] == 'i') {
                    pronounce += "ay"; 
                    group = true; 
                    syllable++;
                } else if (i+1 < word_in.length() && word_in[i+1] == 'u') {
                    pronounce += "eh-oo"; 
                    group = true; 
                    syllable++;
                } else { 
                    pronounce += "eh"; 
                    syllable++;
                }
                break;
            case 'i':
                if (i+1 < word_in.length() && word_in[i+1] == 'u') {
                    pronounce += "ew";
                     group = true;
                     syllable++;
                } else { 
                    pronounce += "ee";
                    syllable++; 
                }
                break;
            case 'o':
                if (i+1 < word_in.length() && word_in[i+1] == 'i') {
                    pronounce += "oy"; 
                    group = true;
                    syllable++;
                } else if(i+1 < word_in.length() && word_in[i+1] == 'u') {
                    pronounce += "ow"; 
                    group = true;
                    syllable++;
                } else{ 
                    pronounce += "oh";
                    syllable++; 
                }
                break;
            case 'u':
                if (i+1 < word_in.length() && word_in[i+1] == 'i') {
                    pronounce += "ooey"; 
                    group = true;
                    syllable++;
                } else{ 
                    pronounce += "oo"; 
                    syllable++;
                }
                break;
        }

        if (group) {
            i++;
        }
        
        if (i + 1 < word_in.length() && 
            word_in[i+1] != ' ' && 
            word_in[i+1] != '\'' && 
            test != ' ' && 
            test != '\'' && 
            string("pkhlmnw").find(test) == string::npos) {
            pronounce += "-";
        }
    }
    cout << syllable << '\n';
    return 0;
}