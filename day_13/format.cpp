/* 格式化 I/O */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

int main(void) {
     cout.precision(10);
     cout << sqrt(200) << endl;
     cout << cout.precision() << endl;
     cout.setf(ios::scientific, ios::floatfield);
     cout << sqrt(200) << endl;

     cout.width(10);
     cout.fill('-');
     cout.setf(ios::internal, ios::adjustfield);
     cout.setf(ios::showpos);
     cout << 12345 << endl << 678910 << endl; // width(10) 只有第一次生效了
     cout << 12345 << endl;

     cout << setw(10) << setfill('-') << internal << showpos << 12345 << endl << 678910 << endl;
     return 0;
}

