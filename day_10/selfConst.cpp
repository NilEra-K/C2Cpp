/* 没有虚函数的程序——无虚的世界 */
#include <iostream>
#include <cstring>
using namespace std;

// 图形类
class Shape {
public:
     void draw(){ cout << "Shape::draw()" << endl; }
     int m_x;
     int m_y;
};

// 矩形类
class Rect : public Shape {
public:
     void draw(){ cout << "Rect::draw()" << endl; }
     int m_rx;
     int m_ry;
};

// 圆形类
class Circle : public Shape {
public:
     void foo() { cout << "Circle::foo()" << endl; }
     void draw(){ cout << "Circle::draw()" << endl; }
     int m_radius;
};
// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     // 哪个类的对象优先调用哪个类的普通成员函数
     cout << ">>> 利用对象调用非虚的成员函数" << endl;
     Shape s;
     s.draw();
     Rect r;
     r.draw();
     Circle c;
     c.draw();

     // 通过基类类型指针调用普通成员函数只能调用基类的成员函数
     cout << ">>> 利用指针调用非虚的成员函数" << endl;
     Shape* ps = &s;
     ps->draw();
     ps = &r;  ps->draw();
     ps = &c;  ps->draw();
     // ps->foo();
     return 0;
}