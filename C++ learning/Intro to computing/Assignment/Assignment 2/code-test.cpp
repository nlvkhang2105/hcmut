#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string word_in;
    string pronounce = "";
    
    // Standard alphabet only (Cleaner handles the special stuff first)
    string alphabet[14] = {"a", "e", "i", "o", "u", "p", "k", "h", "l", "m", "n", "w", " ", "\'"};

    cout << "Enter your Hawaiian word: ";
    getline(cin, word_in);
    
    string word_origin = word_in; 

    // ==========================================
    // STEP 1: THE UNIVERSAL CLEANER
    // ==========================================
    string cleaned_word = "";
    
    // Use size_t for safety
    for (size_t i = 0; i < word_in.length(); i++) {
        // CRITICAL: Cast to unsigned char so we get positive numbers (0-255)
        unsigned char c = (unsigned char)word_in[i];

        // CHECK 1: UTF-8 Encoding (2 bytes)
        // 0xC3 is 195 (Start of ã, â)
        // 0xC4 is 196 (Start of ā)
        if ((c == 0xC3 || c == 0xC4) && i + 1 < word_in.length()) {
            unsigned char next = (unsigned char)word_in[i+1];
            
            // Check for ã (0xA3), â (0xA2), ā (0x81)
            // We also check upper case Ã (0x83), Â (0x82), Ā (0x80)
            if (c == 0xC3 && (next == 0xA3 || next == 0xA2 || next == 0x83 || next == 0x82)) {
                cleaned_word += 'a'; 
                i++; // Skip the second byte
                continue;
            }
            if (c == 0xC4 && (next == 0x81 || next == 0x80)) {
                cleaned_word += 'a'; 
                i++; 
                continue;
            }
        }
        
        // CHECK 2: Single Byte Encoding (Windows/Latin-1)
        // 0xE3 = ã, 0xE2 = â
        else if (c == 0xE3 || c == 0xE2) {
             cleaned_word += 'a';
             continue;
        }

        // If not special, keep original
        cleaned_word += word_in[i];
    }
    
    // Update main string
    word_in = cleaned_word;

    // ==========================================
    // STEP 2: LOWERCASE TRANSFORM
    // ==========================================
    transform(word_in.begin(), word_in.end(), word_in.begin(), 
              [](unsigned char c){ return std::tolower(c); });

    // ==========================================
    // STEP 3: VALIDITY CHECK
    // ==========================================
    for (size_t i = 0; i < word_in.length(); i++) {
        string test = word_in.substr(i, 1);
        bool found = false;

        for (int j = 0; j < 14; j++) { 
            if (test == alphabet[j]) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << word_origin << " contains invalid characters." << endl;
            return 0;
        }
    }

    // ==========================================
    // STEP 4: PRONUNCIATION
    // ==========================================
    for (size_t i = 0; i < word_in.length(); i++) {
        char test = word_in[i];
        bool group = false;

        switch (test) {
            case 'p': pronounce += 'p'; break;
            case 'k': pronounce += 'k'; break;
            case 'h': pronounce += 'h'; break;
            case 'l': pronounce += 'l'; break;
            case 'm': pronounce += 'm'; break;
            case 'n': pronounce += 'n'; break;
            case ' ': pronounce += ' '; break;
            case '\'': pronounce += '\''; break;
            case 'w':
                if (i == 0) {
                    pronounce += 'w';
                } else {
                    // Check previous char safely
                    switch (word_in[i - 1]) {
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

        switch (test) {
            case 'a':
                if (i + 1 < word_in.length()) {
                    if (word_in[i+1] == 'i' || word_in[i+1] == 'e') { pronounce += "eye"; group = true; }
                    else if (word_in[i+1] == 'o' || word_in[i+1] == 'u') { pronounce += "ow"; group = true; }
                    else { pronounce += "ah"; }
                } else { pronounce += "ah"; }
                break;
            case 'e':
                if (i + 1 < word_in.length()) {
                    if (word_in[i+1] == 'i') { pronounce += "ay"; group = true; }
                    else if (word_in[i+1] == 'u') { pronounce += "eh-oo"; group = true; }
                    else { pronounce += "eh"; }
                } else { pronounce += "eh"; }
                break;
            case 'i':
                if (i + 1 < word_in.length() && word_in[i+1] == 'u') { pronounce += "ew"; group = true; }
                else { pronounce += "ee"; }
                break;
            case 'o':
                if (i + 1 < word_in.length()) {
                    if (word_in[i+1] == 'i') { pronounce += "oy"; group = true; }
                    else if (word_in[i+1] == 'u') { pronounce += "ow"; group = true; }
                    else { pronounce += "oh"; }
                } else { pronounce += "oh"; }
                break;
            case 'u':
                if (i + 1 < word_in.length() && word_in[i+1] == 'i') { pronounce += "ooey"; group = true; }
                else { pronounce += "oo"; }
                break;
        }

        if (group) {
            i++;
        }

        // Hyphen Logic
        if (i + 1 < word_in.length() && 
            word_in[i+1] != ' ' && 
            word_in[i+1] != '\'' && 
            test != ' ' && 
            test != '\'' && 
            string("pkhlmnw").find(test) == string::npos) {
            
            pronounce += "-";
        }
    }

    // Print Results
    cout << word_origin << endl;
    cout << pronounce << endl;
    return 0;
}