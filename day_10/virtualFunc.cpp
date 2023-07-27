/* 有虚函数的程序——虚的世界 */
#include <iostream>
#include <cstring>
using namespace std;

// 图形类
class Shape {
public:
     // 基类 虚函数
     virtual void draw(){ cout << "Shape::draw()" << endl; }
     int m_x;
     int m_y;
};

// 矩形类
class Rect : public Shape {
public:
     // 虚函数(编译器将补充 virtual)
     void draw(){ cout << "Rect::draw()" << endl; }
     int m_rx;
     int m_ry;
};

// 圆形类
class Circle : public Shape {
public:
     // 虚函数(编译器将补充 virtual)
     void draw(){ cout << "Circle::draw()" << endl; }
     int m_radius;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     // 哪个类的对象优先调用哪个类的虚成员函数
     cout << ">>> 利用对象调用虚的成员函数" << endl;
     Shape s;
     s.draw();
     Rect r;
     r.draw();
     Circle c;
     c.draw();

     // 调用哪个类的成员函数是由指针或引用的实际目标对象的类型决定的
     cout << ">>> 利用对象调用虚的成员函数" << endl;
     Shape* ps = &s;
     ps->draw();              // 非多态
     ps = &r;  ps->draw();    // 多态
     ps = &c;  ps->draw();    // 多态
     // ps->foo();
     return 0;
}