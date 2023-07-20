/* 类: 抽取事物特征的规则 */
#include <iostream>
#include <cstring>

using namespace std;

// struct
class Human{
public:
     void setinfo(int age = 0, const char* name = "None"){
          if(!strcmp(name, "Hello")){
               // 可以通过这种方式来进行保护私有成员变量不能通过成员函数篡改
               cout << "禁止的修改名" << endl;
               return;
          }
          m_age = age;
          strcpy(m_name, name);
     }

     void getinfo(void){
          cout << "姓名: " << m_name << " 年龄: " << m_age << endl;
     }
private:
     int m_age;
     char m_name[256];
};
// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Human h;  // 定义 h, 定义就是给 h分配内存
               // 在 h所占据的内存空间中, 定义 m_age(给 m_age分配内存空间), 初值为随机数
               // 在 h所占据的内存空间中, 定义 m_name(给 m_name分配内存空间), 初值为随机数
     cout << "sizeof(h): " << sizeof(h) << endl;  // [OUTPUT] sizeof(h): 260
     h.setinfo(22, "张三");
     h.setinfo(22, "Hello");
     h.getinfo();
     return 0;
}
