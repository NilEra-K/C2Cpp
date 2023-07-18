/* 指针和引用的区别 */
#include <iostream>
using namespace std;

int main(void){
     int a = 10, b = 20;
     
     int* pa;       // 指针可以不进行初始化
     int& ra = a;   // 引用必须初始化

     // 指针的目标在初始化后可以随意变更
     pa = &a;  cout << pa << endl;
     pa = &b;  cout << pa << endl;
     // 引用在初始化后, 不可以变更其所指向的内存
     cout << "a = " << a << " b = " << b << endl;
     ra = b;
     cout << "a = " << a << " b = " << b << endl;

     pa = NULL;          // 存在空指针
     // ra = NULL;       // 不存在空引用

     int** ppa = &pa;    // 存在指向指针的指针
     // int&& rra = &ra; // 不存在引用的引用

     pa = &a;
     int*& rpa = pa;     // 存在指向指针的引用
     cout << "rpa = " << rpa << endl;
     // int&* pra = &ra; // 不存在引用的指针
                         // [ERROR] 不允许使用指向引用的指针
     
     int x = 10, y = 20, z = 40;
     int* p[3] = {&x, &y, &z};     // 存在指针数组
     // int& r[3] = {x, y, z};     // 不存在引用数组
     int* (&rarr)[3] = p;          // 但存在数组引用

     int arr[3];
     int(&rarr)[3] = arr;          // 数组引用
     return 0;
}
