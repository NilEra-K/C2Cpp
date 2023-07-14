/* 命名空间声明 */
#include <iostream>
using namespace std;

namespace ns{ // 命名空间中的变量是进程级的声明周期
    int g_value = 0;
}

// 定义表只允许一个变量被定义
// 可见表可以允许有多个重名变量
int g_value = 0;        // g_value 定义在全局域中, 对 main 函数可见
// using ns::g_value;   // ns::g_value 定义在全局域中
                        // 当两者都定义在相同域中就会报错


int main(void){
    // int g_value = 0;     // g_value 是 main 函数定义的局部成员变量
                            // 会存在于定义表中
    using ns::g_value;      // 名字空间声明
                            // 从这行代码开始, ns 中的 g_value 引入当前作用域
                            // 相当于定义
    g_value = 8888;
    cout << "ns::g_value = " << ns::g_value << endl;
    return 0;
}