/* 异常说明: 给调用者承诺, 承诺函数不会抛出异常说明以外的异常类型 */
#include <iostream>
#include <cstdio>
using namespace std;

void foo() throw (int, double){
     throw 3.14;
}

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void) {
     try {
          foo();
     }
     catch(int& e){
          cout << "1. 捕获异常信息 : " << e << endl;
     }
     catch(double& e){
          cout << "2. 捕获异常信息 : " << e << endl;          
     }
     return 0;
}

