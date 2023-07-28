/* 动态类型转换: 基类类型指针 转换为 子类类型指针 */
/*           : 基类类型引用 转换为 子类类型引用 */
#include <iostream>
using namespace std;
class A { // 编译器根据 A类的信息构造一张虚函数表, 保存 A::foo() 的地址
          // A 类类型信息 | A 类虚函数表
          // A 类类型信息 | A::foo()
     virtual void foo(){} 
};
class B : public A { // 编译器根据 B类的信息构造一张虚函数表, 保存 A::foo() 的地址
                     // B 类类型信息 | B 类虚函数表
                     // B 类类型信息 | A::foo()
};

class C : public B { // 编译器根据 C类的信息构造一张虚函数表, 保存 A::foo() 的地址
                     // C 类类型信息 | C 类虚函数表
                     // C 类类型信息 | A::foo()
};
class D {};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者
int main(void) {
     B b;
     A* pa = &b;    // B* -> A* 子类类型指针 转换为 基类类型指针, 编译器认为安全, 可以隐式转换

     cout << ">>> dynamic_cast" << endl;
     B* pb = dynamic_cast <B*> (pa);    // 即合理又安全
                                        // pa -> b对象所占的内存空间 -> 虚表指针 -> 编译器根据 B类信息制作的虚函数表 -> 类名 "B"
     cout << "A* pa -> B* pb :" << pb << endl;

     C* pc = dynamic_cast <C*> (pa);    // 有风险
                                        // pa -> b对象所占的内存空间 -> 虚表指针 -> 编译器根据 B类信息制作的虚函数表 -> 类名 "B"
     cout << "A* pa -> C* pc :" << pc << endl;

     D* pd = dynamic_cast <D*> (pa);    // 不合理
                                        // pa -> b对象所占的内存空间 -> 虚表指针 -> 编译器根据 B类信息制作的虚函数表 -> 类名 "B"
     cout << "A* pa -> D* pd :" << pd << endl;

     cout << ">>> dynamic_cast for reference" << endl;
     A& ra = b;
     B& rb = dynamic_cast <B&> (ra);
     cout << "A& ra -> B& rb : OK" << endl;
     C& rc = dynamic_cast <C&> (ra);
     cout << "A& ra -> C& rd : BAD_CAST" << endl;
     D& rd = dynamic_cast <D&> (ra);
     cout << "A& ra -> D& rd : BAD_CAST" << endl;

     cout << ">>> static_cast" << endl;
     B* pb = static_cast <B*> (pa);    // 即合理又安全
                                       // A* -> B* 反方向 B* -> A*
     cout << "A* pa -> B* pb :" << pb << endl;
     C* pc = static_cast <C*> (pa);    // 有风险
                                       // A* -> C* 反方向 C* -> A*
     cout << "A* pa -> C* pc :" << pc << endl;
     // D* pd = static_cast <D*> (pa);
     // cout << "A* pa -> D* pd :" << pd << endl;

     return 0;
}


