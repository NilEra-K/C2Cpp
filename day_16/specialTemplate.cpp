/* 类模板拓展 */
// 特化
#include <iostream>
#include <cstring>
using namespace std;

template  <typename T>
class CMath{
public:
    CMath(T const& t1, T const& t2) : m_t1(t1), m_t2(t2) { }
    T add(){
        return m_t1 + m_t2;
    }
private:
    T m_t1;
    T m_t2;
};

// 全类特化, 当类型复杂时非常冗余, 需要写大量的代码
/* ===============================================================================
template <>
class CMath<char* const> {
    CMath<char* const>(char* const& t1, char* const& t2) : m_t1(t1), m_t2(t2) { }
    char* const add(){
        return strcat(m_t1, m_t2);
    }
private:
    char* const m_t1;
    char* const m_t2;
};
=============================================================================== */

// 成员特化
template <>
char* const CMath<char* const>::add(){
    return strcat(m_t1, m_t2);
}

// 局部特化演示
template <typename T, typename D>
class A {
public:
    static void foo(void) {
        cout << "0: A<T, D>::foo()" << endl;
    }
private:
};

// 特化形式 1
template <typename T>
class A<T, short> {
public:
    static void foo(void) {
        cout << "1: A<T, short>::foo()" << endl;
    }
private:
};

// 特化形式 2
template <typename T>
class A<T, T> {
public:
    static void foo(void) {
        cout << "2: A<T, T>::foo()" << endl;
    }
private:
};

// 类型形参的缺省值
template <typename T, typename D=short>
class B {
public:
    void print() {
        cout << "m_t : " << typeid(m_t).name() << ' '
             << "m_d : " << typeid(m_d).name() << endl;
    }
private:
    T m_t;
    D m_d;
};

// 数值类型的模板参数
template <typename T, size_t S=15>
class Array {
public:
    T& operator[](size_t i){
        return m_arr[i];
    }

    size_t size() {
        return S;
    }
private:
    T m_arr[S];
};


int main(void){
    int ix = 10, iy = 20;
    CMath <int> cm_1(ix, iy);
    cout << cm_1.add() << endl;

    double dx = 1.23, dy = 45.6;
    CMath <double> cm_2(dx, dy);
    cout << cm_2.add() << endl;

    string sx = "Hello", sy = "World";
    CMath <string> cm_3(sx, sy);
    cout << cm_3.add() << endl;

    char cx[256] = "Hello", cy[256] = "World";
    CMath<char* const> cm_4(cx, cy);    // 数组名式具有常属性的指针
    cout << cm_4.add() << endl;

    // 局部特化演示
    // 无形式时: 0
    // 只有形式一: 1
    // 只有形式二: 2
    // 包括形式一 和 形式二: ERROR 出现歧义
    // A<short, short>::foo();

    // 类型形参的缺省值
    B<int, double> b_1;
    b_1.print();
    B<int> b_2;     // 缺省 typename D
    b_2.print();

    // 数值型的模板参数
    Array <int, 20> arr;
    for(int i = 0; i < arr.size(); i++){
        arr[i] = i + 1;
    }
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}

