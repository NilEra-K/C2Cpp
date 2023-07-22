/* 单例模式(饿汉式): 设计一个类, 保证用户在使用这个类时, 只能出现一个对象 */
#include <iostream>
#include <cstring>
using namespace std;
class Singleton { // 饿汉式单例
public:
     // 以引用形式返回, 不会创建无名对象
     static Singleton& getInstance(){
          return s_instance;
     }
private:
     Singleton() { }                     // 私有化构造函数
     Singleton(const Singleton& that){ } // 私有化拷贝构造函数
     static Singleton s_instance;        // 我们来提供唯一对象
};

Singleton Singleton::s_instance;

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Singleton& s1 = Singleton::getInstance();
     Singleton& s2 = Singleton::getInstance();
     Singleton& s3 = Singleton::getInstance();
     cout << "&s1 = " << &s1 << endl
          << "&s2 = " << &s2 << endl
          << "&s3 = " << &s3 << endl;
     return 0;
}


