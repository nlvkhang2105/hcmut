#include<iostream>

using namespace std;

int maxOfArray(int arr[], int n){
    
}
int sumOfArray(int arr[], int n){
    if(n == 0) return 0;
    return sumOfArray(arr,n -1) + arr[n -1];
}
void print(int n){
    if(n == 1){
        cout << 1;
        return;
    }
    print(n-1);
    cout << " " << n; 
}
int main(){
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    print(n);
}