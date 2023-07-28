/* 虚析构函数——delete一个指向子类对象的基类指针, 能够正确的调用子类析构 */
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;
class A {
public:
     A() : m_a(open("./file", O_CREAT | O_RDWR, 0644)) {
          // 定义 m_a, 初始化为文件描述符
          // int m_a = open("./file", O_CREAT | O_RDWR, 0644); -> 文件表等内核结构(动态资源)
          cout << "A() is invoked - 打开了 file 文件" << endl;
     }

     ~A() {
          close(m_a);
          cout << "~A() is invoked - 关闭了 file 文件" << endl;
          // 释放了 m_a 本身所占内存空间
     }
private:
     int m_a;
};

class B : public A {
public:
     B() : m_b(open("./config", O_CREAT | O_RDWR, 0644)) {
          // 定义基类子对象, 利用基类子对象.A()
          // 定义 m_b, 初始化为文件描述符
          // int m_a = open("./file", O_CREAT | O_RDWR, 0644);-> 文件表等内核结构(动态资源)
          cout << "B() is invoked - 打开了 config 文件" << endl;
     }

     ~B() {
          close(m_b);
          cout << "~B() is invoked - 关闭了 config 文件" << endl;
          // 对于基类子对象, 利用基类子对象.~A()
          // 释放基类子对象, m_b本身所占内存空间
     }
private:
     int m_b;
};

class virtualA {
public:
     virtualA() : virtual_a(open("./vfile", O_CREAT | O_RDWR, 0644)) {
          cout << "virtualA() is invoked - 打开了 vfile 文件" << endl;
     }

     // 基类的析构函数是虚函数, 子类析构函数也是虚函数
     // 但是基类的析构函数 和 子类的析构函数不要求同名, 因为二者不可能同名
     virtual ~virtualA() {
          close(virtual_a);
          cout << "~virtualA() is invoked - 关闭了 vfile 文件" << endl;
     }
private:
     int virtual_a;
};

class virtualB : public virtualA {
public:
     virtualB() : virtual_b(open("./vconfig", O_CREAT | O_RDWR, 0644)) {
          cout << "virtualA() is invoked - 打开了 vconfig 文件" << endl;
     }

     ~virtualB() {
          close(virtual_b);
          cout << "~virtualB() is invoked - 关闭了 vconfig 文件" << endl;
     }
private:
     int virtual_b;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者
int main(void) {
     cout << ">>>>>>>>>>>>>>>" << endl;
     B* pb = new B;
     delete pb; // pb->析构函数 ~B() 释放 B类堆对象所占内存空间
                // A() is invoked - 打开了 file 文件
                // B() is invoked - 打开了 config 文件
                // ~B() is invoked - 关闭了 config 文件
                // ~A() is invoked - 关闭了 file 文件

     cout << endl << ">>>>>>>>>>>>>>>" << endl;
     A* pa = new B;
     delete pa; // pa->析构函数 ~A() 释放 A类堆对象所占内存空间
                // 所以 B类的部分动态资源并没有被释放
                // A() is invoked - 打开了 file 文件
                // B() is invoked - 打开了 config 文件
                // ~A() is invoked - 关闭了 file 文件
     
     cout << endl << ">>>>>>>>>>>>>>>" << endl;
     virtualA* pva = new virtualB;
     delete pva;// pva->虚析构函数(实际指向对象的析构函数)
     return 0;
}


