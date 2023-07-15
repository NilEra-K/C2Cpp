/* C++ 内联函数: 编译器的一种优化策略 */
#include <iostream>
using namespace std;

void foo(int x){
    cout << "void foo(int) : " << x << endl;
}

inline void bar(int x){ // 内联函数
    cout << "void bar(int) : " << x << endl;
}

int main(void){
    // 调用三次 foo() 函数, 需要发生六次跳转
    foo(10);    // 将此处的语句替换为跳转指令, 执行完后再跳转回来
    foo(20);    // 将此处的语句替换为跳转指令, 执行完后再跳转回来
    foo(30);    // 将此处的语句替换为跳转指令, 执行完后再跳转回来

    bar(10);    // 将此处替换为 bar() 函数被编译后产生的二进制代码
    bar(20);    // 将此处替换为 bar() 函数被编译后产生的二进制代码
    bar(30);    // 将此处替换为 bar() 函数被编译后产生的二进制代码
    return 0;
}