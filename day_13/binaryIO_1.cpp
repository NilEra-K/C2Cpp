/* 二进制 I/O */
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
     ifstream ifs("./getline.txt", ios::in);
     if(!ifs) {
          cerr << "ifs 流对象状态错误 - 打开文件失败" << endl;
     }
     char buf[3];
     while (true) {
          ifs.read(buf, 3);
          if(!ifs){
               // 没读满 3个字节
               cout << buf ;
               break;
          } else {
               // 读满 3个字节
               cout << buf ;
          }
     }
     return 0;
}

