#include<iostream>
#include<string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    unsigned int i;
    string word_in;
getline(cin, word_in);
    
    string word_origin = word_in; // Save original for printing later

    // ==========================================
    // STEP 1: CLEANING LOOP (The Fix)
    // Converts 2-byte characters (ã, â) into 1-byte 'a'
    // ==========================================
    string clean_builder = "";
    
    // Use size_t for the loop to satisfy Web Coderunners
    for(size_t i = 0; i < word_in.length(); i++){
        unsigned char c = (unsigned char)word_in[i];

        // Check for the UTF-8 "Lead Byte" 195 (which starts ã and â)
        if (c == 195 && i + 1 < word_in.length()) {
            unsigned char next = (unsigned char)word_in[i+1];
            
            // 163 is the second half of 'ã', 162 is the second half of 'â'
            if (next == 163 || next == 162) { 
                clean_builder += 'a'; 
                i++; // SKIP the next byte because we just handled it
                continue;
            }
        }
        
        // If it's not a special char, just keep it
        clean_builder += word_in[i];
    }
    
    // Update the main variable to the clean version
    word_in = clean_builder;
    cout << word_in;
    return 0;
}