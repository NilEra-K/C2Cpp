#include <stdio.h>

int main(void){
    // sum 和 sub 未声明, 编译器会自动隐式声明, 并报两个警告
    // 进行编译后, 将 extern.o 和 mklib.o 进行链接会链接失败
    // 因为 C++ 会进行函数改名, 而 C 不会进行函数改名

    // 解决方法 1: 
    // 但这个方法并不好, 因为不同的 C++ 编译器的换名规则都不相同
    // 我们无法确定不同的 C++ 编译器的换名规则
    // int c = _Z3sumii(5, 4);
    // int d = _Z3subii(5, 4);

    // 解决方法 2:
    // 在制作库的源文件中使用 extern "C" 
    // mklib.cpp
    int c = sum(5, 4);
    int d = sub(5, 4);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    return 0;
}