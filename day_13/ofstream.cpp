/* 写文件操作 */
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
     ofstream ofs_1("./file", ios::out);

     // 判断打开文件是否成功
     if(!ofs_1){ // ofs_1.operator bool()
          cerr << "流对象状态错误 - 打开文件失败" << endl;
     }

     ofs_1 << 1234 << ' ' << 56.78 << ' ' << "Hello" << '\n';
     if(!ofs_1){
          cerr << "流对象状态错误 - 写文件失败" << endl;
     }
     ofs_1.close();

     ofstream ofs_2("./file", ios::app);
     if(!ofs_2){
          cerr << "流对象状态错误 - 打开文件失败" << endl;
     }

     ofs_2 << "World" << endl;
     if(!ofs_2){
          cerr << "流对象状态错误 - 写文件失败" << endl;
     }
     ofs_2.close();
     return 0;
}

