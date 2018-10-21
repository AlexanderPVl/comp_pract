#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void sort_numbers(string &str);
vector<int> find_numbers(string &str);
bool is_number(const string &str);
int str_to_number(const string &str);
string num_to_str(int value);
int power(int value, int degree);
string insert_numbers(string &str, vector<int> numbers);

void sort_numbers(string &str) {
    vector<int> numbers = find_numbers(str);
    sort(numbers.begin(), numbers.end());
    for(int i : numbers) {
        cout << i << " ";
    }
    cout << "\n";
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

bool is_number(const string &str) {
    string::const_iterator itr = str.begin();
    while ( itr != str.end() && isdigit(*itr) ) { 
        ++itr; 
    }
    return ( !str.empty() && itr == str.end() );
}

int str_to_number(const string &str) {
    int dozens = str.length();
    int number = 0;
    for(int i = 0; i < dozens; ++i) {
        number += (str[str.length() - i - 1] - '0') * power(10,i);
    }
    return number;
}

int power(int value, int degree) {
    if( degree < 0 ) { cout << "Error! Negative degree.\n"; return -1; }
    
    if( degree == 0 ) { return 1; }
    if( degree == 1 ) { return value; }
    int tmp = value;
    for(int i = 1; i < degree; ++i) {
        tmp *= value; 
    }
    return tmp;
}

string insert_numbers(string &str, vector<int> numbers) {
    string tmp = "";
    vector<int>:: iterator itr = numbers.begin();
    string word;
    size_t prev = 0;
    size_t next;

    /*while( ( next = tmp.find(" ", prev) ) != -1 ) {
        word = tmp.substr(prev, next - prev);
        if( is_number(word) ) {
            tmp.replace(prev, word.length(), num_to_str(*itr));
            ++itr;
        }
        prev = next + 1;
    }
    word = str.substr(prev);
    if( is_number(word) ) {
        tmp.replace(prev, word.length(), num_to_str(*itr));
    }
    */

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

string num_to_str(int value) {
    int doz = 0;
    int tmp = value;
    do {
        tmp /= 10;
        doz++;
    } while( tmp );

    string num_str = "";
    for( int i = doz - 1; i >= 0; i-- ) {
        num_str += (value % 10 + '0');
        value /= 10;
    }
    string reverse_num_str;
    copy(num_str.rbegin(), num_str.rend(), back_inserter(reverse_num_str));
    return reverse_num_str;
}