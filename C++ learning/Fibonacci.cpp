#include<iostream>
/*sybau*/
using namespace std;
int main() {
    int next,latest,sum,step;
    next = 0;
    latest = 1;
    step = 1;
    do {
        sum = next + latest;
        cout << "step " << step++ << " next: "<< next << " " << "latest: " << latest << " sum: " << sum << endl;
        next = latest;
        cout << "step " << step++ << " " << "next: "<< next << " " << "latest: " << latest << " sum: " << sum << endl;
        latest = sum;
        cout << "step " << step++ << " " << "next: "<< next << " " << "latest: " << latest << " sum: " << sum << endl;
    } while (sum <= 1000);
}