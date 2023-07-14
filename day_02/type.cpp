/* C++ 的复合类型和 C 的复合类型之间的差别 */
#include <iostream>
#include <cstring>

using namespace std;

void TestStruct(void){
    struct Student {
        int m_age;          // 成员变量: 年龄
        char m_name[256];   // 成员变量: 姓名
        void getInfo(void){ // 成员函数: C语言结构体中无法定义函数
                            // C++ 结构体中可以定义函数
            cout << "姓名: " << m_name << endl
                 << "年龄: " << m_age << endl;
        }
    };
    struct Student s;   // C 语言必须这样写
    Student stu;        // C++ 可以省略前面的 struct
    s.m_age = 22;
    strcpy(s.m_name, "张三");
    cout << "姓名: " << s.m_name << endl
         << "年龄: " << s.m_age << endl;
    s.getInfo();
}

void TestUnion(void){
    union A{ // C++ 联合体完全兼容 C, 所有变量共用一块内存空间
             // 也就是说给 i赋值也就是给 c赋值
        int i;
        char c[4];
    };
    /*union*/ A a;  // C++ 可以省略前面的 union
    union { // 匿名联合体, 主要是为了体现联合体中所有成员的内存排布方式
            // 共用同一块内存年空间
        int ua;
        char uc[4];
    }; // 它无法被定义, 也不想被定义
    ua = 0x12345678;    // 匿名联合体中的变量
    cout << hex         // 要求以 16进制输出
         << (int)uc[0] << ' ' 
         << (int)uc[1] << ' '
         << (int)uc[2] << ' '
         << (int)uc[3] << endl;
}

void TestEnum(void){
    enum Color {RED, GREEN, BLUE};
    // C++ 对类型检查更加严格
    // Color c = 0 [Error] 无法从 int 类型转为 Color 类型
    /*enum*/ Color c = RED;
    cout << "c = " << c << endl;
}

void TestBool(void){
    bool a = true;
    bool b = false;
    bool boolstr_1 = "hello";
    bool boolstr_2 = "";
    bool boolstr_3 = "\n";
    bool boolstr_4 = NULL;
    cout << a << ' ' << b << endl;
    cout << boolstr_1 << ' '
         << boolstr_2 << ' '
         << boolstr_3 << ' '
         << boolstr_4 << endl;
}

int main(void){
    // TestStruct();
    // TestUnion();
    // TestEnum();
    TestBool();
    return 0;
}