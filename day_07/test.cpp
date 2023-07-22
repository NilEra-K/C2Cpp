/* 边角语法补充 */
#include <iostream>
#include <cstring>

using namespace std;

class A { }; // 空类
class B {
public:
     int m_i;
     // B m_b;      // 类中不能包含本类对象作为成员变量
     static B m_b;  // 类中能包含本类静态对象作为成员
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     A a;         // 空类占 1个字节的内存空间, 其中存储 1个字节的垃圾数据
     A& ra = a;   // 引用的对象不能为空, 否则 C++ 无法自圆其说——引用无法参照一个空壳
     cout << "sizeof(a) = " << sizeof(a) << endl;
     return 0;
}


