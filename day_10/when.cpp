/* 何时需要多态? 一个需要多态的场景 */
#include <iostream>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <cstdio>
using namespace std;

// 设计一个 "通用" 的线程类
class Thread {
public:
     void Start() {
          pthread_create(&m_pid, NULL, threadFunc, this);
     }

     // 我们不能使用普通的成员函数来设计线程处理函数
     // 因为 C++ 会给其补充 this 参数, 而线程处理函数要求只有一个 void* 参数
     // 因此使用 static 关键字, 此时 threadFunc 不会补充 this 参数
     static void* threadFunc(void* arg){
          // 创建线程要执行的操作, 不应该由类的设计者提供
          // 而应该由用户提供
          // 作为类的设计者, 我们应该调用用户提供的操作
          // for(;;){
          //      usleep(1000 * 500);
          //      cout << '+' << flush;    // flush 是立刻显示的意思
          // }
          Thread* p = (Thread*) arg;
          p->run();
     }

     virtual void run() = 0; // 纯虚函数, 使得该类变为抽象类
                             // 用户使用时必须构造自己的子类, 且必须定义 run()的实现
private:
     pthread_t m_pid;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者
class MyThread : public Thread {
public:
     MyThread(int sec = 1, char ch = '*') : m_sec(sec), m_ch(ch) { }
     void run(){
          for(;;){
               usleep(1000 * 500 * m_sec);
               cout << m_ch << flush;
          }
     }
private:
     int m_sec;
     char m_ch;
};


int main(void) {
     MyThread t1(1, '*'), t2(2, '-');
     t1.Start();
     t2.Start();
     getchar();
     return 0;
}


