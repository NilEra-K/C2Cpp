/* 必须使用初始化表的情况 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(int age = 0, const char* name = "None", float score = 0.0) : m_age(age), m_name(name), m_score(score), m_len(m_name.size()){
          // 在 this指向的内存空间中, 定义 m_len, 初值为名字的长度
          // 在 this指向的内存空间中, 定义 m_age, 初值为 age
          // 在 this指向的内存空间中, 定义 m_name, 利用 m_name.string(name)
          // 在 this指向的内存空间中, 定义 m_score
          // 定义语句如下, const float m_socre, 此时必须指定初始化表构成 const float m_score = xxx;
          cout << "Human 类的缺省构造函数被调用" << endl;
     }
     
     Human(const Human& that) : m_age(that.m_age), m_name(that.m_name), m_score(that.m_score), m_len(m_name.size()){
          cout << "Human 类的拷贝构造函数被调用" << endl;
     }

     void getinfo(){
          cout << "姓名 : " << m_name 
               << " 年龄 : " << m_age
               << " 分数 : " << m_score 
               << " 名字长度 : " << m_len << endl;
     }

private:
     // int m_len;        // 在此处声明会导致名字长度无法取得正确值, 因为在构造时并没有定义 m_name
                          // 但是我们可以通过防止牵扯其它成员变量来避免顺序问题
                          // 比如我们可以从形参中得到此长度
     int m_age;
     string m_name;
     const float m_score; // 常量型的成员变量
     // int& m_teacher;   // 引用型的成员变量
     int m_len;           // 保存名字的长度
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
     Human h2(22, "张三", 99.9);
     h2.getinfo();
     cout << endl;

     cout << "--------- h3的创建信息 ---------" << endl;
     Human h3(h2);  // Human h3 = h2;
     h3.getinfo();
     cout << endl;

     return 0;
}
