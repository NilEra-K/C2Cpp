/* lambda 表达式 */
#include <iostream>
#include <iomanip>
using namespace std;

int Max(int x, int y){
     return x > y ? x : y;
}


int main(void) {
     int a = 10, b = 20;
     cout << Max(a, b) << endl;

     // lambda 表达式
     // 编译器根据 lambda 表达式做以下三个操作 :
     // (1) 生成一个类
     // (2) 类内定义小括号操作符函数
     // (3) 返回这个类的匿名对象
     // 返回一个对象, 我们不知道其类型, 用 auto 关键字来接取
     auto f = [](int x, int y)->int{ return x > y ? x : y; };
     cout << typeid(f).name() << endl;  // Z4mainEUliiE_
     /* 用代码表示该过程 */
     /* ========================================================================== 
     class Z4mainEUliiE_ {    // (1) 生成一个类
     public:                  // (2) 类内定义小括号操作符函数
                              // lambda 表达式的返回类型是小括号操作符函数的返回类新
                              // lambda 表达式的参数表是小括号操作符函数的参数表
                              // lambda 表达式的函数体是小括号操作符函数的函数体
          int operator() (int x, int y) {
               return x > y ? x : y;
          }
     };
     Z4mainEUliiE_{};         // (3) 返回这个类的匿名对象
     ========================================================================== */
     cout << f(a, b) << endl; // 调用 f 的小括号操作符函数, f.operator()(int, int)

     // lambda 表达式可以没有返回类型, 将根据 return 判断
     auto g = [](int x, int y) { return x + y; };
     /* ========================================================================== 
     class X {      // (1) 生成一个类, 这里将类名用 X 代替
     public:        // (2) 类内定义小括号操作符函数
          auto operator() (int x, int y) -> decltype(x + y) {
               return x + y;
          }
     };
     X {};          // (3) 返回这个类的匿名对象
     ========================================================================== */
     cout << g(a, b) << endl;
     // 也可以这样用
     cout << [](int x, int y) { return x + y; }(10, 20) << endl; // X{ }(int, int)

     // lambda 表达式可以没有 return 语句, 此时返回值为 void
     [](int x, int y) { cout << x << ' ' << y << endl; }(a, b);

     // 参数为 void 可以省略不写
     [] { cout << "Hello World!" << endl;} ();


     return 0;
}

