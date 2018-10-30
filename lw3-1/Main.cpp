#include <iomanip>
#include <iostream>
#include "Template_vector.h"

void test() {
    Template_vector<int> a;
    a.print();
    std::cout << std::endl;
    Template_vector<double> b(5);
    b.print();
    std::cout << std::endl;
    // std::vector<double> v = {1,2,3,4,5,6,7,8};
    Template_vector<double> c({2,3,2,3,2});
    c.print();
}

int main() {
    test();
    return 0;
}