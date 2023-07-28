/* 利用 return 报告错误信息 */
#include <iostream>
#include <cstdio>
using namespace std;
class A { 
public:
     A() { cout << "A() is invoked" << endl; }
     ~A() { cout << "~A() is invoked" << endl; }
private:
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者
int foo(void) {
     cout << "模拟 foo() 出错前的代码..." << endl;
     A a;
     FILE* pfile = fopen("./config", "r");
     if(!pfile) {
          return -1;
     }
     cout << "模拟 foo() 出错后的代码..." << endl;
     return 0;
} // a.~A(); 释放 a所占的内存空间

int bar(void) {
     cout << "模拟 bar() 出错前的代码..." << endl;
     A b;
     if(foo() == -1){
          return -1;
     }
     cout << "模拟 bar() 出错后的代码..." << endl;
     return 0;
} // b.~A(); 释放 b所占的内存空间

int hum(void) {
     cout << "模拟 hum() 出错前的代码..." << endl;
     A c;
     if(bar() == -1){
          return -1;
     }
     cout << "模拟 hum() 出错后的代码..." << endl;
     return 0;
} // c.~A(); 释放 c所占的内存空间

int main(void) {
     cout << "模拟 main() 出错前的代码..." << endl;
     A d;
     if(hum() == -1){
          return -1;
     }
     cout << "模拟 main() 出错后的代码..." << endl;
     return 0;
} // d.~A(); 释放 c所占的内存空间


