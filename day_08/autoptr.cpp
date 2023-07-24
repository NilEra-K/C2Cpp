/* 智能指针 解引用和间接访问操作符函数 */
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <memory>   // 使用智能指针需要包含此头文件

using namespace std;
class A
{
public:
     A() : m_f(open("./file", O_CREAT | O_RDWR, 0664)){
          cout << "A() is invoked - 打开了 file 文件" << endl;
     }

     ~A() {
          cout << "~A() is invoked - 关闭了 file 文件" << endl;
          close(m_f);
     }

     void foo() {
          cout << "foo() is invoked - 写入了 file 文件" << endl;
          write(m_f, "hello file", 10);
     }
private:
     int m_f;
};

class AutoPtr { // 自己设计的智能指针类
public:
     AutoPtr(A* a) : m_a(a){
          // A* m_a = a;
     }

     ~AutoPtr() {
          delete m_a;    // 释放用户申请的内存
     }

     A& operator*(){
          return *m_a;
     }

     A* operator->() {
          return m_a;
     }

     // 重载拷贝构造函数
     AutoPtr(AutoPtr& that) : m_a(that.m_a){
          // A* m_a = that.m_a;
          that.m_a = NULL;    // 地址间的转移代替复制
     }

private:
     A* m_a;    // 常规指针
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void)
{
     // 常规指针
     A* pa = new A;    // 定义 A类堆对象, 利用 A类堆对象.A()
     pa->foo();
     (*pa).foo();
     A* pb = pa;
     delete pa;        // pa->~A(), 释放 A类堆对象.A()

     // 自己设计的智能指针
     cout << "自己设计的智能指针" <<endl;
     AutoPtr pau = new A;     // 定义匿名 AutoPtr类对象, 利用匿名 AutoPtr类对象.AutoPtr(new A)
                              // AutoPtr pau = 匿名 AutoPtr类对象;
     (*pau).foo();            // pau.operator*().foo()
     pau->foo();              // pau.operator->()->foo()
     AutoPtr pbu = pau;       // 不进行重载拷贝构造函数和拷贝复制函数会导致 double free 错误
     pbu->foo();
     (*pbu).foo();

     // 标准库设计的智能指针
     cout << "标准库设计的智能指针" <<endl;
     auto_ptr <A> apa(new A);
     apa->foo();
     (*apa).foo();
     auto_ptr <A> bpa = apa;
     bpa->foo();
     (*bpa).foo();
     apa->foo();

     // unique_ptr
     unique_ptr <A> upa(new A);
     upa->foo();
     (*upa).foo();

     return 0;
} // 释放 pa本身所占的内存空间, 但是其并没有调用析构函数, 所以会导致内存泄漏
  // pau.~AutoPtr(), pau离开当前作用域, 自动调用 ~AutoPtr() 析构函数, 释放 A* m_a内存
  // 然后 pau 所占的内存被释放
