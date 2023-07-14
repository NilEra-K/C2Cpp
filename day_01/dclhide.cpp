/* 命名空间声明与名字空间指令二者的区别 */
#include <iostream>
using namespace std;

namespace ns1{
    int g_value = 0;
    int g_other = 0;
}

namespace ns2{
    int g_value = 0;
    int g_other = 0;
}

int main(void){
    using namespace ns1;    // 名字空间指令
    using ns2::g_value;     // 名字空间声明
    g_value = 8888;         // 这里访问的是 ns1 还是 ns2
                            // ns2的 g_value
    g_other = 6666;         // 这里访问的是 ns1 还是 ns2
                            // ns1的 g_other
    cout << "ns1::g_value = " << ns1::g_value << endl
         << "ns2::g_value = " << ns2::g_value << endl;

    cout << "ns1::g_other = " << ns1::g_other << endl
         << "ns2::g_other = " << ns2::g_other << endl;

    return 0;
}