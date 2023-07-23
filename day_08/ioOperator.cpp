/* 输入输出操作符的重载 */
#include <iostream>
#include <cstring>

using namespace std;

class Human{
public:
     Human(int age = 0, const char* name = "None") : m_age(age), m_name(name){
          // cout << "Human 类的缺省构造函数被调用" << endl;
     }

     // 可以被替换掉
     void getinfo(){
          cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
     }
private:
     friend ostream& operator<<(ostream& os, const Human& that);
     friend istream& operator>>(istream& os, Human& that);
     int m_age;     // 基本类型的成员函数
     string m_name; // 类类型的成员变量
};

// 成员形式操作符函数
// cout 调用, 也就是 ostream 类, 但是我们无法在 ostream 类中添加代码
// 因此我们只能以全局形式重载这个操作符
//                        cout
//                         v
ostream& operator<<(ostream& os, const Human& that) {
     os << "姓名: " << that.m_name << " 年龄" << that.m_age;
     return os;
}

istream& operator>>(istream& is, Human& that) {
     is >> that.m_name >> that.m_age;
     return is;
}

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     // 基本数据类型
     // int a = 3, b = 4;   // 非常左值
     // const int c = 5;    // 常左值
     // cout << a;          // 输出流对象 cout << 非常左值;
     // cout << c;          // 输出流对象 cout << 常左值;
     // cin >> a;           // 输入流对象 cin >> 非常左值;
     // cin >> c;           // [ERROR] 输入流对象 cin >> 常左值;

     Human a(22, "张三");
     Human b(24, "李四");
     const Human c(26, "王五");
     const Human d(28, "赵六");

     cout << a << endl;     // cout.operator<<(a) 或 operator<<(cout, a);
     cout << c << endl;     // cout.operator<<(c) 或 operator<<(cout, c);
     cout << Human(30, "刘七") << endl;     // cout.operator<<(Human(30, "刘七")) 或 operator<<(cout, Human(30, "刘七"));
     cout << a  << ' ' << c << endl;

     cin >> a;              // cin.operator>>(a) 或 operator>>(cin, a)
     cout << a << endl;
     return 0;
}
