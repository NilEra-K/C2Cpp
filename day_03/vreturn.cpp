/* 引用作为函数的返回值 */
#include <iostream>
using namespace std;

int g_value = 0;

// 平时写的比较普通的函数
int normal(void){
     return g_value;
}

int& foo(void){
     return g_value; // 返回值是谁, 就是谁的别名
}

int& bar(void){
     static int s_value = 0; // 静态局部变量, 静态局部变量的生命周期是进程级的, 但是只是函数可见的
                             // 这句代码在程序启动时就执行, 而且只执行一次, 所以其生命周期是进程级的
                             // 不是每次调用 bar()函数都执行
     cout << "s_value = " << s_value << endl;
     return s_value;
}

int& hum(void){
     int* pn = new int;
     return *pn;
}

int& func(int& x){
     return x;      // 返回引用型参数本身
}

int& No(){
     int m = 8888;
     // return &m;  // [Warning] 这是错误的
     return m;
}

const int& cfunc(void){
     return g_value;
}

int main(void){
     normal();      // 调用该函数会在此处创建一块无名内存, 再进行跳转等操作
     foo();         // 但是返回类型为引用类型的函数不会创建无名内存
                    // 执行完跳转操作后, 函数名就是一个别名
                    // 返回值是谁, 就是谁的别名
                    // 也就是说, 此处 foo()是 g_value的别名
     foo() = 100;   // 既然 foo() 为 g_value的别名, 那么该语句是非常合理的
     cout << "g_value = " << g_value << endl; // [OUTPUT] g_value = 100

     cout << "================" << endl;
     bar() = 200;   // 这里修改的是静态局部变量 s_value的值为 200
     bar();         // 第一次打印为 0, 函数执行结束后, bar() 就是 s_value的别名, 上面的代码修改了其值为 200
                    // 再次调用, s_value输出值为 200

     hum() = 300;

     cout << "================" << endl;
     int a_value = 0;
     cout << "a_value = " << a_value << endl;
     func(a_value) = 400; // 这里 a_value初始值为 0, 执行 func(int& x)函数, 传入 a_value
                          // 这个是引用型函数, 返回值为 x, x为 a_value的别名, 也就是说 func()执行后是 a_value的别名
                          // 因此执行该语句会修改局部变量 a_value
     cout << "a_value = " << a_value << endl;

     cout << "================" << endl;
     // cfunc() = 200;    // 无法修改, 因为 cfunc()是一个常引用型返回值
     return 0;
}
