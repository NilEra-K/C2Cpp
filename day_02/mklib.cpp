/* 制作库文件的代码 */
// g++ -c mklib.cpp -> mklib.o
// 这里可以直接拿 .o 文件做库
// extern "C" int sum(int a, int b){ return a + b; }
// extern "C" int sub(int a, int b){ return a - b; }

// 也可以用这种写法
extern "C" {
    int sum(int a, int b){ return a + b; }
    int sub(int a, int b){ return a - b; }
}
