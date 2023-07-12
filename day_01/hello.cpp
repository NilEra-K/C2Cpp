/* 老生常谈: 第一个 C++ 程序 */
// ========================================= //
// 编译器: g++
// 也可以使用 gcc 编译, 编译时需要连接 stdc++ 库
// gcc hello.cpp -o hello -lstdc++
// ========================================= //
// + 拓展名: .cpp/.cc/.C/.cxx
// 甚至可以用 .c
// ========================================= //
// 头文件: #include <iostream>
// 在 /usr/include/c++ 目录中
// ========================================= //
// 流操作: cout<< / cin>>
// 也可以使用 printf / scanf
// ========================================= //
// 所有标准类型、对象和函数都位于 std 命名空间中
// ========================================= //
#include <stdio.h>
#include <iostream>

int main(void){
    printf("Hello World!\n");
    std::cout << "Hello World!" << std::endl; 
    return 0;
}
