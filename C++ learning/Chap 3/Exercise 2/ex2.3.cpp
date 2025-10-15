#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    float num;
    cout << "Input your number:";
    cin >> num;
    cout << setw(8) << fixed << setprecision(1) << num << setw(8);
}