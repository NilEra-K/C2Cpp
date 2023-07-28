/* 匹配顺序 */
#include <iostream>
#include <cstdio>
using namespace std;
class A { };
class B : public A { };

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者
void foo(void) {
     throw B();
}

int main(void) {
     try {
          foo();
     } // 顺序匹配——而不是最优匹配, 所以最好将对子类的捕获放在对基类对象的捕获前面
     catch(B& e){
          cout << "B 类型引用的 catch 捕获" << endl;
     }
     catch(A& e){
          cout << "A 类型引用的 catch 捕获" << endl;
     }
     return 0;
}

