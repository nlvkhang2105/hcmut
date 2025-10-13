#include<iostream>
#include<iomanip>

using namespace std;
int main() {
    float mid, lab, final;
    float avg;
    avg = 0;
    cout << "Enter your midterm score: ";
    cin >> mid;
    cout << "Enter your lab score: ";
    cin >> lab;
    cout << "Enter your finals score: ";
    cin >> final;
    avg = mid * 0.30 + lab * 0.20 + final * 0.50;
    cout << "Your average weighted score is " << avg;
    return 0;
}