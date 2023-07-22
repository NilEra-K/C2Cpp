/* 默认的拷贝构造和拷贝赋值函数, 在特定的场景下(类中有指针成员), 会出现浅拷贝的缺陷 */
#include <iostream>
#include <cstring>

using namespace std;

// 模拟 C++ 标准库的 string 类, 自己设计一个 String 类
class String {
public:
     String(const char* psz = "") : m_psz(new char[strlen(psz) + 1]) {
          // 定义 m_psz, 初值为指向一块堆内存(动态资源)
          // char* m_psz = new char[strlen(psz) + 1];
          strcpy(m_psz, psz); // 将 psz中的字符串拷贝到堆内存中
     }

     // 默认的拷贝构造函数
     /* *********************************************
     String(const String& that) {
          // char* m_psz = that.m_psz;
          // 只复制了地址, 没有复制地址指向的数据 -> 浅拷贝
     }
     ********************************************* */

     // 深拷贝构造
     String (const String& that) : m_psz(new char[strlen(that.m_psz) + 1]){
          // char* m_psz = new char[strlen(that.m_psz) + 1];
          strcpy(m_psz, that.m_psz);    // 不复制地址, 而复制地址所指向的数据 -> 深拷贝
     }

     // 默认的拷贝赋值函数
     /* *********************************************
     String operator=(const String& that) {
          this->m_psz = that.m_psz;
          // 只复制了地址, 没有复制地址指向的数据 -> 浅拷贝
          return *this;
     }
     ********************************************* */

     // 深拷贝赋值
     String operator=(const String& that) {
          // 防止用户自己给自己赋值, 出现 str = str 的写法
          // 当满足条件时才进行代码的执行
          if(this != &that){ 
               delete[] this->m_psz;         // 释放旧资源
               this->m_psz = new char[strlen(that.m_psz) + 1]; // 申请新资源
               strcpy(m_psz, that.m_psz);    // 复制数据
          }
          return *this;
     }

     ~String(){
          delete[] m_psz;
     }

     char* c_str() { return m_psz; }

private:
     char* m_psz;   // 指针型成员变量
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     String s1("Hello");
     // cout 遇到 char* 会打印其指向的字符串
     // 为了防止此问题需要将其强制转化为 void* 型指针
     cout << "s1 = " << s1.c_str() << endl
          << "s1 所执指向的堆内存的地址为: " << (void*)s1.c_str() << endl;

     String s2(s1); // 触发拷贝构造
     cout << "s2 = " << s2.c_str() << endl
          << "s2 所执指向的堆内存的地址为: " << (void*)s2.c_str() << endl;

     String s3;     // 定义 s3, 利用 s3.String() -> 维护一个字节的内存 "\0"
     s3 = s2;       // s3.operatot=(s2) 拷贝赋值, 也发生了浅拷贝现象
     cout << "s3 : " << s3.c_str() << endl
          << "s3 所执指向的堆内存的地址为: " << (void*)s3.c_str() << endl;

     return 0;
} // s1.~String()   s2.~String() 浅拷贝的情况下, 会导致段错误 double free, 对一块相同的地址空间进行多次释放
  // s2.~String()   s3.~String() 浅拷贝的情况下, 会导致段错误 double free, 对一块相同的地址空间进行多次释放



