/* 赋值类双目操作符函数 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(int age = 0, const char* name = "None") : m_age(age), m_name(name){
          // cout << "Human 类的缺省构造函数被调用" << endl;
     }

     void getinfo(){
          cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
     }

     // 成员形式的操作数函数
     Human& operator+=(const Human& that) {
          this->m_age = this->m_age + that.m_age;
          this->m_name = this->m_name + "+" + that.m_name;
          return *this;
     }
private:
     int m_age;     // 基本类型的成员函数
     string m_name; // 类类型的成员变量
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     // 基本数据类型
     // int a = 3, b = 4;   // 非常左值
     // const int c = 5;    // 常左值
     // a = b;              // 非常左值 = 非常左值
     // a = c;              // 非常左值 = 常左值
     // a = 5;              // 非常左值 = 右值
     // c = 5;              // [ERROR] 常左值 = 右值
     // 5 = b;              // [ERROR] 右值 = 非常左值
     Human a(22, "张三");
     Human b(24, "李四");
     const Human c(26, "王五");
     const Human d(28, "赵六");

     a += b;        // a.operator+=(b);
     a.getinfo();

     a += c;        // a.operator+=(c);
     a.getinfo();

     a += Human(30, "刘七");  // a.operator+=(Human(30, "刘七"));
     a.getinfo();
     return 0;
}
