#include <iostream>
#include <iomanip> 

using namespace std;
int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int row = 0; row < n; ++row) {
        long long coef = 1;
        cout << setw((n - row) * 3) << "";
        for (int col = 0; col <= row; ++col) {
            if (col == 0) {
                coef = 1;
            } else {
                coef = coef * (row - col + 1) / col;
            }
            cout << setw(6) << coef;
        }
        cout << endl;
    }
    return 0;
}