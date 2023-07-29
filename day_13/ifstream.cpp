/* 读文件操作 */
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
     ifstream ifs_1("./file", ios::in);
     if(!ifs_1) {
          cerr << "ifs_1 流对象状态错误 - 打开文件失败" << endl;
     }
     int i;
     double d;
     string s;
     ifs_1 >> i >> d >> s;    // 读取文件数据到内存
     if(!ifs_1) {
          cerr << "ifs_1 流对象状态错误 - 读取数据失败" << endl;
     }
     cout << i << ' ' << d << ' ' << s << endl;
     ifs_1.close();

     ifstream ifs_2("./file", ios::ate);
     if(!ifs_2) {
          cerr << "ifs_1 流对象状态错误 - 打开文件失败" << endl;
     }
     int i2;
     double d2;
     string s2;
     // ifs_2.seekg(0, ios::beg);     // 设置定位为: 相对文件头偏移 0字节, 即文件头
     ifs_2 >> i2 >> d2 >> s2;
     if(!ifs_2) {
          cerr << "ifs_2 流对象状态错误 - 读取数据失败" << endl;
          cout << "ifs_2 是 0状态吗? - " << ifs_2.good() << endl
               << "ifs_2 是 1状态吗? - " << ifs_2.bad() << endl
               << "ifs_2 是 2状态吗? - " << ifs_2.eof() << endl
               << "ifs_2 是 4状态吗? - " << ifs_2.fail() << endl;
          cout << "ifs_2 是 具体的状态值 - " << ifs_2.rdstate() << endl;
     }
     cout << i2 << ' ' << d2 << ' ' << s2 << endl;
     ifs_2.close();
     return 0;
}

