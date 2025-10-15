#include <iostream>
#include <string>

using namespace std;
int main() {
    string full_name;
    int L_total_length;
    int N_last_space_index;
    cout << "Enter the Full Name: ";
    getline(cin, full_name);
    cout << "Enter the total string length (L): ";
    cin >> L_total_length;
    cout << "Enter the index of the last space (N_last): ";
    cin >> N_last_space_index;
    int start_pos = N_last_space_index + 1;
    int last_name_length = L_total_length - start_pos;
    string last_name(full_name, start_pos, last_name_length);
    cout << "The Last Name is: " << last_name << endl;
    return 0;
}