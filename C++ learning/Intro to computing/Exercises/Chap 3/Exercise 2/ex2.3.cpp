#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    double num;
    cout << "Input your number: ";
    cin >> num;
    cout << fixed << setprecision(1);
    for (int i = 1; i <= 4; ++i) {
        for (int j = 0; j < 4 - i; ++j) {
            cout << "  ";
        }
        for (int k = 0; k < i; ++k) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}