#include<iostream>
/*sybau*/
using namespace std;
int main() {
    int next,latest,sum,step;
    next = 0;
    sum = 0;
    latest = 1;
    step = 1;
    do {
        cout << "step " << step++ << " next: "<< next << " " << "latest: " << latest << " sum: " << sum << endl;
        sum = next + latest;
        if (sum >= 1000) {
            cout<< "step " << step++ << " " << "sum: " << sum << " >= 1000, stop!" << endl;
            break;
        } 
        else {
            cout << "step " << step++ << " " << "Not there yet" << endl;
        }
        cout << "step " << step++ << " " << "next: "<< next << " " << "latest: " << latest << " sum: " << sum << endl;
        next = latest;
        cout << "step " << step++ << " " << "next: "<< next << " " << "latest: " << latest << " sum: " << sum << endl;
        latest = sum;
    } while (true);
    system("pause");
    return 0;
}