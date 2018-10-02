#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include "histogram.h"
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

void add_bar( Histogram &histogram, const char *strName );
bool append_bar( Histogram &histogram, const char *strName );
void get_array( Histogram &histogram );
char* num_to_str( int number );
void choose_order( Histogram &histogram );

void add_block( Histogram &histogram, const char *strName ) {
    if( !append_bar(histogram, strName) ) {
        add_bar(histogram, strName );
    }
}


bool append_bar( Histogram &histogram, const char *strName ) {
    for( int i = 0; i < histogram.nBarsSize; ++i ) {
        if( strcmp( histogram.BarNames[i], strName )  == 0 ) {
            histogram.nMaxBar = max( histogram.nMaxBar, ++histogram.Bars[i] );
            return true;
        }
    }
    return false;
}

void add_bar( Histogram &histogram, const char *strName ) {
    char **newNames = new char *[histogram.nBarsSize + 1];
    int   *newBars = new int[histogram.nBarsSize + 1];
    int order = ( histogram.bAscending ) ? 1 : -1;
    int i;
    if( histogram.nBarsSize > 0 ) {
        for( i = 0; ( i < histogram.nBarsSize ) &&  ( ( order * strcmp( histogram.BarNames[i], strName ) < 0  && strlen(histogram.BarNames[i]) == strlen(strName) ) || ( order*strlen(histogram.BarNames[i]) < order*strlen(strName))); ++i ) {
            newNames[i] = histogram.BarNames[i];
            newBars[i] = histogram.Bars[i];
        }
        newNames[i] = new char[strlen( strName ) + 1];
        strcpy( newNames[i], strName );
        newBars[i] = 1; i++;

        for(; i < ( histogram.nBarsSize + 1 ); ++i ) {
            newNames[i] = histogram.BarNames[i - 1];
            newBars[i] = histogram.Bars[i - 1];
        }
        delete[] histogram.BarNames;
        delete[] histogram.Bars;
        histogram.nBarsSize++;
        histogram.BarNames = newNames;
        histogram.Bars = newBars;
        return;
    }

    newNames[histogram.nBarsSize] = new char[strlen(strName) + 1];
    strcpy(newNames[histogram.nBarsSize], strName);
    newBars[histogram.nBarsSize] = 1;

    histogram.nBarsSize++;
    histogram.BarNames = newNames;
    histogram.Bars = newBars;
}

void print_histogram( const Histogram &histogram ) {
    int max_name_width = 0;
    for ( int i = 0; i < histogram.nBarsSize; ++i ) {
        max_name_width = ( max_name_width > strlen(histogram.BarNames[i]) ) ? max_name_width : strlen(histogram.BarNames[i]);
    }

    for( int i = 0; i < histogram.nBarsSize; ++i ) {
        cout.width(max_name_width);
        cout << setfill(' ') << right << histogram.BarNames[i] << '|';
        cout << setfill( histogram.chBlock ) << setw( 10 * histogram.Bars[i] / histogram.nMaxBar ) << "" << endl;
    }
}

void get_array( Histogram &histogram ) {
    // input of array
    int size = 0;
    cout << "Enter size of the array: ";
    cin >> size;
    int *arr = new int[size];

    for(int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cout << "Entered array: " << endl;
    for( int i = 0; i < size; ++i ) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
	choose_order(histogram);

    //adding to histogram
    char *num_str;
    for( int i = 0; i < size; ++i ) {
        num_str = num_to_str( arr[i] );
        add_block( histogram, num_str );
    }
    
}

char* num_to_str( int number ) {
    int doz = 0;
    int tmp = number;
    do {
        tmp /= 10;
        doz++;
    } while( tmp );

    char *num_str = new char[doz + 1];
    num_str[doz] = '\0';

    for(int i = doz - 1; i >= 0; i-- ) {
        num_str[i] = number % 10 + '0';
        number /= 10;
    }

    return num_str;
}

void choose_order(Histogram &histogram) {
	char c;
	cout << "Ascending(a) or descending(d)?" << endl;
	cin >> c;
	switch (c) {
		case 'a':
			cout << "Ascending order" << endl;
			break;
		case 'd':
			histogram.bAscending = false;
			cout << "Descending order" << endl;
			break;
		default:
			cout << "I will take that for ascending order." << endl;
			break;
	}
}