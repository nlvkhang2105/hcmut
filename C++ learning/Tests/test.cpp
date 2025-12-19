#include <iostream>

int main() {
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            continue;
        }
        std::cout << i << " ";
    }
    return 0;
}