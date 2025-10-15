#include <iostream>
#include <iomanip>

int main() {
    double num;
    std::cout << "Input your number: ";
    std::cin >> num;
    std::cout << std::fixed << std::setprecision(1);
    for (int i = 1; i <= 4; ++i) {
        for (int j = 0; j < 4 - i; ++j) {
            std::cout << "   ";
        }
        for (int k = 0; k < i; ++k) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}