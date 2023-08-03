/* 模板技巧 */
#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Array {
public:
    T& operator[] (size_t i) {
        return m_arr[i];
    }
private:
    T m_arr[10];
};

template <class D>
class Sum {
public:
    Sum(Array<D>& s) : m_s(s) { };
    D add(){
        D d = 0;
        for(int i = 0; i < 10; i++){
            d += m_s[i];
        }
        return d;
    }
public:
    Array <D> m_s;  // 模板型成员变量
};

// 模板型模板参数
template <typename D, template <typename P> typename T>
class temSum {
public:
    temSum(T<D>& s) : m_s(s) { };
    D add(){
        D d = 0;
        for(int i = 0; i < 10; i++){
            d += m_s[i];
        }
        return d;
    }
public:
    T<D> m_s;
};

// 类模板的成员函数模板
template <class T>
class A {
public:
    template<class D>
    void foo(); // 成员函数模板, 可以类内实现, 也可以类外实现
};

// 类外实现
template<class T>
template<class D>
void A<T>::foo() {
    cout << "A<T>::foo<D>" << endl;
}

// 模板型成员类型
template <class X>
class B {
public:
    void foo() {
        cout << "B<X>::foo()" << endl;
    }

    template <class Y>
    class C { 
    public:
        template <class T>
        void func(){
            cout << "B<X>::C<Y>::func<T>" << endl;
        }

        template <class Z>
        class D;
    };    // 模板型的成员类型
};

template <class X>
template <class Y>
template <class Z>
class B<X>::C<Y>::D {
public:
    void bar() {
        cout << "B<X>::C<Y>::D<Z>::bar()" << endl;
    }
};

int main(void){
    // 模板型成员变量演示
    Array<int> arr;
    for(int i = 0; i < 10; i++){
        arr[i] = i + 1;
    }
    Sum<int> s(arr);
    cout << s.add() << endl;

    // 模板型成员函数演示
    A<int> a;
    a.foo<double>();

    // 模板型成员类型
    B<int> b;
    b.foo();
    B<int>::C<double>::D<short> d;
    d.bar();
    
    // 模板型模板参数
    temSum<int, Array> tS(arr);
    cout << tS.add() << endl;
    return 0;
}

