/* 二进制 I/O */
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
     // 二进制读取
     ifstream ifs("./getline.txt", ios::ate);
     if(!ifs) {
          cerr << "ifs 流对象状态错误 - 打开文件失败" << endl;
     }
     
     ofstream ofs("./outgetline_2", ios::out);
     if(!ifs) {
          cerr << "ofs 流对象状态错误 - 打开文件失败" << endl;
     }

     // 读取文件, 打开文件时将文件指针设置到结尾处
     // 获取文件读指针的位置, 该位置位于文件尾, 即为文件的大小
     int size = ifs.tellg();
     char buf[size];
     ifs.seekg(0, ios::beg);
     ifs.read(buf, size);
     ofs.write(buf, size);

     ifs.close();
     ofs.close();
     return 0;
}

