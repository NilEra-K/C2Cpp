/* 类型计算 */
#include <iostream>
using namespace std;

double foo(int a, int b){
     cout << a << ' ' << b << endl;
     return 0;
}

int main(void) {
     const int a = 20;
     auto b = a;    // 推导出 b 为 int
     cout << "b 的类型为 : " << typeid(b).name() << endl;   // i
     cout << "a 的地址为 : " << &a << endl;  // 地址不同
     cout << "b 的地址为 : " << &b << endl;
     b++; // 允许更改

     // 使用类型计算
     // decltype(a) 计算 a 的类型, 并赋予 c 其类型, 初始化为 a 的值
     decltype(a) c = a;  // 计算出 const int
     cout << "c 的类型为 : " << typeid(c).name() << endl;   // i
     cout << "a 的地址为 : " << &a << endl;  // 地址不同
     cout << "c 的地址为 : " << &c << endl;
     cout << "c 的值为 : " << c << endl;
     // c++; // 不允许更改

     // 三种类型计算规则
     // 标识符表达式, 直接取表达式的类型
     int x = 10000;
     decltype(x) d = x;
     cout << "d 的类型为 : " << typeid(d).name() << endl;   // i
     cout << "x 的地址为 : " << &x << endl;  // 地址不同
     cout << "d 的地址为 : " << &d << endl;
     d++; // 允许更改

     // 函数表达式, 取函数返回值的类型
     decltype(foo(10, 20)) e = x;           // foo(int, int) 函数并没有被调用, 只是计算类型
     cout << "e 的类型为 : " << typeid(e).name() << endl;   // i
     cout << "x 的地址为 : " << &x << endl;  // 地址不同
     cout << "e 的地址为 : " << &e << endl;

     // 其他表达式
     // 如果表达式的值为左值, 取该左值引用的类型
     decltype(++x) f = b;     // ++x 为左值, 返回其类型的引用 
     cout << "f 的类型为 : " << typeid(f).name() << endl;   // i
     cout << "b 的地址为 : " << &b << endl;  // 地址相同, 因为表达式的值为左值, 取该左值引用的类型
     cout << "f 的地址为 : " << &f << endl;

     // 如果表达式的值为右值, 则取右值本身的类型
     decltype(x++) g = b;     // x++ 为右值, x 累加之前的值存在一块匿名内存中
     cout << "g 的类型为 : " << typeid(g).name() << endl;   // i
     cout << "b 的地址为 : " << &b << endl;  // 地址不同, 因为表达式的值为右值, 取该左值引用的类型
     cout << "g 的地址为 : " << &g << endl;
     g++;
     return 0;
}

