/* 命名空间指令 */
#include <iostream>

namespace ns{
    int g_value = 0;
}

// int g_value;     // 这里定义 g_value 并不是 main 函数的定义, 但是对 main 函数可见, 位于 main 函数的可见表
                    // namespace中的 g_value 也位于 main 函数的可见表, 此时可见表中有两个 g_value 会导致歧义/冲突

int main(void){
    // g_value = 8888;      // 这里没有声明 g_value, 会显示为定义的标识符
    int g_value = 10;       // 这里定义局部成员变量, 下面 cout 输出局部 g_value 的值
                            // 低可靠性
                            // [补充] 编译器在编译时会维护两张表: 定义表和可见表
                            // g_value 是 main 函数的定义, 在 main 函数的定义表中
                            // 先找定义表, 再找可见表
    using namespace ns;     // 从这行代码开始, ns中的内容在当前作用域可见
    g_value = 8888;
    
    std::cout << "ns::g_value = " << ns::g_value << std::endl;
    return 0;
}