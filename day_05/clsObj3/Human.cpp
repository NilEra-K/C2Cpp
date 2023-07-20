#include <iostream>
#include <cstring>
#include "Human.h"

using namespace std;

Human::Human(int age, const char* name){
    cout << "构造函数被调用" << endl;
    m_age = age;
    strcpy(m_name, name);
}

void Human::getinfo(){   // 定义
    cout << "姓名 : " << m_name << " 年龄 : " << m_age << endl;
}
