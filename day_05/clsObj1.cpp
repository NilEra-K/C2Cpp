/* 构造函数 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     // Human(Human* this, int age = 0, const char* name = "None");
     Human(int age = 0, const char* name = "None"){
          // 在 this 所指向的内存空间中, 定义 m_age(给 m_age分配内存空间), 初值为随机数
          // 在 this 所指向的内存空间中, 定义 m_name(给 m_name分配内存空间), 初值为随机数
          cout << "构造函数被调用" << endl;
          m_age = age;
          strcpy(m_name, name);
     }

     void setinfo(int age = 0, const char* name = "None"){
          m_age = age;
          strcpy(m_name, name);
     }

     void getinfo(){
          cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
     }

private:
     int m_age;
     char m_name[256];
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Human h(22, "张三");  // 定义 h, 给 h分配内存, 调用 h.Human()
     h.getinfo();
     return 0;
}
