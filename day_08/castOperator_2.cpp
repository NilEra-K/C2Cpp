/* 类型转换构造函数 和 类型转换构造符函数 */
#include <iostream>
#include <cstring>
using namespace std;

class Dog;

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

     operator Dog(/*| const Cat* this |*/) const;
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
     // Dog(const Cat& that) : m_name(that.m_name){
     //      cout << "Dog 类的类型转换构造函数被调用" << endl;
     // }

     // 类型转换操作符函数

     void talk(){
          cout << m_name << ": 汪汪~" << endl;
     }
private:
     string m_name;
};

Cat::operator Dog(/*| const Cat* this |*/) const {
     return Dog(this->m_name.c_str());
}


// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Cat smallWhite("小白");

     Dog bigYellow = smallWhite;   // 定义匿名 Dog类对象, 利用匿名 Dog类对象.Dog(smallWhite) -> 触发类型转换构造
                                   // Dog bigYellow = 匿名 Dog类对象;
                                   // 当类型转换函数被屏蔽时, 编译器会尝试调用类型转换操作符函数
                                   // Dog bigYellow = smallWhite.operator Dog() -> 触发类型转换操作符函数
     return 0;
}
