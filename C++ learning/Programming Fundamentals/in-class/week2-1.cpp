#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int height;
    int width = 0;
    cin >> height;
    cout << setw(height+10) << '*' << '\n';
    for(int i = height; i < 0; i--){
        cout << setw(height - i) << '*' << setw(height - i) << '*' << '\n';  
    }
}