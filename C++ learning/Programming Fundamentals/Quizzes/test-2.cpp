#include<iostream>

using namespace std;

const char STAR = '*';
const int PRIME = 71;

int main(){
    int count, sum;
    double x;
    count = 1;
    sum = count + PRIME;
    x = 25.67;
    sum = count + sum; // Add count to sum
    x = x + sum * count;
    cout << " count = " << count << ", sum = " << sum << ", PRIME = " << PRIME << endl;
    return 0;
}