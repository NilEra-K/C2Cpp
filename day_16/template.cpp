/* 函数模板 */
#include <iostream>
using namespace std;

// 普通函数
void Max(int x, int y){
    cout << "1: Max(int, int)" << endl;
}

// 模板函数
template <typename DataType>
DataType Max(DataType x, DataType y){
    return x > y ? x : y;
}

template <class T>
T Min(T x, T y){
    return x < y ? x : y;
}

template <typename DataType>
void foo(){
    // abc = 10;    // [ERROR] 所有表识符必须声明
    // A a;
    // a.abc();     // [ERROR] 已知类型的调用必须合理
    // a.m_i;

    DataType t;
    t.abc();        // [OK] 未知类型的调用假定合理
}

template <typename D, typename T>
void Func(int x){
    D d = 10;
    T t = 12.5;
    cout << d << ' ' << t << endl;
}

class Integer {
friend ostream& operator<< (ostream& os, const Integer& that);
public:
    Integer(int i = 0) : m_i(i) {}
    bool operator< (Integer& that){
        return this->m_i < that.m_i ? true : false;
    }

    bool operator> (Integer& that){
        return this->m_i > that.m_i ? true : false;
    }
private:
    int m_i;
};

ostream& operator<< (ostream& os, const Integer& that) {
    os << that.m_i;
    return os;
}

int main(void){
    int ix = 10, iy = 20;
    double dx = 10.9, dy = 20.8;
    Integer cix(ix), ciy(iy);

    Max(ix, iy);
    Max<>(ix, iy);
    cout << Max <int> (ix, iy) << endl;
    cout << Min <double> (dx, dy) << endl;
    cout << Max <Integer> (cix, ciy) << endl;
    cout << Min <Integer> (cix, ciy) << endl;

    // foo<string>();  // [ERROR] 二次编译出错

    Func<int, double> (10);
    return 0;
}


