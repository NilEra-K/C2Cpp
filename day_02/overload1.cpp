/* 函数重载 */
// 1. 同一作用域
// 2. 函数名相同
// 3. 形参表不同
// 形参表是否相同与形参名无关, 与形参的个数以及每个对应形参的类型有关
#include <iostream>

using namespace std;

void foo(char* c, short s){ cout << "1. foo" << endl; }

void foo(int i, double d){ cout << "2. foo" << endl;  }

void foo(const char* c, short s){ cout << "3. foo" << endl; }

// 下面这行会报错
// int foo(int i, double d){ } // 是否为重载关系, 和返回值类型无关

int main(void){
    char* c;
    short s;
    foo(c, s);  // [Out] 1. foo
                // 这里 1和 3都能匹配, 但是会选择最匹配的的一个进行调用
    return 0;
}


