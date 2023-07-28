/* typeid 操作符——获取对象的类型信息 */
#include <iostream>
#include <typeinfo>
using namespace std;
class A { virtual void foo(){} };
class B : public A {};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者
int main(void) {
     int m;
     // 1. 获取类的类型信息
     // 2. 创建一个 type_info 类的对象
     // 3. 将获取的类的信息保存到 type_info 类对象的各个私有成员变量中
     // 4. 返回这个 type_info 类对象的常引用
     const type_info& tif = typeid(m);
     string tip = tif.name();
     cout << "m 的类型 : " << tip << endl;   // i

     // typeid 操作符存在局限性: 其无法获取到对象的常属性——const int 和 int 都是 i
     const int n = m;
     cout << "n 的类型 : " << typeid(m).name() << endl;     // i
     cout << (typeid(m) == typeid(n)) << endl;

     // 若基类不包含虚函数, typeid 所返回类型信息由该指针或引用本身的类型决定
     // 若基类至少包含一个虚函数, 即存在多态继承, typeid 所返回类型信息由该指针或引用的实际目标对象的类型决定
     B b; // 虚表指针 -> 编译器根据 B类信息制作的虚函数表
     A* pa = &b;
     A& ra = b;
     cout << "pa 的类型" << typeid(pa).name() << endl;
     // pa -> b对象所占的内存空间 -> 虚表指针 -> 根据 B类信息制作的虚函数表 -> "B"
     cout << "pa 指针目标对象的类型" << typeid(*pa).name() << endl;
     cout << "ra 引用目标对象的类型" << typeid(ra).name() << endl;
     return 0;
}


