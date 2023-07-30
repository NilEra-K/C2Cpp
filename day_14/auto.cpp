/* 类型推导 */
#include <iostream>
using namespace std;

void foo(auto v){
     cout << v << endl;
}

class A {
public:
     // 类的成员变量无法推导
     // auto a;   // 声明
     // auto b;   // 声明
};

int main(void) {
     int a = 10;
     const int b = 20;

     auto c = a;
     cout << "c 的类型为 : " << typeid(c).name() << endl;
     cout << "a 的地址 : "<< &a << endl;     // 验证 c是否是 a的引用
     cout << "c 的地址 : "<< &c << endl;
     c++;

     auto d = b;
     cout << "d 的类型为 : " << typeid(d).name() << endl;   // auto 无法自动推断 const, 只能在 auto 的上下文显示指明
     cout << "b 的地址 : "<< &b << endl;
     cout << "d 的地址 : "<< &d << endl;
     d++;
     
     const auto e = b;
     cout << "d 的类型为 : " << typeid(e).name() << endl;   // auto 无法自动推断 const, 只能在 auto 的上下文显示指明
     cout << "b 的地址 : "<< &b << endl;
     cout << "e 的地址 : "<< &e << endl;
     // e++;   // e 无法修改, 则可推导出其类型为 const int

     // 如果给出的初始化数据类型为常量指针, 则可以自动推导 const
     auto f = &b;   // f 的类型为 PKi
     cout << "f 的类型为 : " << typeid(f).name() << endl;   // auto 无法自动推断 const, 只能在 auto 的上下文显示指明
     cout << "b 的地址 : "<< &b << endl;
     cout << "f 的地址 : "<< &f << endl;
     // *f = 8888;  // 无法修改
     f = NULL;      // 可以修改

     // auto 和引用联用
     auto& g = a;
     cout << "g 的类型为 : " << typeid(g).name() << endl;   // auto 无法自动推断 const, 只能在 auto 的上下文显示指明
     cout << "a 的地址 : "<< &a << endl;
     cout << "g 的地址 : "<< &g << endl;
     
     // 若指明按照引用推导并且目标带有常属性, 则可以自动推导 const
     auto& h = b;
     cout << "h 的类型为 : " << typeid(h).name() << endl;   // auto 无法自动推断 const, 只能在 auto 的上下文显示指明
     cout << "b 的地址 : "<< &b << endl;
     cout << "h 的地址 : "<< &h << endl;

     // auto 关键字的使用限制
     // 函数形参类型无法推导(C++ 14 标准支持)
     // C++ 11 标准不支持: error: use of ‘auto’ in parameter declaration only available with ‘-std=c++14’ or ‘-std=gnu++14’
     foo(100); 
     return 0;
}

