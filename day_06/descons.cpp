/* 析构函数 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(int age = 0, const char* name = "None") : m_age(age), m_name(name){
          cout << "Human 类的缺省构造函数被调用" << endl;
     }
     
     Human(const Human& that) : m_age(that.m_age), m_name(that.m_name){
          cout << "Human 类的拷贝构造函数被调用" << endl;
     }

     Human& operator=(const Human& that){
          cout << "Human 类的拷贝赋值函数被调用" << endl;
          this->m_age = that.m_age;
          this->m_name = that.m_name;
          return *this;
     }

     // 默认析构函数
     /* ****************************************************
     ~Human() {
          // 对于基本类型的成员变量 m_age, 什么都不做
          // 对于类类型的成员变量 m_name, 调用 m_name.~string()
          // 释放 m_age/m_name 本身所占的内存空间
     }
     **************************************************** */

     // 当程序员提供析构函数的时候, 编译器会把默认析构的操作添加到自定义析构的最后
     ~Human(){
          cout << "析构函数被调用" << endl;
          // 对于基本类型的成员变量 m_age, 什么都不做
          // 对于类类型的成员变量 m_name, 调用 m_name.~string()
          // 释放 m_age/m_name 本身所占的内存空间
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
     cout << "--------- h 的创建信息 ---------" << endl;
     Human h;
     h.getinfo();
     cout << endl;

     cout << "--------- h2的创建信息 ---------" << endl;
     Human h2(22, "张三");
     h2.getinfo();
     cout << endl;

     cout << "--------- h3的创建信息 ---------" << endl;
     Human h3(h2);  // Human h3 = h2;
     h3.getinfo();
     cout << endl;

     cout << "--------- h4的创建信息 ---------" << endl;
     Human h4;
     h4.getinfo();
     return 0;
} // (1) h.~Human() h2.~Human() h3.~Human() h4.~Human()
  // (2) 释放 h/h2/h3/h4 这四个对象本身占内存空间

