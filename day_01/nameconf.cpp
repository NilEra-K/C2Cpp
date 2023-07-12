/* 命名空间 */
// 命名空间可以划分更精细的逻辑空间(单元)
// 能够有效避免名字冲突的问题
#include <iostream>

namespace ICBC{
    // ICBC 中国工商银行命名空间
    int g_money = 0;

    // 存钱函数
    void save(int money){
        g_money += money;
    }
}

namespace ICBC{ // 编译器将两个命名空间合并为一个命名空间
    // 当我们的命名空间拆分时, 我们允许定义不同的内容
    // 但是并不能定义相同的内容, 定义相同的内容(如下), 会产生重定义错误
    // int g_money = 0; // 重定义

    // 支付函数
    void pay(int money){
        g_money -= money;
    }
}

namespace CCB{
    // CCB 中国建设银行命名空间
    int g_money = 0;

    // 存钱函数: 纯声明
    void save(int money);

    // 支付函数: 声明+定义
    void pay(int money){
        g_money -= money;
    }
}

void CCB::save(int money){  // CCB 命名空间中的 save 函数的定义(实现)
    // 声明定义分开写时, 一定要保证和声明契合
    // 声明和定义分开写, 是为了可以分文件编程
    g_money += money;
}

int main(void){
    ICBC::save(10000);
    ICBC::pay(3000);
    std::cout << "工行卡余额: " << ICBC::g_money << std::endl;

    CCB::save(8000);
    CCB::pay(3000);
    std::cout << "建行卡余额: " << CCB::g_money << std::endl;
    return 0;
}
