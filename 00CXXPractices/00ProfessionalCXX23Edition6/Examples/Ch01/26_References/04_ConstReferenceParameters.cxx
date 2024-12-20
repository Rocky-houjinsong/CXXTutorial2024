#include <iostream>

using namespace std;

void printString(const string& myString)
{
	std::cout << format("{}\n", myString);
}

int main()
{
	string someString{ "Hello World" };
	printString(someString);
	printString("Hello World");  // Passing literals works    这里 是输入字面量, 如果不是const 引用的话, 则报错 
}

/**
     const引用传递  

      值传递: 生成副本,  但不修改 原始变量    慢 而不变 
      引用传递: 值传递指向原始对象的指针, 无副本, 但 会修改原始副本 快 而变 

      const引用传递:  快而不变;   不生成任何副本, 且无法更改原始变量

	引用 作为返回值  

	函数也可以返回引用 , 

	只有 在函数终止后返回的引用所指向的变量 继续存在的情况下 才能使用此方法 ;  

	切勿返回作用域为 函数内部的局部变量的引用 

	返回引用的 主要原因是:  能够直接把  返回值作为左值 对其赋值, 几个重载运算符 通常会 返回引用 += , -= 等 



*/