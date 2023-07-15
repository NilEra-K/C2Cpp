/* C/C++ 动态内存分配 */
#include <iostream>
#include <cstdlib>
using namespace std;


int main(void){
    int* pm = (int*)malloc(4);  // malloc 返回值为 void* 需要强制类型转换为 int*
    cout << "*pm = " << *pm << endl;
    free(pm);
    // free(pm);    // 不能对一块内存释放两次
                    // 释放一块内存后, pm指针只想的堆内存已经被释放, pm就变成野指针
                    // free 野指针会发生段错误
    pm = NULL;      // pm 置空
    free(pm);       // pm 置空后再释放不会发生错误

    int* pi = new int(100);
    cout << "*pi = " << *pi << endl;
    delete(pi);

    int* parr = new int[4] {10, 20, 30, 40}; // 以数组元素 new , 永远返回第一个元素的地址
    // 注意: new 操作并不会给初始值(在不同的系统或者编译器中表现可能不同)
    // 可以使用 int* parr = new int[4](); 加入一对括号来进行初始化, 这样里面的值就全为 0
    for(int i = 0; i < 4; i++){
        cout << parr[i] << ' ';
    }
    cout << endl;
    delete[] pi;

    // 定义二维数组
    // 以数组方式 new, 永远返回第一个元素的地址
    // 无论是几维数组, 本质都是一维数组
    // int[3][4]: 一个一位数组, 有三个元素, 每个元素是一个一维数组
    // 所以第一个元素的地址 —— 一个一维数组的地址
    int (*p)[4] = new int[3][4];
    delete[] p;

    // 申请 4G内存被直接杀死, 抛出异常 Bad Alloc
    // 如果我们不对异常进行捕获, 就会被系统杀死, 如下所示
    // new int[0xfffffffff];
    try {
        new int[0xffffffff];
    } catch (...) {

    }
    return 0;
}

