/* 类模板拓展 */
// 特化
#include <iostream>
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

// 全类特化

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
    return 0;
}

