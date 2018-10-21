#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sort_numbers(string &str);
void reverse_numbers(string &str);

int main() {
    cout << "--------Task 5:--------\n" << "String before:\n";
    string str = "55 is bet 22 ter 137 than 13 and 4356 even 21 14 than 6";
    cout << str;
    cout << "\n\nString after (with sorted numbers):\n";
    sort_numbers(str);
    cout << "\n\n";

    cout << "--------Task 11:--------\n";
    string str2 = "13 is better than 32 and even than 256";
    reverse_numbers(str2);
    cout << "\n";
    return 0;
}