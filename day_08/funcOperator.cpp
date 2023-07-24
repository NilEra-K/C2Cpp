/* 函数操作符(小括号操作符)函数 */
#include <iostream>
#include <cstring>
using namespace std;
class Compare {
public:
     // 没有固定返回值, 按需求确定
     int operator()(int x, int y) {
          return x > y ? x : y;
     }

     int operator()(int x, int y, int) {
          return x + y;
     }

     void operator()(){
          cout << "Have No Fun" << endl;
     }
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Compare c;
     int a = 10, b = 20;
     cout << c(a, b) << endl;      // c.operator()(a, b)
     cout << c(a, b, 1) << endl;   // c.operator()(a, b, 1)
     c();
     return 0;
}
