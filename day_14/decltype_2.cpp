/* 返回值类型后置 */
#include <iostream>
using namespace std;

// 先不指定函数返回值类型, 通过 decltype 计算得到返回值类型
auto foo(int x, double y) -> decltype(x+y) {
     return x+y;
}

int main(void) {
     auto f = foo(10, 3.14);
     // 推导 f 的类型为 : d
     cout << "f 的类型为 : " << typeid(f).name() << endl;
     return 0;
}

