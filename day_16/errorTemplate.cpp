/* 模板典型错误 */
#include <iostream>
using namespace std;

// 嵌套依赖
class A {
public:
    class B {
    public:
        void foo(void) {
            cout << "A::B::foo()" << endl;
        }
    };
};

template <typename T>
void Func_1() {
    // T::B b;          // 问题: 嵌套依赖
    typename T::B b;    // 解决方案: 在类型形参的前面增加一个 typename 标识符, 意在告诉编译器其后是一个类模板的嵌套使用
    b.foo();
}

// 依赖模板参数访问成员
class C {
public:
    template <typename T>
    void foo() {
        cout << "C::foo<T>()" << endl;
    }
};

template <typename D>
void Func_2() {
    D d;
    // d.foo<int>();// 未知类型的参数假定合理, 但是不能出现尖括号
                    // 出现尖括号则意味着其一定是一个函数模板
    d.template foo<int>();
}

// 子类模板访问基类模板
// 只在子类模板和全局域中搜索使用的标识符号, 不会到基类模板中搜索
template <typename T>
class Base {
public:
    int m_i;
    void foo() {
        cout << "Base<T>::foo() -> m_i:" << m_i << endl;
    }
};

// 全局域中没有
template <typename T, typename D>
class Derived : public Base<T> {
public:
    void bar(){
        // m_i = 100;   // 子类模板无法调用基类模板中的成员, 编译出现未声明的错误
        // foo();
        Base<T>::m_i = 100;
        Base<T>::foo();

        this->m_i = 200;
        this->foo();
    }
    // 子类模板中没有
private:
};

// 零值初始化
class Integer {
friend ostream& operator<<(ostream& os, const Integer& that);
public:
    Integer() : m_i(0) {}
private:
    int m_i;
};

template <typename T>
void Func_3(){
    // T t;
    T t = T();  // 显式缺省构造, 取零值
    cout << "t = " << t << endl;
}

ostream& operator<<(ostream& os, const Integer& that) {
    os << that.m_i;
    return os;
}

// 类模板中的成员虚函数
template <typename T>
class VBase {
public:
    virtual void foo() {
        cout << "VBase<T>::foo()" << endl;
    }

    // template <typename M>
    // virtual void Func(){ // [ERROR] templates may not be ‘virtual’
    //     cout << "VBase<T>::Func()" << endl;
    // }
};

template <typename T, typename D>
class VDerived : public VBase<T> {
public:
    void foo(){
        cout << "Derived<T, D>::foo()" << endl;
    }
private:
};



int main(void){
    Func_1<A>();

    Derived<int, double> d;
    d.bar();

    Func_3<int>();
    Func_3<double>();
    Func_3<Integer>();

    VDerived<int, double> vd;
    VBase<int>* pvb = &vd;
    pvb->foo();
    return 0;
}

