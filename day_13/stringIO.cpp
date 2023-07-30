/* 字符串流 */
#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
     ostringstream oss;
     oss << 1234 << ' ' << 56.78 << ' ' << "ABCD";
     string os = oss.str();
     cout << os << endl;

     string is("1234 56.78 ABCD");
     istringstream iss (is);
     int i;
     double d;
     string s;
     iss >> i >> d >> s;
     cout << i << ' ' << d << ' ' << s << endl;
     return 0;
}

