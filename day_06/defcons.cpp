/* 无参构造 */
#include <iostream>
#include <cstring>

using namespace std;

class A {
public:
     // 必须为一个类提供无参(缺省)构造函数
     // 因为这个类对象可能作为另一个类的成员变量
     A(int i = 0){
          m_i = i;
     }
private:
     int m_i;
};

class Human{
public:
     // 如果类没有提供任何构造函数, 编译器将提供一个无参构造函数
     // 也就是说, 如果提供了其他构造函数, 编译器将不再提供无参构造
     /* ************************************************************
     Human(){
          // 在 this指向的内存空间中, 定义 m_age, 初值为 随机数
          // 在 this指向的内存空间中, 定义 m_name, 利用 m_name.string()
     }
     ************************************************************ */

     // 
     Human(int age = 0, const char* name = "None"){
          // 在 this指向的内存空间中, 定义 m_age, 初值为 随机数
          // 在 this指向的内存空间中, 定义 m_name, 利用 m_name.string()
          // this->getinfo();    // 验证上面两句话
          // 在 this指向的内存空间中, 定义 m_a, 利用 m_a.string() 无参构造
          // [ERROR] no matching function for call to ‘A::A()’ 类 "A" 不存在默认构造参数
          cout << "Human 类的缺省构造函数被调用" << endl;
          m_age = age;
          m_name = name;
     }

     void getinfo(){
          cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
     }

private:
     int m_age;     // 基本类型的成员函数
     string m_name; // 类类型的成员变量
     A m_a;         // 类类型成员变量: 没有提供无参构造
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Human h;
     h.getinfo();

     return 0;
}
