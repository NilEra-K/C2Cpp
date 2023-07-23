/* 简易栈容器 */
#include <iostream>
#include <cstring>
using namespace std;

class Stack {
public:
     Stack() : m_size(0) { }
     void push (int data) { m_a[m_size++] = data;}
     int pop() { return m_a[--m_size]; }
     int size() { return m_size; }

     const int& operator[](size_t index) const { // 常函数
          return m_a[index];
     }

     int& operator[](size_t index) { // 非常函数
          return this->m_a[index];
     }
private:
     int m_a[20];   // 保存数据
     int m_size;    // 保存数据个数
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Stack s;            // 空栈容器
     const Stack cs = s; // 常容器
     for(int i = 0; i < 20; i++){
          s.push(1000 + i);
     }
     cout << "压栈后 s 容器中数据的个数 = " << s.size() << endl;

     s[5] = 8888;
     for(int i = 0; i < 20; i++){
          cout << s[i] << ' ' ;
     }
     cout << endl;
     cout << "读数据后 s 容器中数据的个数 = " << s.size() << endl;

     for(int i = 0; i < 20; i++){
          cout << s.pop() << ' ' ;
     }
     cout << endl;
     cout << "出栈后 s 容器中数据的个数 = " << s.size() << endl;
     // cs[5] = 8888;
     return 0;
}
