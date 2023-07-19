#ifndef _HUMAN_H_
#define _HUMAN_H_

class Human{
public:
     Human(int age = 0, const char* name = "None");
     void getinfo();
private:
     int m_age;          // 声明
     char m_name[256];   // 声明
};
#endif  // _HUMAN_H_