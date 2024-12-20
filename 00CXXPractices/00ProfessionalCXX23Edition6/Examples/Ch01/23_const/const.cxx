import <iostream>; 
using namespace std;



/**    const 修饰类型     */

// 等同 C语言中 define 宏定义 ;  可将任何 变量标记为 const ,  包括全局变量  和 类中的 数据成员
const int versionNumberMajor{ 2 };
const int versionNumberMinor{ 1 };
const std::string productName{ "Super Hyper Net Modulator" };
const double PI{ 3.141592653589793238462 };


/**    const 修饰类型     */

void func(const int /*param*/)
{
	// Not allowed to change param...
}

void constIntOne()
{
	const int* ip;        // 防止 指向的值被更改; 
	ip = new int[10];
	//  ip[4] = 5; // DOES NOT COMPILE!
}

void constIntTwo()
{
	int const* ip;       // 防止  指向的值被更改
	ip = new int[10];
	//  ip[4] = 5; // DOES NOT COMPILE!
}

void constPtrOne()
{
	int* const ip{ nullptr };     // 防止 ip本身被更改  
	//  ip = new int[10]; // DOES NOT COMPILE!
	ip[4] = 5;	// Error: dereferencing a null pointer
}

void constPtrTwo()
{
	int* const ip{ new int[10] };
	ip[4] = 5;
}

void constIntPtrOne()
{
	int const* const ip{ nullptr };
}

void constIntPtrTwo()
{
	const int* const ip{ nullptr };
}

void manyLevelConst()
{
	const int* const* const* const ip{ nullptr };
}

int main()
{
	int* ip;
	ip = new int[10];
	ip[4] = 5;
}





/**

		 关键字 const 是 constant 的缩写, 表示  某些内容保持不变, 编译器通过 将任何视图 将 其更改的行为标记为错误;   
		 启用优化后,   编译器可根据 此知识 来生成更好的代码; 



*/
