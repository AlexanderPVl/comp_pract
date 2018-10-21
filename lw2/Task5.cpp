#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Func.h"

void sort_numbers(string &str);
vector<int> find_numbers(string &str);
string insert_numbers(string &str, vector<int> numbers);

void sort_numbers(string &str) {
    vector<int> numbers = find_numbers(str);
    sort(numbers.begin(), numbers.end());
    string str2 = insert_numbers(str, numbers);
    cout << str2;
}

vector<int> find_numbers(string &str) {
    vector<int> num_array;
    string word;
    size_t prev = 0;
    size_t next;

    while( ( next = str.find(" ", prev) ) != -1 ) {
        word = str.substr(prev, next - prev);
        if( is_number(word) ) {
            num_array.push_back(str_to_number(word)); 
        }
        prev = next + 1;
    }

    word = str.substr(prev);
    if( is_number(word) ) {
        num_array.push_back(str_to_number(word)); 
    }
    return num_array;
}

string insert_numbers(string &str, vector<int> numbers) {
    string tmp = "";
    vector<int>:: iterator itr = numbers.begin();
    string word;
    size_t prev = 0;
    size_t next;

    while( ( next = str.find(" ", prev) ) != -1 ) {
        word = str.substr(prev, next - prev);
        if( is_number(word) ) {
            tmp += (num_to_str(*itr) + " ");
            ++itr;
        } else {
            tmp += ( word + " ");
        }
        prev = next + 1;
    }
    
    word = str.substr(prev);
    if( is_number(word) ) {
        tmp += (num_to_str(*itr));
    } else {
        tmp += word;
    }

    return tmp;
}
