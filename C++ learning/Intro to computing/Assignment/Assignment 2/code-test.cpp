#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

std::string validHawaiianword() {
    bool valid = true;
    std::string word;

    while (valid) {
        std::cout << "Enter a hawaiian word to pronounce: ";
        std::getline(std::cin, word);

        int countletters = 0;
        for (char letter : word) {
            if (std::string("aeioupkhlmnw' ").find(letter) != std::string::npos) {
                countletters++;
            }
        }

        if (countletters == (int)word.size()) {
            valid = false;
        } else {
            valid = true;
        }
    }

    return word;
}

std::string hawaiian_pronuncer() {
    std::string word = validHawaiianword();

    // convert to lowercase
    for (char &c : word) {
        c = std::tolower(c);
    }

    if (word.find("iw") != std::string::npos || word.find("ew") != std::string::npos) {
        for (char &c : word) {
            if (c == 'w') c = 'v';
        }
    }
    if (word.find("uw") != std::string::npos || word.find("ow") != std::string::npos) {
        // word = word.replace('w', 'w') does nothing, so no change needed
    }

    std::unordered_map<std::string, std::string> grpVowels = {
        {"ai", "eye-"}, {"ae", "eye-"}, {"ao", "ow-"}, {"au", "ow-"}, {"ua", "oo-ah-"},
        {"ei", "ay-"}, {"eu", "eh-oo-"}, {"iu", "ew-"}, {"oi", "oyo-"}, {"ou", "ow-"}, {"ui", "ooey-"}
    };
    std::unordered_map<char, std::string> vowels = {
        {'a', "ah-"}, {'e', "eh-"}, {'i', "ee-"}, {'o', "oh-"}, {'u', "oo-"}
    };

    std::string new_word = "";

    for (size_t index = 0; index < word.size(); ++index) {
        char current = word[index];

        // for consonants
        if (std::string("pkhlmnvw' ").find(current) != std::string::npos) {
            new_word += current;
        }

        // for vowels
        if (std::string("aeiou").find(current) != std::string::npos) {
            // for grouped vowels
            if ((index + 1) < word.size() && std::string("aeiou").find(word[index + 1]) != std::string::npos) {
                std::string grp = "";
                grp += current;
                grp += word[index + 1];
                if (grpVowels.find(grp) != grpVowels.end()) {
                    new_word += grpVowels[grp];
                } else {
                    for (char ch : grp) {
                        new_word += vowels[ch];
                    }
                }
            }

            // for single vowels
            if (index > 0 && std::string("aeiou").find(word[index - 1]) == std::string::npos && std::string("aeiou").find(current) != std::string::npos) {
                if ((index + 1) < word.size() && std::string("aeiou").find(word[index + 1]) == std::string::npos) {
                    new_word += vowels[current];
                }
            }

            // for last letter
            if (index == word.size() - 1 && index > 0 && std::string("aeiou").find(word[index - 1]) == std::string::npos) {
                if (std::string("pkhlmnvw'").find(current) != std::string::npos) {
                    new_word += current;
                }
                if (std::string("aeiou").find(current) != std::string::npos) {
                    new_word += vowels[current];
                }
            }

            // for first letter
            if (index == 0 && std::string("aeiou").find(current) != std::string::npos) {
                new_word += vowels[current];
            }
        }
    }

    if (!new_word.empty()) {
        new_word[0] = std::toupper(new_word[0]);
    }

    return new_word;
}

int main() {
    std::cout << hawaiian_pronuncer() << std::endl;
    return 0;
}