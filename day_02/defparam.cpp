/* C++ 缺省参数 */
#include <iostream>
using namespace std;

void foo(int a, double b = 3.14, float c = 3.1, short d = 2, char e = 'A'){
    // char e = 'A' 就是缺省
    // 如果 double b 有缺省值, 那么 float c 和 short d 也必须有缺省值
    cout << "e = " << e << endl;
}

void foo(int a){
    cout << "a = " << a;
}

void declare(int a = 3, double b = 3.14);   // 声明
// 错误写法, 会报错
// void declare(int a = 3, double b = 3.14){ return; }
// 正确写法
void declare(int a, double b){ return; }

int main(void){
    foo(1, 2, 3, 4);
    // foo(10);         // 产生歧义
                        // 因为 foo(10) 可以匹配 foo(int, double b = 3.14, float c = 3.1, short d = 2, char e = 'A')
                        // 也可以匹配 foo(int)
    return 0;
}