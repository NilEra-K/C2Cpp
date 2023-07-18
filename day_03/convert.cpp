/* 显式类型转换 */
#include <iostream>
using namespace std;

int main(void){
     int a;  double b;  float c;  short d;  char e;
     // 任何基本类型之间都可以隐式转换
     a = b = c = d = e;
     e = d = c = b = a;

     // 任何其他类型的指针 到 void* 都可以隐式转换
     void* pv = &a;
     pv = &b;
     pv = &c;
     pv = &d;
     pv = &e;

     // void* 到其他类型指针必须类型强转
     // int* pa = (int*)pv; // void* -> int* 反方向 int* -> void*
     int* pa = static_cast <int*> (pv);
     double* pb = static_cast <double*> (pv);
     float* pc = static_cast <float*> (pv);
     short* pd = static_cast <short*> (pv);
     char* pe = static_cast <char*> (pv);

     // 任何类型的非常指针 到 同类型的常指针都可以隐式转换
     const int* cpa = pa;
     const double* cpb = pb;
     const float* cpc = pc;
     const short* cpd = pd;
     const char* cpe = pe;

     // 任何类型的常指针 到 同类型的非常指针都必须类型强转
     pa = (int*)cpa;     // const int* -> int* 反方向为 int* -> const int*
                         // 但是 pa = static_cast <int*> (cpa) 会报错
                         // 因为 C++提供了一种专门的方法去处理这种操作, 即 const_cast 操作
     // pa = static_cast <int*> (cpa); // static_cast 无法丢掉常量或其他类型限定符
     pa = const_cast <int*> (cpa);
     pb = const_cast <double*> (cpb);
     pc = const_cast <float*> (cpc);
     pd = const_cast <short*> (cpd);
     pe = const_cast <char*> (cpe);

     // 除了 void* 以外, 其他类型的指针都必须强转
     // pa = (int*)pb;      // double* -> int* 反方向为 int* -> double*
     pa = reinterpret_cast <int*> (pb);      // 可以在任意指针之间转换
     pa = reinterpret_cast <int*> (1000);    // 甚至可以将整形数转换为指针
     return 0;
}
