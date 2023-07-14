/* 同一作用域 */
#include <iostream>

using namespace std;

namespace ns1{
    void foo(char* c, short s){ cout << "1. foo" << endl; }
    void foo(int i, double d){ cout << "2. foo" << endl;  }
}
namespace ns2{
    void foo(const char* c, short s){ cout << "3. foo" << endl; }
}

int main(void){
    using namespace ns1;
    using ns2::foo;
    char* c;
    short s;
    foo(c, s);  // [Out] 3. foo
    return 0;
}


