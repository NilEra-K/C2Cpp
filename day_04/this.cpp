/* This参数 */
#include <iostream>
#include <cstring>

using namespace std;

// 该程序有两个对象, (h/h2), 每个对象中各有一份成员变量(共有两份成员变量)
// 而成员函数只有一份, 这些成员函数保存在代码区
class Human{
public:
     //                this 指针
     //                    v
     // void setinfo(Human* this, int age = 0, const char* name = "None");
     void setinfo(int age = 0, const char* name = "None"){
          m_age = age;
          strcpy(m_name, name);
     }

     // void getinfo(Human* this);
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
     // h.setinfo(&h, 22, "张三");
     h.setinfo(22, "张三");
     h.getinfo();

     Human h2;
     h.setinfo(20, "李四");
     h.getinfo();

     return 0;
}
