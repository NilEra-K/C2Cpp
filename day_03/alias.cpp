/* 引用: 一块内存的别名 */
#include <iostream>

using namespace std;

int main(void){
     int a = 100;
     int &b = a; // 不要理解为: 利用 a的数据给 b进行赋值
                 // 而应该理解为: 引用 b是 a所代表内存的别名

     b = 20;
     cout << "a = " << a << ' '
          << "b = " << b << endl;
     cout << "&a = " << &a << ' '
          << "&b = " << &b << endl;

     // int& c;  // [Error] c 声明作为一个引用, 但并未初始化
     int c = 20;
     b = c; // 不要理解为: 引用 b 的目标内存变为 c
            // 而应该理解为: 用 c中的数据给引用 b的目标内存(a) 赋值
     cout << "a = " << a << ' '
          << "b = " << b << ' '
          << "c = " << c << endl;
     cout << "&a = " << &a << ' '
          << "&b = " << &b << ' '
          << "&c = " << &c << endl;

     int &d = b; // 不要理解为是引用的引用, 如 d 是 b 的别名
                 // 而应该理解为 d 和 b 都是 a 的别名
     cout << "&a = " << &a << ' '
          << "&b = " << &b << ' '
          << "&d = " << &d << endl;

     const int e = 10;   // 无法修改的变量 e
     // int& f = e;      // [ERROR] 定义一个更宽松(能修改)的别名是不可以的
     const int& g = e;   // [OK] 定义一个正常的的别名是可以的
     const int& h = a;   // [OK] 定义一个更严格的别名是可以的
     return 0;
}
