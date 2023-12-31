# Day 05

**类的定义和实例化** <p>
***构造函数***
- 函数名必须与类名相同, 且没有返回值类型
- 构造函数调用时间
    - 在定义对象同时自动被调用, 且仅被调用一次
        - 对象定义语句
        - new 操作符
- 构造函数的作用
    - 定义对象的各个成员变量并赋初值, 设置对象的初始状态
    - 在对象定义之初想实现的任何操作

***对象的定义过程***
- 为整个对象分配内存空间
- 以构造实参调用构造函数
    - 定义成员函数
    - 执行构造代码

***类的声明和定义(实现)可以分开*** <p>
可以将类的 **声明(Human.h)、定义(Human.cpp)与使用(main.cpp)** 分别放在不同的文件中
```
// 类的声明
class 类名 {
    返回类型 函数名 (形参表);
};

// 类的定义
返回类型 类名::函数名(形参表){
    函数体;
}
```

**对象的定义与销毁**
- 在栈中定义单个对象
    - `类名 对象;`
    - `类名 对象(实参表);`
- 在栈中定义对象数组
    - `类名 对象数组[元素个数];`
    - `类名 对象数组[元素个数] = {类名(实参表), ...};`
    - `类名 对象数组[] = {类名(实参表), ...};`
- 在堆中定义/销毁单个对象
    - `类名* 对象指针 = new 类名;`
    - `类名* 对象指针 = new 类名();`
    - `类名* 对象指针 = new 类名(实参表);`
    - `delete 对象指针;`
- 在堆中定义/销毁单个对象
    - `类名* 对象数组指针 = new 类名[元素个数];`
    - `类名* 对象数组指针 = new 类名[元素个数] {类名(实参表), ...};`
    - `delete[] 对象数组指针;`

**String 类**
```
class string {
public:
    //                        初始化表
    //                           v
    string(const char* psz = "") : m_psz(new char[strlen(psz)+1]) {
        // 在 this 指针指向的内存空间中定义 m_psz
        // 并赋初值为指向堆内存
        strcpy(m_psz, psz);
    }

    string(const string& that) : m_psz(new char[strlen(that.m_psz)+1]) {
        // 在 this 指向内存空间中定义 m_psz
        // 并赋初值为指向另一块堆内存
        strcpy(m_psz, that.m_psz);
    }

    string& operator=(const string& that){
        delete[] this->m_psz; // 释放旧资源
        this->m_psz = new char[strlen(that.m_psz)+1]; // 分配新资源
        strcpy(this.m_psz, that.m_psz); // 拷贝新内容
    }

    char* c_str(){
        return m_psz;
    }
private:
    char* m_psz;
}
```
在 `clsString.cpp` 文件中共有 5 种定义 string 类对象的方式
- 注意事项
    - 如果在做初始化, 并且 **"="** 两边的类型完全一致, 那么 `= xxx` 和 `(xxx)` 无区别
    - 如果在做赋值, 并且 **"="** 两边的类型完全一致, 那么将触发 `operator=` 函数
    - 无论是初始化还是赋值, 只要 **"="** 两边的类型不一致, 编译器将 **"="** 右边的类型转换为和 **"="** 左边的类型一致

