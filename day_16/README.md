# Day 16

**模板起源**
- **C++ 是静态类型语言**
    - C++ 有很多数据类型(基本类型、类类型), 在效率和安全性方面是无可比拟的
    - 但是这种语言很大程度上会给程序员编写通用代码带来瓶颈
    - 是程序员不得不为每一种数据类型编写完全相同或近乎完全相同的代码实现, 虽然其在抽象层面是一致的
- **使用宏可以摆脱数据类型的限制**
    - 宏是在预处理阶段针对代码的纯文本替换
    - 宏本身没有函数的语义(不会对类型进行检查)
    - 因此借助参数宏虽然可以摆脱类型的约束和限制, 但是也同时丧失了对数据类型的检查
- **利用宏构建通用函数框架**
    - 通过实例化宏, 让预处理将这个宏代换为针对不同数据类型的真正函数
    - 将宏的通用性和函数的类型安全性完美结合起来

**函数模板**
- **函数模板的定义**
    - 函数模板的定义形式
        ```
        template <{class | typename} 类型型参 1, {class | typename} 类型型参 2, ...>
        返回值类型 函数模板名(调用形参 1, 调用形参 2, ...) {
            函数体;
        }
        ```
        例如——
        ```
        template <typename DataType>
        DataType Max(DataType x, DataType y){
            return x > y ? x : y;
        }
        ```
        或者——
        ```
        template <class T>
        T Max(T x, T y){
            return x > y ? x : y;
        }
        ```
    - 可以使用任何表示符作为类型形参的名称, 但是使用 "T" 已经成为一种惯例
- **函数模板的分析**
    - 编译器**并不是**把函数模板编译成一个可以处理任何数据类型的单一实体
    - 编译器在实例化函数模板时根据类型实参从函数模板中产生一个真正的函数实体
    - 函数模板**并不是**一个函数实体, 通过实例化才能产生真正的函数实体
    - 函数模板可以看成是编译器生成函数实体的一个依据而已
    - 这种用具体数据类型替换函数模板类型形参的过程叫做实例化, 这个过程将产生一个函数模板的实例(函数实体)
    - 只要使用函数模板, 就会自动引发编译器的实例化过程, 因此程序员不需要额外地请求对函数模板的实例化
- **实例化函数模板的条件**
    - 原则上可以使用任何类型来实例化函数模板, 不管其为基本类型还是类类型
    - 但前提是这个类型**必须支持函数模板所要执行的操作**
        - 例如: 上述 `T Max(T x, T y)` 中的操作, 用到了 `x > y` 语句, 那么如果是自定义类类型, 就必须重载 `operator>` 操作符函数
- **函数模板拓展**
    - ***二次编译***
        - 编译器对函数模板都会进行二次编译
        - 第一次编译发生在实例化函数模板之前(产生真正函数实体之前), 只检查函数模板本身内部代码, 查看基本语法是否正确
            1. 函数模板内部出现的所有标识符是否均有声明
            2. 对于已知类型的调用要查看调用是否有效
            3. 对于未知类型调用认为都合理
        - 第二次编译发生在实例化函数模板之后(产生真正函数实体之后))结合所使用的类型实参, 再次检查模板代码, 查看所有调用是否真的均有效
    - ***隐式推断类型实参***
        - 如果函数模板的调用形参和类型形参相关 <p>
            **例如 :** `template <class T> T Max(T x,T y){ ... }`
        - 那么在实例化函数模板时即使不显式指明函数模板的类型实参，编译器也有能力根据调用实参的类型隐式推断出正确的类型实参的类型 <p>
            **例如 :** `Max(123,456);` -> `Max<int>(123,456):`
        - 获得和调用普通函数一致的语法表现形式
        - 三种情况不能做隐式推断
            1. 调用参数和类型参数不完全相关
                ```
                template <class T, class D>
                T Max(T x, T y) { ... }
                ```
            2. 隐式推断不支持隐式类型转换
                ```
                template <class T>
                T Max(T x, T y) { ... }

                Max(123, 45.6); // CAN'T
                ```
            3. 返回值类型不支持隐式推断
    - ***函数模板重载***
        - 普通函数和可实例化出该函数的函数模板构成重载关系在数据类型匹配度相同情况下**编译器优先选择普通函数**
        - 除非函数模板可以产生具有更好的数据类型匹配度的实例
        - 函数模板的实例化不支持隐式类型转换, 但普通函数支持在传递参数时如果需要编译器做隐式类型转换, 则编译器选择普通函数
        - 可以在实例化时用 `<>` 强行通知编译器选择函数模板

**类模板** 
- **类模板的声明**
    ```
    template <class 类型形参 1, class 类型形参 2, ...>
    class 类模板名 {

    };
    ```
    例如——
    ```
    template <class A, class B>
    class CMath {
    public:
        A m_a;
        B func(void){
            ...;
        }
    };
    ```
    类模板外实现成员函数
    ```
    template <class 类型形参 1, class 类型形参 2, ...>
    返回值类型 类模板名<class 类型形参 1, class 类型形参 2, ...>::函数名(调用形参 1, ...) {
        ...;
    }
    ```
    例如——
    ```
    template <class A, class B>
    B CMath<A, B>::func(void){
        ...;
    }
    ```
- **类模板的使用**
    - 使用类模板必须对类模板进行实例化(产生真正的类) <p>
        类模板本身并不代表一个确定的类型(即不能用于定义对象), 只有通过类型实参实例化成真正的类后才具备类的语义(即可以定义对象) <p>
        例如: `CMath<int,double> math;`
    - 类模板被实例化时类模板中的成员函数并没有实例化, 成员函数只有在被调用时才会被实例化(即产生真正成员函数) <p>
        注意: 成员虚函数除外
    - 某些类型虽然并没有提供类模板所需要的全部功能但照样可以实例化类模板, 只要不调用那那些未提供功能的成员函数即可
- **类模板的静态成员**
    - 类模板中的静态成员即不是每个对象拥有一份, 也不是类模板拥有一份, 而应该是由类模板实例化出的每一个真正的类各有一份,且为该实例化类定义的所有对象共享
    - 即实例化出的相同类型的类模板共享, 如下 —— `cia/cib/cic/cid` 共享一份静态成员, `cda/cdb/cdc` 共享一份静态成员
        ```
        A <int> cia, cib
        A <int> cic;
        A <double> cda, cdb, cdc;
        ```
- **类模板的递归实例化**
    - 可以使用任何类型来实例化类模板
    - 由类模板实例化产生的类也可以用来实例化类模板自身, 这种做法称之为类模板的递归实例化
    - 通过这种方法可以构建空间上具有递归特性的数据结构 (例如: 多维数组)
- **类模板扩展**
    - ***全局特化 : 对全部的类型参数做特化处理*** <p>
      又分为 *全类特化* 和 *成员特化* 两种
      - 全类特化 : 特化一个类模板可以特化该类模板所有的成员函数，相当于重新写了一个针对某种特定数据类型的具体类。


      - 成员特化: 特化不支持的成员函数
    - ***局部特化***
    - ***类型形参的缺省***
    - ***数值型的模板参数***
    - ***模板技巧***