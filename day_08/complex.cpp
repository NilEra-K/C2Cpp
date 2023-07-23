/* 操作符重载 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(int age = 0, const char* name = "None") : m_age(age), m_name(name){
          // cout << "Human 类的缺省构造函数被调用" << endl;
     }

     // 使用 c_str() 函数把 string 转化为 const char*
     Human sum(Human that){
          return Human(this->m_age + that.m_age, (this->m_name + "+" + that.m_name).c_str());
     }

     Human sub(Human that){
          return Human(this->m_age - that.m_age, (this->m_name + "-" + that.m_name).c_str());
     }

     void getinfo(){
          cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
     }
private:
     int m_age;     // 基本类型的成员函数
     string m_name; // 类类型的成员变量
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Human a(22, "张三");
     Human b(24, "李四");
     Human c(26, "王五");
     Human d(28, "赵六");

     Human res = a.sum(b);    // a + b; -> 编译器有能力将其看作 a.operator+(b) 或 operator+(a, b)
     res.getinfo();

     res = c.sub(d);          // a - b; -> 编译器有能力将其看作 a.operator-(b) 或 operator-(a, b)
     res.getinfo();
     return 0;
}
