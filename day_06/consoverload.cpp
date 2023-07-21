/* 构造函数的重载 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(){
          cout << "无参构造" << endl;
          m_age = 0;
          m_name = "None";
     }

     Human(int age){
          cout << "Human(int)" << endl;
          m_age = age;
          m_name = "None";
     }

     Human(int age, const char* name){
          cout << "Human(int, const char*)" << endl;
          m_age = age;
          m_name = name;
     }

     void getinfo(){
          cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
     }

private:
     int m_age;
     string m_name;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Human h;
     h.getinfo();

     Human h2(22);
     h2.getinfo();

     Human h3(22, "张三");
     h3.getinfo();
     return 0;
}
