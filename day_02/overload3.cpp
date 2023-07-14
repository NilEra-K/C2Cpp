/* 重载匹配的优先级 */
#include <iostream>

using namespace std;
// 完全匹配
// 换名后: _Z3fooPcs
void foo(char* c, short s){ cout << "1. foo(char*, short)" << endl; }

// 当编译器不存在完全匹配时, 存在两个或两个以上的优先级不同的非完全匹配的函数
// 编译器会选择优先级高的函数, 但会给出警告 [Warning]
// 常量转换
// 换名后: _Z3fooPKcs
void foo(const char* c, short s){ cout << "2. foo(const char*, short)" << endl; }

// 升级转换
// 没有信息损失的转化, 从小到大
// 例如: short->int  float->double  
// 换名后: _Z3fooPci
void foo(char* c, int i){ cout << "3. foo(char*, int)" << endl; }

// 标准转换
// 有可能有信息损失的转换, 从大到小
// 例如: int->short  double->float
// 换名后: _Z3fooPcc
void foo(char* c, char s){ cout << "4. foo(char*, char)" << endl; }

// 自定义转换
/* 还没有涉及该内容 */

// 省略号匹配
// 又叫可变长参数
// 换名后: _Z3fooz
void foo(...){ cout << "5. foo(...)" << endl; }

int main(void){
    char* c;
    short s;
    foo(c, s);  // 普通方式调用重载关系函数

    // 函数指针调用重载关系的函数, 根据函数指针类型确定到底调用哪个
    void (*pfunction)(const char*, short) = foo;
    pfunction(c, s);
    return 0;
}


