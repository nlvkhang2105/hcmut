#include<iostream>
#include<string>
using namespace std;

int main(){
    string word_in;
    string pronounce;
    string alphabet[26] = {"a", "e", "i", "o", "u", "p", "k", "h", "l", "m", "n", "w", "A","E","I","O","U","P","K","H","L","M","N","W"," ","\'"};
    cout << "Enter your Hawaiian word: ";
    getline(cin, word_in);
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
        
    }
    return 0;
}