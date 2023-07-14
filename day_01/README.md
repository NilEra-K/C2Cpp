# Day 01

**命名空间** <p>
为什么要划分命名空间——
C语言在逻辑空间上的划分只有**局部域**和**全局域** , **C++ 为了划分逻辑单元 , 避免名字冲突** , 提出命名空间的概念 <p>
命名空间可以划分更精细的逻辑空间(单元), 能够有效避免名字冲突的问题 <p>
命名空间是**可以进行拆分**的, 在编译时会被编译器自动合并, 之所以可以拆分, 是为了方便进行**协同开发**

**如何使用命名空间 ?**
- 作用域限定符 `::`
    - **优点 :** 高可靠性
    - **缺点 :** 编码较为麻烦, 每个名字前都需要加一个作用域
- 命名空间指令: `deruse.cpp`
    - _**`using namespace _name_`**_
- 命名空间声明: `impname.cpp`
    - **优点 :** 编码方便
    - **缺点 :** 低可靠性

**命名空间嵌套** <p>
命名空间并不只有一层, C++允许定义多层命名空间
- 内层标识符于外层同名标识符为隐藏关系
- 嵌套的名字需要逐层分解
```
namespace ns1{
    ...
    namespace ns2{
        ...
        namespace ns3{
            ...
        }
    }
}
```

**命名空间别名** <p>
通过命名空间别名可以简化书写
`namespace ns_four = ns1::ns2::ns3::ns4;`
