/* 拷贝构造函数被调用的时机 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(int age = 0, const char* name = "None"){
          // 在 this指向的内存空间中, 定义 m_age, 初值为 随机数
          // 在 this指向的内存空间中, 定义 m_name, 利用 m_name.string()
          // this->getinfo();    // 验证上面两句话
          // 在 this指向的内存空间中, 定义 m_a, 利用 m_a.string() 无参构造
          // [ERROR] no matching function for call to ‘A::A()’ 类 "A" 不存在默认构造参数
          // cout << "Human 类的缺省构造函数被调用" << endl;
          m_age = age;
          m_name = name;
     }

     Human(const Human& that) {
          // 在 this指向的内存空间中, 定义 m_age 但是不赋予初始值
          // 在 this指向的内存空间中, 定义 m_name 但是不调用拷贝构造函数
          // this->getinfo(); // 验证上面两句话, 这里应该输出随机数
          cout << "Human 类的拷贝构造函数被调用" << endl;
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

void foo(Human hm){

}

Human bar() {
     Human m;
     return m;
}

int main(void){
     // 用已定义对象作为同类型对象的构造实参
     Human h(22, "张三");
     Human h2(h);   // 定义 h2, 利用 h2.human(h) -> 触发拷贝构造函数的调用

     // 以对象形式向函数传递参数
     foo(h2);       // 将 h2 复制一份到 foo() -> 触发拷贝构造函数的调用

     // 从函数中返回对象
     cout << "bar" << endl;
     bar();              // 将触发 1次拷贝构造函数
     Human h3 = bar();   // 将触发 2次拷贝构造函数
                         // 一次是在 bar() 函数中, return 返回匿名内存时触发一次
                         // 一次是在 Human h3 = 匿名对象; 时触发一次
                         // 我们看不到此处的结果是因为此处被编译器优化了
     // 注意: 某些拷贝构造过程会因编译优化而被省略
     // 使用 g++ copyconstime.cpp -o copyconstime -fno-elide-constructors 可以查看编译器没有进行优化的结果
     return 0;
}
