/* 初始化表 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(int age = 0, const char* name = "None") : m_age(age), m_name(name){
          // 在 this指向的内存空间中, 定义 m_age, 初值为 age
          // 在 this指向的内存空间中, 定义 m_name, 利用 m_name.string(name)
          cout << "Human 类的缺省构造函数被调用" << endl;
          // 以下这两行就不需要了
          // m_age = age;
          // m_name = name;
     }
     
     Human(const Human& that) : m_age(that.m_age), m_name(that.m_name){
          // 在 this指向的内存空间中, 定义 m_age 赋予初始值为 that.m_age
          // 在 this指向的内存空间中, 定义 m_name 调用拷贝构造函数 m_name.string(that.m_name)
          // this->getinfo(); // 验证上面两句话, 这里应该输出随机数
          cout << "Human 类的拷贝构造函数被调用" << endl;
          // this->m_age = that.m_age;
          // this->m_name = that.m_name;
     }

     // 如果一个类没有定义拷贝赋值函数, 那么编译器会为其提供一个默认的拷贝赋值函数
     /* **********************************************************************
     Human& operator=(const Human& that){
          this->m_age = that.m_age;
          this->m_name = that.m_name;   // this->m.name.operator=(that,m_name)
          return *this;
     }
     ********************************************************************** */
     // Human& 返回值是为了使用串连赋值
     Human& operator=(const Human& that){
          // 编译器不会在自定的拷贝赋值函数中补充任何操作
          cout << "Human 类的拷贝赋值函数被调用" << endl;
          this->m_age = that.m_age;
          this->m_name = that.m_name;
          return *this;
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
     h4 = h3;       // 调用 拷贝赋值函数
     h4.getinfo();
     h4 = h3 = h;   // 当拷贝赋值函数的返回值为 Human& 时可以使用串连调用
     h4.getinfo();
     return 0;
}
