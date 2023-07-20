/* 定义类的对象的 10 种方法 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     // Human(Human* this, int age = 0, const char* name = "None");
     Human(int age = 0, const char* name = "None");
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

void Human::getinfo(){
     cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
}

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Human h(22, "张三");  // 定义 h, 给 h分配内存, 调用 h.Human()
     h.getinfo();

     Human h2;
     h2.getinfo();

     Human h3[3];
     for(int i = 0; i < 3; i++){
          h3[i].getinfo();
     }

     Human h4[3] = {Human(22, "张三"), Human(23, "李四"), Human(24, "王五")};
     for(int i = 0; i < 3; i++){
          h4[i].getinfo();
     }

     Human h5[] = {Human(22, "张三"), Human(23, "李四"), Human(24, "王五"), Human(25, "赵六")};
     for(int i = 0; i < sizeof(h5)/sizeof(h5[0]); i++){
          h5[i].getinfo();
     }

     Human* ph = new Human;    // 定义 Human类堆对象, 利用 Human类堆对象.Human()
     (*ph).getinfo();
     delete ph;
     ph = NULL;

     Human* ph2 = new Human(); // 定义 Human类堆对象, 利用 Human类堆对象.Human()
     (*ph2).getinfo();
     delete ph2;
     ph2 = NULL;

     Human* ph3 = new Human(22, "张三"); // 定义 Human类堆对象, 利用 Human类堆对象.Human()
     (*ph3).getinfo();
     delete ph3;
     ph3 = NULL;

     Human* ph4 = new Human[3];// 定义 3个 Human类对象, 分别利用这 3个 Human类堆对象.Human()
     for(int i = 0; i < 3; i++){
          ph4[i].getinfo();
     }
     delete ph4;
     ph4 = NULL;

     Human* ph5 = new Human[3] {Human(22, "张三"), Human(23, "李四"), Human(24, "王五")};
     for(int i = 0; i < 3; i++){
          ph5[i].getinfo();
     }
     delete ph5;
     ph5 = NULL;
     return 0;
}
