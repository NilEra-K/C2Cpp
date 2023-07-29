/* 构造函数中的异常 */
#include <iostream>
#include <cstdio>
using namespace std;

void foo();

class A {
public:
     ~A() { 
          // 主动抛出异常
          // throw "构造函数中抛出的异常";
          try{
               foo();
          }
          catch (const char* e){
               cout << "析构函数中的异常信息(非主动调用):" << e << endl;
          }
          cout << "析构函数的后续代码" << endl;
     }
private:
};

void foo() {
     throw "foo() 函数中抛出的异常";
}

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void) {
     try {
          A a;
          foo();
     }
     catch(const char* e){
          cout << "main() 函数捕获到异常: " << e << endl;
     }
     return 0;
}

