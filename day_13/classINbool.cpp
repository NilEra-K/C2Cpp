/* 将类对象放置在 bool 上下文中 */
#include <iostream>
#include <cstdio>
using namespace std;

class A {
public:
     A(int i) : m_i(i) { 
     }

     operator bool(/*| const A* this |*/) const {
          cout << "A 类的类型转换操作符函数被调用" << endl;
          return this->m_i;
     }
private:
     int m_i;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void) {
     A a(8888), b(0);

     // 1. 利用类对象给 bool 变量做初始化
     bool c = a;    // bool c = a.operator bool() -> 类型转换操作符函数
     cout << "c = " << c << endl;

     // 2. 利用类对象给 bool 变量赋值
     bool d;
     d = b;
     cout << "d = " << d << endl;

     // 3. if 语句的判定条件
     if (a) {
          cout << "IF 语句的判定条件为真" << endl;
     }

     // 4. while 循环的判定条件
     while (a) {
          cout << "WHILE 语句的判定条件为真" << endl;
          break;
     }

     // 5. for 循环的判定条件
     for (; a;) {
          cout << "FOR 语句的判定条件为真" << endl;
          break;
     }

     // 6. 逻辑反
     cout << "!a = " << !a << endl;
     return 0;
}

