/* 常对象和常函数 */
#include <iostream>
#include <cstring>

using namespace std;
class Integer{
public:
     void setinfo(int i){ // 非常函数
          m_i = i;
     }

     // void getinfo(Integer* this);
     void getinfo(){ // 非常函数
          cout << "非常版本" << endl;
          cout << "m_i = " << m_i << endl;
     }

     // void getinfo(const Integer* this);
     void getinfo() const { // 常函数
          m_i = 8888;       // 常函数内部无法修改成员变量的值
                            // 当加入 mutable 关键字后可以进行修改
          // 或者使用 const_cast <Integer*> (this) 去除常属性
          // const_cast <Integer*> (this)->m_i = 8888;
          cout << "常版本" << endl;
          cout << "m_i = " << m_i << endl;
     }
private:
     // int m_i;
     mutable int m_i;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Integer ix;    // 非常对象
     ix.setinfo(1000);
     ix.getinfo();  // getinfo(&ix) -> 实参类型为 Integer*
                    // getinfo(Integer) 完全匹配

     const Integer cix = ix; // 需要初始化, 不初始化会报错
     cix.getinfo();          // getinfo(&cix) -> 实参类型为 const Integer*
                             // 没有非常版本时会报错
     return 0;
}

