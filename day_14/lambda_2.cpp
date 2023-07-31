/* lambda 表达式的捕获表 */
#include <iostream>
#include <iomanip>
using namespace std;
int a = 10;

class Y {
public:
     Y() : e(50) { }
     void foo(int c = 30){
          // 空捕获表
          cout << ">>> 空捕获表 []" << endl;
          [](int d = 40) {
               cout << "a = " << a << endl;
               cout << "b = " << b << endl;
               // cout << "c = " << c << endl;    // [ERROR] 可以看到实际实现中的代码
                                                  // lambda表达式实际是个类, 先编译该类, 再编译 foo() 函数
               cout << "d = " << d << endl;
               // cout << "e = " << e << endl;    // [ERROR]
          }();
          /* ================================================
          class X {
          public:
               void operator()(int d = 40) {
                    cout << "a = " << a << endl;
                    cout << "b = " << b << endl;
                    cout << "c = " << c << endl;  // [ERROR]
                    cout << "d = " << d << endl;
                    cout << "e = " << e << endl;  // [ERROR]
               }
          };
          X{ } ();
          ================================================ */

          // lambda 表达式将捕获外部变量的值
          // 捕获表里有没有值的区别反映在 lambda 表达式的类中即其有无成员变量和构造函数
          cout << endl << ">>> [c]" << endl;
          [c](int d = 40) { cout << "c = " << c << endl; }();
          /* ================================================
          class X {
          public:
               X(int m) : c(m) { }
               void operator()(int d = 40) {
                    cout << "c = " << c << endl;
               }
          private:
               const int c;   // 这里的 c 并不是 foo() 函数的形参 c
                              // 而是 X 类的一个成员变量
          };
          X{ c }(); // 这里的 c 是 foo() 函数的 c
                    // 编译器已经编译完 X 类
                    // 编译完成后编译 foo() 函数的代码
                    // 这里是在用 foo() 函数的形参 c 来给 X 做构造
          ================================================ */
          
          // lambda 表达式 按引用捕获, 指定的外部变量
          cout << endl << ">>> [&c]" << endl;
          [&c](int d = 40) { cout << "c = " << c++ << endl; }();
          /* ================================================
          class X {
          public:
               X(int& m) : c(m) { }   // 构造函数形参表是一个引用
               void operator()(int d = 40) {
                    cout << "c = " << c << endl;
               }
          private:
               int& c;        // 这里的 c 并不是 foo() 函数的形参 c
                              // 而是 X 类的一个成员变量
          };
          X{ c }(); // 这里的 c 是 foo() 函数的 c
          ================================================ */
          cout << "c = " << c << endl;  // 在 lambda 表达式中可以通过引用修改

          // 捕获 this 指针, 访问外部对象的成员
          cout << endl << ">>> [this]" << endl;
          [this](int d = 40) { cout << "e = " << this->e << endl; }();
          [c, this](int d = 40) { cout << "c = " << c << endl << "e = " << this->e << endl; }();
     }
private:
     static int b;
     int e;
};

int Y::b = 20;

int main(void) {
     Y y;
     y.foo();
     return 0;
}

