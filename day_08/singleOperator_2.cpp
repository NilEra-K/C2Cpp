/* 前自增减类单目操作符函数 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(int age = 0, const char* name = "None") : m_age(age), m_name(name){
          // cout << "Human 类的缺省构造函数被调用" << endl;
     }

     // 成员形式操作符函数
     Human& operator++() {
          this->m_age += 1;
          return *this;
     }

     Human operator++(int) { // 哑元
          Human old = *this;  // 备份 b原来的值
          this->m_age += 1;   // 直接加 1
          return old;
     }

     void getinfo(){
          cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
     }
private:
     friend ostream& operator<<(ostream& os, const Human& that);
     friend istream& operator>>(istream& os, Human& that);
     int m_age;     // 基本类型的成员函数
     string m_name; // 类类型的成员变量
};

ostream& operator<<(ostream& os, const Human& that) {
     os << "姓名: " << that.m_name << " 年龄" << that.m_age;
     return os;
}

istream& operator>>(istream& is, Human& that) {
     is >> that.m_name >> that.m_age;
     return is;
}


// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     // 基本数据类型
     // int a = 3, b = 4;   // 非常左值
     // const int c = 5;    // 常左值
     // ++a;                // [OK] 非常左值
     // ++c;                // [ERROR] 常左值无法修改
     // ++5;                // [ERROR] 右值无法修改
     // | 4 | b++;          // b++ 表达式结果为右值, 且为自增减以前的值
                            // 也就所说, 无名内存中存储了 4, 但是其实此时 b已经完成了自增
                            // 我们使用的其实是无名内存中的值

     Human a(22, "张三");
     Human b(24, "李四");
     const Human c(26, "王五");
     const Human d(28, "赵六");

     ++a;      // a.operator++() 或 operator++(a)
     cout << ++a << endl;

     cout << b++ << endl; // b.operator++(0) 或 operator++(b, 0)
                          // 为了和 ++b 区分, b会在调用时补一个 0
     cout << b << endl;
     return 0;
}
