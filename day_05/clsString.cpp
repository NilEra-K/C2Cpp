/* string 类的使用 */
#include <iostream>
#include <cstring>

using namespace std;
// C++ 标准库设计的 string 类, 内部有一个成员 char* m_psz -> 一个字符串

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     string s1("Hello"); // 定义 s1, 利用 s1.string("Hello")
                         // s1 维护字符串为 "Hello"
     cout << "s1 = " << s1.c_str() << endl;
     cout << "s1 = " << s1 << endl;

     // 如果在做初始化, 并且 "=" 两边的类型完全一致, 那么 = xxx 和 (xxx) 无差别
     string s2 = s1;     // 与 string s2(s1) 无差别
     cout << "s2 = " << s2.c_str() << endl;
     cout << "s2 = " << s2 << endl;

     string s3;
     cout << "s3 = " << s3.c_str() << endl;
     cout << "s3 = " << s3 << endl;
     // 如果在做赋值, 并且 "=" 两边的类型完全一致, 那么将触发 operator= 函数
     s3 = s2;  // s3.operator=(s2), s3 维护的字符串和 s2 维护的字符串内容相同
     cout << "s3 = " << s3.c_str() << endl;
     cout << "s3 = " << s3 << endl;

     // 只要 "=" 两边的类型不一致, 编译器就会尝试将 "=" 右边的类型转换为和 "=" 左边的类型一致
     string s4 = "Hello";
     cout << "s4 = " << s4.c_str() << endl;
     cout << "s4 = " << s4 << endl;
     return 0;
}
