/* 类模板 */
#include <iostream>
#include <iomanip>
using namespace std;

class Integer {
friend ostream& operator<<(ostream& os, const Integer& that);
public:
    Integer(int i) : m_i(i) {}
    Integer operator+(Integer const& that) const {
        return this->m_i + that.m_i;
        // return Integer(this->m_i + that.m_i);    // 等效
    }
private:
    int m_i;
};

template <typename DataType>
class CMath {
public:
    CMath(DataType const& t1, DataType const& t2) : m_t1(t1), m_t2(t2){ }
    DataType add();
    void print(void){
        cout << "&m_s1 : " << &m_s1 << " &m_s2 : " << &m_s2 << endl;
    }
private:
    DataType m_t1;
    DataType m_t2;
    static DataType m_s1;
    static int m_s2;
};

// 模板类静态成员类外初始化方式
template <typename DataType>
DataType CMath<DataType>::m_s1 = 0;

template <typename DataType>
int CMath<DataType>::m_s2 = 0;

template <typename DataType>
DataType CMath<DataType>::add(){
    return m_t1 + m_t2;
}

ostream& operator<<(ostream& os, const Integer& that){
    os << that.m_i;
    return os;
}

// 递归实例化
template <typename T>
class Array{
public:
    T& operator[](size_t i){
        return m_arr[i];
    }
private:
    T m_arr[10];
};


int main(void){
    // 类模板的使用
    int i1 = 10, i2 = 20;
    CMath <int> cm_1(i1, i2);
    CMath <int> cm_i(i1, i2);
    cout << cm_1.add() << endl;

    double d1 = 1.23, d2 = 45.6;
    CMath <double> cm_2(d1, d2);
    cout << cm_2.add() << endl;

    Integer it1(10), it2(20);
    CMath <Integer> cm_3(it1, it2), cm_4(it1, it2);
    cout << typeid(cm_3.add()).name() << endl;
    cout << cm_3.add() << endl;

    cout << "CMath <int>" << endl;
    cm_1.print();
    cm_i.print();
    cout << endl;

    cout << "CMath <double>" << endl;
    cm_2.print();
    cout << endl;

    cout << "CMath <Integer>" << endl;
    cm_3.print();
    cm_4.print();

    // 普通实例化
    Array<int> arr;
    for(int i = 0; i < 10; i++){
        arr[i] = i;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;

    // 递归实例化
    Array <Array<int> > m;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            m[i][j] = i*10 + j;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << setw(2) << setfill('0') << m[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}


