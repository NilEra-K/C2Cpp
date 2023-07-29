/* 构造函数中的异常 */
#include <iostream>
#include <cstdio>
using namespace std;

class A {
public:
     A() { cout << "A() is invoked" << endl; }
     ~A() { cout << "~A() is invoked" << endl; }
private:
};

class C {
public:
     C() : m_pi(new int) {
          cout << "C() is invoked" << endl;
          FILE* pfile = fopen("./config", "r");
          if(!pfile){
               // 动态分配的资源, 必须在抛出异常之前, 自己手动释放, 否则将形成资源的泄漏
               delete m_pi;
               // 当编译器发现抛出异常时, 会将原本在析构函数中的操作放置于 throw 语句前
               // 这被形象的称为 "回滚机制"
               // 对于 m_a, 利用 m_a.~A(), 释放 m_a本身所占内存空间
               throw -1;
          }
     }
     ~C() {
          cout << "~C() is invoked" << endl; 
          delete m_pi;
     }
private:
     A m_a;
     int* m_pi;
};
// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void) {
     try {
          C c;
     }
     catch(...){
          
     }
     return 0;
}

