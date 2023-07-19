/* 类的声明与实现分开 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     // Human(Human* this, int age = 0, const char* name = "None");
     Human(int age = 0, const char* name = "None");
     // void getinfo(){  // 声明 + 定义
     //      cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
     // }
     void getinfo();
private:
     int m_age;          // 声明
     char m_name[256];   // 声明
};

Human::Human(int age, const char* name){
     cout << "构造函数被调用" << endl;
     m_age = age;
     strcpy(m_name, name);
}

void Human::getinfo(){   // 定义
     cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
}

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Human h(22, "张三");  // 定义 h, 给 h分配内存, 调用 h.Human()
     h.getinfo();
     return 0;
}
