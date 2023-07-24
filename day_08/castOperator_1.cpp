/* 类型转换操作符函数 和 类型转换构造函数 */
#include <iostream>
#include <cstring>
using namespace std;

class Integer {
public:
     Integer(int i) : m_i(i) {
          cout << "Integer 类的类型转换构造函数调用" << endl;
     }

     operator int(void) const {
          // 其实有返回值类型, 只是不需要我们写出来
          cout << "Integer 类的类型转换操作符函数被调用" << endl;
          return this->m_i;
     }
private:
     int m_i;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     int n = 666;

     // int -> Intager (基本类型->类类型)
     Integer ix = n;     // 定义匿名 Integer类对象, 利用匿名 Integer类对象.Integer(n); -> 类型转换构造函数
                         // 不存在 Integer ix = n.operator Intager

     // Intager -> int (类类型->基本类型)
     int m = ix;         // 不存在定义匿名 int类对象, 利用匿名 int类对象.int(ix);
                         // 因为不存在上面的方法, 所以编译器会尝试下面的方法
                         // int m = ix.operator int() -> 类型转换操作符函数
     cout << m << endl;
     return 0;
}
