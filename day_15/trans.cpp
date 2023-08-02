/* 移动语义 */
// 编译时使用下面命令
// g++ trans.cpp -o trans -std=c++11 -fno-elide-constructors
#include <iostream>
#include <cstring>

using namespace std;

// 模拟 C++ 标准库的 string 类, 自己设计一个 String 类
class String {
public:
     String(const char* psz = "") : m_psz(new char[strlen(psz) + 1]) {
          strcpy(m_psz, psz); 
     }

     // 深拷贝构造
     String (const String& that) : m_psz(new char[strlen(that.m_psz) + 1]){
          cout << "深拷贝构造函数被调用" << endl;
          strcpy(m_psz, that.m_psz);
     }

     // 转移构造函数——体现为资源的转移
     String (String&& that) : m_psz(that.m_psz){
          // char* m_psz = that.m_psz;
          that.m_psz = NULL;
          cout << "转移构造函数被调用" << endl;
     }

     // 深拷贝赋值——体现为资源的重建
     String operator=(const String& that) {
          cout << "深拷贝赋值被调用" << endl;
          if(this != &that){ 
               delete[] this->m_psz;
               this->m_psz = new char[strlen(that.m_psz) + 1];
               strcpy(m_psz, that.m_psz);
          }
          return *this;
     }

     // 转移赋值函数——体现为资源的转移
     String operator=(String&& that) {
          cout << "转移赋值被调用" << endl;
          delete[] this->m_psz;
          this->m_psz = that.m_psz;
          that.m_psz = NULL;
          return *this;
     }

     ~String(){
          delete[] m_psz;
     }

     char* c_str() { return m_psz; }

private:
     char* m_psz;
};

int main(void){
     String a("Hello");
     cout << ">>> 1" << endl;
     String b = a;                 // 定义 b , 利用 b.String(a) -> 触发 String 类深拷贝构造函数

     cout << ">>> 2" << endl;
     String c = String("World");   // 定义 c , 利用 c.String(String("world")) -> 触发 String 类的深拷贝构造函数
                                   // 但是, String("World") 是一个将亡值, 也就是说, 我们用转移资源代替重建资源
                                   // 使用右值引用来进行操作
     cout << ">>> 3" << endl;
     String d, e;
     d = a;

     cout << ">>> 4" << endl;
     e = String("World");
     return 0;
}


