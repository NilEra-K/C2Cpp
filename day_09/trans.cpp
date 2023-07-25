/* 子类类型的指针或引用 能隐式转换为基类类型 */
/* 基类类型的指针或者引用 不能隐式转换为子类类型 */
#include <iostream>
using namespace std;

#pragma pack(1)     // 按照 1字节进行对齐
class Human {
public:
private:
     int m_age;
     string m_name;
};

class Student : public Human{
public:
private:
     int m_no;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Human h;
     cout << "基类对象 h 的大小为 " << sizeof(h) << endl;

     Student s;
     cout << "子类对象 s 的大小为 " << sizeof(s) << endl;

     // 编译器认为访问范围缩小是安全的(向下造型)
     // 子类类型指针(引用)可以隐式转换为基类类型指针(引用)
     // Student 类能看到 m_age、m_name、m_no
     // Human 类只能看到 m_age、m_name
     // 因此是安全的
     Human* ph = &s;     // Student* -> Human*  40 -> 36
     Human& rh = s;

     // 编译器认为访问范围扩大是危险的
     // 基类类型的指针或者引用 不能隐式转换为子类类型
     // Student 类能看到 m_age、m_name、m_no
     // Human 类只能看到 m_age、m_name
     // 因此是危险的, 通过强制类型转换虽然可以成功转换, 但是风险依然存在, 极其不建议强转
     // Student* ps = static_cast <Student*> (&h);   // Human* -> Student*
     // Student& rs = static_cast <Student&> (h);

     // 编译器对于类型安全的检测仅仅基于指针或者引用本身
     // Student* ps = ph;// Human* -> Student*
                         // 上面代码 36行 ph 引用 s, 此时定义一个 Student 指针指向 ph引用的对象
                         // 以人类的角度来说是 Student* 指向一个 Student
                         // 但是编译器认为这是不合理的
     // Student& rs = rh;
     // 当程序员判断合理时, 可以直接进行强转, 不会出现危险
     Student* ps = static_cast <Student*> (ph);
     Student& rs = static_cast <Student&> (rh);
     return 0;
}
