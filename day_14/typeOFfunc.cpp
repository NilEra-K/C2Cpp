/*  */
#include <iostream>
using namespace std;

int a;
void foo(int b) {
     int c;
     // 先编译函数内部的类型, 即在编译 class A 时, foo()函数还没有进行编译
     class A {
     public:
          void bar(int d) {
               a = 10;        // 在类的域中没有 a 变量, 扩大范围, 在全局域中找到
               // b = 10;     // [ERROR] 无法访问
               // c = 10;     // [ERROR] 无法访问
               d = 10;
          }
     };
}

// 成员函数中也可以有类型
int x;
class B {
public:
     void hum(int y){
          class C {
          public:
               void chi(int z){
                    x = 10;    // 范围扩大顺序: chi()函数(没有 x) -> C类(没有 x) -> (此时还没有编译 foo() 函数) -> B类(没有 x) -> 全局域
                    // y = 10; // [ERROR] 不可访问
                    z = 10;
                    m = 10;
                    // n = 10; // [ERROR] 不可访问
                    B b;
                    b.n = 10;
               }
          private:
          };
     }
private:
     // 为什么 m可以访问, n不可以访问?
     // 类的成员有两种: 静态成员和实例成员(包括实例和函数)
     // 实例成员的存储空间属于具体的实例, 不同实例(对象)的同名成员拥有不同的存储空间;
     // 静态成员的存储空间是固定的, 与具体的实例(对象)无关, 被该类的所有实例共享

     // 简单理解就是:
     // 静态成员变量 m 不属于 对象
     // 普通成员变量 n 属于 对象, 即只能在对象中
     static int m;
     int n;
};

int main(void) {
     return 0;
}

