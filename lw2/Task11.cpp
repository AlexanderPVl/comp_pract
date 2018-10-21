#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Func.h"

void reverse_numbers(string &str) {
    string tmp = str;
    string word;
    string reverse_num_str;
    size_t prev = 0;
    size_t next;

    while( ( next = tmp.find(" ", prev) ) != -1 ) {
        word = tmp.substr(prev, next - prev);
        if( is_number(word) ) {
            copy(word.rbegin(), word.rend(), back_inserter(reverse_num_str));
            tmp.replace(prev, reverse_num_str.length(), reverse_num_str);
            reverse_num_str = "";
        }
        prev = next + 1;
    }
    
    word = tmp.substr(prev);
    if( is_number(word) )  {
        copy(word.rbegin(), word.rend(), back_inserter(reverse_num_str));
        tmp.replace(prev, reverse_num_str.length(), reverse_num_str);
    }

    cout << "String before:\n" << str << "\n\n";
    cout << "String after (with reversed numbers):\n" << tmp << "\n";
}