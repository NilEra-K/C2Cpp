/* 非格式化 I/O */
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
     // put
     ofstream ofs("./noformat.txt", ios::out);
     if(!ofs){
          cerr << "ofs 流对象状态错误 - 打开为文件失败" << endl;
     }
     for(char c =' '; c <= '~'; c++){
          ofs.put(c).flush();
     }
     ofs.close();

     ifstream ifs("./noformat.txt", ios::in);
     if(!ifs){
          cerr << "ifs 流对象状态错误 - 打开为文件失败" << endl;
     }
     char c;
     // 单参的 get
     while(true){
          ifs.get(c);
          if(!ifs){
               break;
          } else {
               cout << c;
          }
     }
     cout << endl;

     // 当 ifs 为错误状态时, ifs 需要复位, 并将文件指针设置到文件头
     cout << "单参 get 读取数据后, ifs流对象的状态值为 : " << ifs.rdstate() << endl;
     ifs.clear();
     ifs.seekg(0, ios::beg);

     // 无参的 get
     while(true){
          c = ifs.get();
          if(c == EOF){
               break;
          } else {
               cout << c;
          }
     }
     cout << endl;
     ifs.close();

     // getline
     ifstream ifs_2("./getline.txt", ios::in);
     if(!ifs_2){
          cerr << "ifs_2 流对象状态错误 - 打开为文件失败" << endl;
     }
     // 一旦读取了 num 个字符还未读取界定符, 第 num 个字符设置为 '\0' , 返回( 输入流对象状态为 4 )
     char buf_1[2];
     ifs_2.getline(buf_1, 2, '\n');
     cout << buf_1 << endl;     // buf_1 输出为 [a][\0], 此时输入流对象返回 4
     cout << "ifs_2 流对象的状态为 - " << ifs_2.rdstate() << endl;
     ifs_2.close();

     ifstream ifs_3("./getline.txt", ios::in);
     if(!ifs_3){
          cerr << "ifs_3 流对象状态错误 - 打开为文件失败" << endl;
     }
     char buf_2[256];
     while(true){
          ifs_3.getline(buf_2, 256, '\n');
          if(!ifs_3){
               break;
          }
          cout << "ifs_3 流对象的状态为 - " << ifs_3.rdstate() << endl;
          cout << buf_2 << endl;     // buf_2 输出为 [a][a], 此时流对象对象返回 0
     }

     return 0;
}

