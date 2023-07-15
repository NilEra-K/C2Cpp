/* 左值和右值比较 */
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
    10;
    // &10;     // [Error] 操作数必须为左值或函数指示符
    foo();      // (1) 分配内存空间 /* 用于存储返回值 100, 这个区域也是匿名内存 */
                // (2) 生成跳转指令
    // &foo();  // [Error] 操作数必须为左值或函数指示符
    return 0;
}

