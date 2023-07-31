/* 左值引用/右值引用 和 左值/右值的关系 */
#include <iostream>

using namespace std;

int foo(void){
    int m  = 100;
    return m;   // return 语句会产生匿名内存
}

int main(void){
    // 左值 
    // 都是有名字的内存 -> 能够取地址 -> 左值 |- 非常左值: 无 const 修饰
    //                                   |- 常左值: 有 const 修饰
    int a = 10;
    &a; 

    const int b = 10
    &b;

    // 右值
    // 右值的生命周期是语句级, 到分号就结束
    // 没有名字的内存 -> 匿名内存 -> 不能取地址 -> 右值: 直接更改右值没有意义
    const int& ri = 10; // [OK]
    int&& rri = 10;

    const int& rf = foo();
    int&& rrf = foo();

    // 左值引用和右值引用的差别
    // 1. 左值引用只能引用左值不能引用右值
    int a, c;
    int& ra = a;        // [OK]
    // int& rs = a + c; // [ERROR] a + c 是一个右值, 其结果存储在一块无名内存中

    // 右值引用只能引用左值不能引用右值
    int&& rs = a + c;   // [OK]
    // int&& rc = c;    // [ERROR]

    // 常量引用即可以引用左值也可以引用右值, C++ 11标准中称为常左值引用
    const int& cra = a;
    const int& crc = c;
    const int& crs = a + c;

    return 0;
}

