#include "histogram.h"
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    const char * const strProgramName = "Histogramer 1.1";
    
    cout << setfill('*') << setw( strlen( strProgramName ) + 4 ) << "" << endl;
    cout << '*' << setfill(' ') << setw( strlen( strProgramName ) + 3 ) << '*' << endl;
    cout << "* " << strProgramName << " *" << endl;
    cout << '*' << setfill(' ') << setw( strlen( strProgramName ) + 3 ) << '*' << endl;
    cout << setfill('*') << setw( strlen( strProgramName ) + 4 ) << "" << endl << endl;

    Histogram myBarChart;
    
	init_histogram(myBarChart);
    get_array(myBarChart);
    
    print_histogram(myBarChart);

    destroy_histogram(myBarChart);
	system("PAUSE");
    return 0;
}