/* 二进制 I/O */
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
     // 二进制读取
     ifstream ifs("./getline.txt", ios::in);
     if(!ifs) {
          cerr << "ifs 流对象状态错误 - 打开文件失败" << endl;
     }
     
     ofstream ofs("./outgetline_1", ios::out);
     if(!ifs) {
          cerr << "ofs 流对象状态错误 - 打开文件失败" << endl;
     }

     char buf[3];
     while (true) {
          ifs.read(buf, 3);
          if(!ifs){
               // 没读满 3个字节, 在 "getline.txt" 文件中的数据当我们最后一次读取时只会读取两个字节
               // 而上一次读满了 3个字节为 [6][7][8], 而我们最后一次读取时无法完全覆盖这三个字节
               // 出现 [9][\n][8]的不完全覆盖
               int len = ifs.gcount();
               // buf[len] = '\0';
               // cout << buf ;
               ofs.write(buf, len);
               break;
          } else {
               // 读满 3个字节
               // cout << buf ;
               ofs.write(buf, 3);
          }
     }
     ifs.close();
     ofs.close();
     return 0;
}

