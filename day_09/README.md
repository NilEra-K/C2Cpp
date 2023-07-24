# Day 09

**继承**
- 共性和个性: 类与类之间都存在共性和个性, 我们在设计类的时候应抽取共性, 保留个性
- 基类和子类: 抽取共性的类可以称之为基类(父类), 保留个性的类可以称之为子类
- 继承和派生 <p>
子类**继承**基类(父类), 基类**派生**子类
    ```
    class Human {
    public: 
        void eat(const string& food) {...}
        void sleep(int hours) {...}
        string m_name;
        int m_age;
    };

    class Student : public Human {
    public:
        void learn (const string& course){...}
        int m_no;
    };

    class Teacher : public Human {
    public:
        void teach (const string& course){...}
        float m_salary;
    };
    ```
- 继承的语法
    ```
    class 子类 : 继承方式1 基类1, 继承方式2, 基类2, ...{
        ...
    };
    ```
- 继承方式
    - 共有继承: public
    - 保护继承: protected
    - 私有继承: private
- 继承所要达到的目的
    - 子类对象包含基类子对象
    - 子类内部可以直接访问基类的所有非私有成员
- 继承的本质
    - 基类的非私有成员在子类中仅仅为可见, 而非拥有
- **[注意]** 对于继承切忌不要理解为基类的成员变为子类的成员, 继承不会改变类成员的作用域, 基类的成员永远都是基类的成员, 并不会因为继承而变成子类的成员

