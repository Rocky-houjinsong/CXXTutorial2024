#include "ClassTest.cxx"

int main(){
    puts("InTo Main"); //进入Main函数
    ClassTest c;       // 进入ClassTest的构造函数中 c 是 自动存储周期, 栈上 局部变量
    puts("Outto Main"); // 离开Main函数
}                       // 析构ClassTest函数


                                                         /* 自动存储周期 */
void func() {
    ClassTest a; // a 是 自动存储周期 变量被定义时 构造
}           // 变量所在的{} 代码块执行到} 时调用

                       /* 动态 存储周期*/
void func2() {
    ClassTest  *p = new ClassTest;  // *p 是 动态存储周期 变量通过 new创建时 调用  p是 栈上变量, p 指向的 *p是 堆上对象 
    delete p;                     // 释放动态分配的内存  p 是自动存储, *p是 动态存储
    /*
        1. 指针本身,  和  指针指向的对象  是 两个 东西, 不可混淆
        2. p 自动会随着 func2的} 而析构, 但 该指针指向的对象 类型是 ClassTest *, 是一个 C语言原始指针, 无析构函数, 需手动delete 才会 释放分配的内存
        new :  内存分配 +  对象构造
        delete : 对象析构 +  内存释放  ------------> 手动new的 对象 是否都需要 手动 delete? 

    */
}
                                /* 静态存储周期 */

namespace hello {
    
    // static 和 inline 仅 影响 符号可见性, 而非 存储周期 
    ClassTest s;                        //s 静态存储周期    --  程序启动时(Main函数之前), DLL是 首次加载时  构造 ;  在 程序退出时 析构
    static ClassTest ss;                //ss 静态存储周期
    inline ClassTest sss;               //sss 静态存储周期

}

    ClassTest s;  // s 静态存储周期    --  程序启动时(Main函数之前), DLL是 首次加载时  构造 ;  在 程序退出时 析构
static ClassTest ss;  // ss 静态存储周期
inline ClassTest sss;  // sss 静态存储周期
