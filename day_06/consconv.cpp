/* 类型转换构造函数 */
#include <iostream>
#include <cstring>
using namespace std;

class Cat {
public:
     // 这其实也是类型转换构造函数
     Cat(const char* name) : m_name(name) {
          // string m_name(name);
          cout << "Cat类的类型转换构造函数Cat(const char* name)被调用" << endl;
     }

     void talk(){
          cout << m_name << ": 喵喵~" << endl;
     }
private:
     friend class Dog;   // 友元声明
     string m_name;
};

class Dog {
public:
     Dog(const char* name) : m_name(name) {
          // string m_name(name);
     }

     // 类型转换构造函数
     // 当加入 explicit 关键字时, 必须强转
     explicit Dog(const Cat& that) : m_name(that.m_name){
          cout << "Dog 类的类型转换构造函数被调用" << endl;
     }

     void talk(){
          cout << m_name << ": 汪汪~" << endl;
     }
private:
     string m_name;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Cat smallWhite("小白");
     smallWhite.talk();

     Cat littleLemon = "小柠檬";
     littleLemon.talk();

     // Dog bigYellow(smallWhite); // 定义 bigYellow, 利用 bigYellow.Dog(smallWhite) -> 触发类型转换构造
     // Dog bigYellow = smallWhite;// 定义匿名 Dog类对象, 利用匿名 Dog类对象.Dog(smallWhite) -> 触发类型转换构造
                                   // Dog bigYellow = 匿名 Dog类对象;
     // 存在 explicit 关键字时, 可以强制这种通过类型转换构造函数实现的类型转换必须通过 静态转换(温和强转) 显式的进行
     Dog bigYellow = static_cast <Dog> (smallWhite);
     bigYellow.talk();
     return 0;
}
