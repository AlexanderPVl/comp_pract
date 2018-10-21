#include <string>
#include <vector>
using namespace std;

bool is_number(const string &str) {
    string::const_iterator itr = str.begin();
    while ( itr != str.end() && isdigit(*itr) ) { 
        ++itr; 
    }
    return ( !str.empty() && itr == str.end() );
}

int power(int value, int degree) {
    if( degree < 0 ) { return -1; }
    
    if( degree == 0 ) { return 1; }
    if( degree == 1 ) { return value; }
    int tmp = value;
    for(int i = 1; i < degree; ++i) {
        tmp *= value; 
    }
    return tmp;
}

int str_to_number(const string &str) {
    int dozens = str.length();
    int number = 0;
    for(int i = 0; i < dozens; ++i) {
        number += (str[str.length() - i - 1] - '0') * power(10,i);
    }
    return number;
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