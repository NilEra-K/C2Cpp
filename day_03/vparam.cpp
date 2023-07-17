/* 引用作为函数的形参 */
#include <iostream>
using namespace std;

// void Swap(int x, int y){
//      int tmp = x;
//      x = y;
//      y = tmp;
// }

// 用指针的 Swap() 函数
void Swap(int* x, int* y){
     int tmp = *x;
     *x = *y;
     *y = tmp;
}

// 用引用的 Swap() 函数
void Swap(int& x, int& y){
     int tmp = x;
     x = y;
     y = tmp;
}

int Print(int& x){
     cout << x << endl;
     return 0;
}

int Print(const int& x, const int& y){ 
     // 打印机函数, 我们并不希望某些参数被修改
     // 当设计一个函数时, 只要能保证函数内部不需要修改实参, 就大胆加上 const
     cout << x << ' ' << y << endl;
     return 0;
}

int main(void){
     int a = 10, b = 20;
     Swap(a, b);
     cout << "a = " << a << " b = " << b << endl;
     Swap(&a, &b);  // 传 a和 b的地址
                    // 这里起始也是值传递, 只不过传递的值是 a和 b的地址
     cout << "a = " << a << " b = " << b << endl;
     // Print(6666);// 没有 const 修饰就无法使用 Print(int& x)
     return 0;
}
