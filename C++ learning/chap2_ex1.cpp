#include<stdio.h>
#include<iostream>
#include<windows.h>

using namespace std;
int main() {
    int straw_choco, matcha_choco, dubai_choco, straw_choco_price, matcha_choco_price, dubai_choco_price, sum_choco, sum_price;
    straw_choco_price = 20000;
    matcha_choco_price = 30000;
    dubai_choco_price = 50000;
    sum_choco = 0;
    sum_price = 0;
    straw_choco = 0;
    matcha_choco = 0;
    dubai_choco = 0;
    sum_choco = straw_choco + matcha_choco + dubai_choco;
    cout << "The total number of chocolates Minh received is " << sum_choco << endl;
    sum_price = straw_choco * straw_choco_price + matcha_choco * matcha_choco_price + dubai_choco * dubai_choco_price;
    cout << "The price of Minh's gift is " << sum_price << " VND" << endl;
    return 0;
}
