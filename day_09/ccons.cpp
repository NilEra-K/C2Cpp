/* 子类的构造函数 和 析构函数 */
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

     ~Human(){
          cout << "Human析构函数被调用" << endl;
     }

     void getinfo(){
          cout << "姓名 : " << m_name << " 年龄 : " << m_age;
     }

private:
     int m_age;
     string m_name;
};

class Student : public Human {
public:
     // 子类没有定义构造函数, 编译器为子类提供的默认无参构造函数
     // Student() {
     //      Human();  // 定义基类子对象, 
     //                // 无名对象 - 并不是所有的匿名对象生命周期都短暂
     //                // 以下两种无名对象的生命周期就很长
     //                // new Human;
     //                // 基类子对象;
     //      float m_socre;
     //      string m_remark;
     // }

     // 子类定义构造函数但没有在初始化表中指明基类部分构造方式
     // Student(int age = 0, const char* name = "None", float score = 0.0, const char* remark = "Good") :
     //           m_score(score), m_remark(remark){
     //      // Human();
     //      // float m_score = score;
     //      // string m_remark = remark;
     // }

     // 子类定义构造函数并在初始化表中指明基类构造方式
     Student(int age = 0, const char* name = "None", float score = 0.0, const char* remark = "Good") :
               Human(age, name), m_score(score), m_remark(remark){
          // Human(age, name);
          // float m_score = score;
          // string m_remark = remark;
     }

     void getinfo() {
          Human::getinfo();
          cout << " 分数 : " << m_score << " 评语 : " << m_remark << endl;
     }

     // 子类提供的默认析构函数
     // ~Student() {
     //      // m_remark.~string(); // 对于 m_remark, 利用 m_remark.~srting()
     //      // Human::~Human();    // 对于基类子对象, 利用基类子对象.~Human();
     //      // 释放 m_score/m_remark/基本子对象本身所占内存空间
     // }

     // 子类定义析构函数
     ~Student() {
          cout << "Student类的析构函数被调用" << endl;
          // m_remark.~string(); // 对于 m_remark, 利用 m_remark.~srting()
          // Human::~Human();    // 对于基类子对象, 利用基类子对象.~Human();
          // 释放 m_score/m_remark/基本子对象本身所占内存空间
     }
private:
     float m_score;      // 成绩
     string m_remark;    // 评语
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     cout << ">>> Create Class" << endl;
     Student s1;
     s1.getinfo();

     Student s2(22, "张三", 12.5, "Bad");
     s2.getinfo();
     cout << ">>> Main Will Over" << endl;
     return 0;
} // s1.~Student(); 释放 s1 本身所占的内存空间
  // s2.~Student(); 释放 s2 本身所占的内存空间