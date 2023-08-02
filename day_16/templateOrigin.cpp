/* 模板起源 */
#include <iostream>
#define Max(x, y)   (x > y ? x : y)

// 利用宏构建通用函数框架
// `##` 表示拼接
// `\`  表示换行
#define Min(T)  T min_##T(T x, T y) {\
    return x < y ? x : y;\
}

// 宏的实例化 下面这里会用 int 替换 T
// int min_##int -> `##` 表示拼接 -> int min_int
Min(int)
#define Min(T) min_##T

using namespace std;

int max_int(int x, int y) {
    return x > y ? x : y;
}

double max_double(double x, double y) {
    return x > y ? x : y;
}

string max_string(string x, string y) {
    return x > y ? x : y;
}

int main(void){
    int ix = 10, iy = 20;
    cout << max_int(ix, iy) << endl;

    double dx = 10.9, dy = 20.8;
    cout << max_double(dx, dy) << endl;

    string sx = "Hello", sy = "World";
    cout << max_string(sx, sy) << endl;

    // 使用宏摆脱数据类型限制
    cout << Max(ix, iy) << endl;    // Max(ix, iy) -> (x > y ? x > y)
    cout << Max(dx, dy) << endl;
    cout << Max(sx, sy) << endl;

    // 使用宏不会进行类型检查
    char cx[256] = "World";
    char cy[256] = "Hello";
    cout << Max(cx, cy) << endl;    // 结果为 "Hello", 实际上比较的是地址
                                    // "Hello" 后定义, 地址较大

    // 利用宏构建通用函数框架
    cout << min_int(ix, iy) << endl;
    cout << Min(int)(ix, iy) << endl;
    return 0;
}

