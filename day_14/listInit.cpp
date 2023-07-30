/* 列表初始化 */
#include <iostream>
using namespace std;

class Date {
friend ostream& operator<<(ostream& os, const Date& right);
public:
     Date(int year = 0, int month = 0, int day = 0) : m_year(year), m_month(month), m_day(day){ }
     ~Date() { }
private:
     int m_year;
     int m_month;
     int m_day;
};

class Student {
friend ostream& operator<<(ostream& os, const Student& right);
public:
     Student(string name = "None", int age = 0, Date date = {0, 0, 0}) : m_name(name), m_age(age), m_date(date){

     }
private:
     int m_age;
     string m_name;
     Date m_date;
};

ostream& operator<<(ostream& os, const Date& right) {
     os << right.m_year << ' '
        << right.m_month << ' ' 
        << right.m_day;
     return os;
}

ostream& operator<<(ostream& os, const Student& right) {
     os << right.m_name << ' '
        << right.m_age << ' ' 
        << right.m_date;
     return os;
}



int main(void) {
     int a {123};
     cout << "a = " << a << endl;

     int b[] {123, 456, 789};
     // cout << sizeof(b) << endl; // 12
     for(int i = 0; i < sizeof(b)/sizeof(b[0]); i++){
          cout << b[i] << ' ';
     }
     cout << endl;

     Student stu[] = {
          {"张三", 20, {2003, 10, 8}},
          {"李四", 21, {2002, 9, 18}},
          {"王五", 22, {2001, 8, 28}},
          {"赵六", 23, {2000, 7, 18}},
          {}
     };

     for(int i = 0; i < sizeof(stu)/sizeof(stu[0]); i++){
          cout << stu[i] << endl;
     }

     Student stu_2 {"刘七", 24, {}};
     cout << stu_2 << endl;


     return 0;
}

