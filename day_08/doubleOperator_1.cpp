/* 运算类双目操作符函数 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(int age = 0, const char* name = "None") : m_age(age), m_name(name){
          // cout << "Human 类的缺省构造函数被调用" << endl;
     }

     // 成员形式的操作符函数
     //                                                 使得 this 指针带有常属性 
     //                                                            v
     Human operator+(/*| const Human* this |*/const Human& that) const {
          return Human(this->m_age + that.m_age, (this->m_name + "+" + that.m_name).c_str());
     }

     void getinfo(){
          cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
     }
private:
     // friend Human operator+(const Human& l, const Human& r); // 友元声明
     int m_age;     // 基本类型的成员函数
     string m_name; // 类类型的成员变量
};

// 全局形式的操作符函数
// Human operator+(const Human& l, const Human& r) {
//      return Human(l.m_age + r.m_age, (l.m_name + "+" + r.m_name).c_str());
// }

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     // 基本数据类型
     // int a = 3, b = 4;   // 非常左值
     // const int c = 5;    // 常左值
     // a + b;              // 非常左值 + 非常左值
     // a + c;              // 非常左值 + 常左值
     // a + 5;              // 非常左值 + 右值
     // c + 5;              // 常左值 + 右值 

     Human a(22, "张三");
     Human b(24, "李四");
     const Human c(26, "王五");
     const Human d(28, "赵六");
     // 非常左值 + 非常左值
     Human res = a + b;    // a.operator+(b) 或 operator+(a, b)
     res.getinfo();

     // 常左值 + 常左值
     res = c + d;    // c.operator+(d) 或 operator+(c, d)
     res.getinfo();

     // 右值 + 右值
     res = Human(30, "刘七") + Human(32, "周八");  // Human(30, "刘七").operator+(Human(32, "周八"))
                                                  // operator(Human(30, "刘七"), Human(32, "周八"))
     res.getinfo();
     return 0;
}
