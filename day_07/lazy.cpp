/* 单例模式(懒汉式): 设计一个类, 保证用户在使用这个类时, 只能出现一个对象 */
#include <iostream>
#include <cstring>
using namespace std;
class Singleton { // 懒汉式单例
public:
     // 以引用形式返回, 不会创建无名对象
     static Singleton& getInstance(){
          if(s_instance == NULL){
               s_instance = new Singleton; // 唯一对象
          }
          ++s_counter;
          return *s_instance;
     }

     // 当用户有对象的时候, 就无需定义为静态成员函数了
     void releaseInstance(){
          // 使用该方式可以解决多个线程调用时
          // 可能会导致的对象释放, 其他对象无法使用的问题
          if(--s_counter == 0){
               delete s_instance;
               s_instance = NULL;
          }
     }
private:
     Singleton() { }                     // 私有化构造函数
     Singleton(const Singleton& that){ } // 私有化拷贝构造函数
     static Singleton* s_instance;       // 并不是唯一对象, 仅仅是一个指针
     static int s_counter;               // 计数功能
};

Singleton* Singleton::s_instance = NULL;  // 程序启动时, 唯一的对象不存在
int Singleton::s_counter = 0;

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Singleton& s1 = Singleton::getInstance(); // 第一次调用 getInstance() 函数时, 创建唯一的对象
     Singleton& s2 = Singleton::getInstance(); // 以后在调用 getInstance() 函数时, 返回第一次调用创建的对象
     Singleton& s3 = Singleton::getInstance();
     cout << "&s1 = " << &s1 << endl
          << "&s2 = " << &s2 << endl
          << "&s3 = " << &s3 << endl;
     s1.releaseInstance();
     s2.releaseInstance();
     s3.releaseInstance(); // 最后一次调用 releaseInstance() 函数才将对象销毁
     
     return 0;
}


