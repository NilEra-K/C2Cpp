/* 不得不显式的使用 This指针的情况 */
#include <iostream>
#include <cstring>

using namespace std;

class Integer; // 短式声明(简式声明)
void Print(Integer* ix){ }

class Integer{
public:
     void setinfo(int i){
          // i = i;
          this->i = i;   // 必须显式的使用 this 指针
                         // 但是这时一种不好的编程习惯
     }

     void getinfo(){
          cout << "i = " << i << endl;
          Print(this);   // 这里也要显式写出 this
     }

     Integer& increment(){
          i++;           // 这里编译器自动补充 this
          return *this;  // 返回基于 this 指针的自引用
                         // 此处必须明显写 this 的情况
     }

     Integer tryNoAnd(){
          i++;
          return *this;
     }
private:
     int i;
};

// 以上代码模拟 类的设计者 (例如: 类库、被人设计的类、自己的设计的类)
///////////////////////////////////////////////////////////
// 以下代码模拟 类的使用者

int main(void){
     Integer ix;
     ix.setinfo(1000);
     ix.getinfo();
     ix.increment().increment().increment(); // 串连调用
     ix.getinfo();

     ix.tryNoAnd().tryNoAnd().tryNoAnd();    // 不带引用, 使用串连调用无法得到正确的结果
     ix.tryNoAnd();                          // 只能执行第一次 tryNoAnd() 函数, 后面的修改无效
     ix.getinfo();
     return 0;
}
