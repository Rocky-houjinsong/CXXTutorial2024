#include <iostream>

using namespace std;

string getString()
{
	return "Hello world!";
}

int main()
{
	int x{ 3 }, y{ 4 }, z{ 5 };
	int& xRef{ x };							// 引用变量 必须在 创建时  被初始化
	xRef = 10;
	//  int& emptyRef; // DOES NOT COMPILE!    // 此处报错: 创建时 没有初始化, 
	std::cout << format("引用变量xRef 创建并初始化 值: {},所指向的 变量x 的值: {}\n",xRef,x);
	xRef = y; // changes value of x to 4. Doesn't make xRef refer to y.   // 引用一旦创建, 无法修改;  引用 始终指向 它初始化时 的那个变量,    此处 将变量  赋值 给 引用 , 则 引用所指向的 变量会 更为该 赋值的比那辆的值 
	std::cout << format("引用变量xRef一旦创建,无法修改;始终指向 它初始化时 的那个变量x,将变量y  赋值 给xRef 值{} , x 值 {}\n",xRef, x);
	// xRef = &y;  // DOES NOT COMPILE!    &y是 一个指针, xRef 是 对int的 引用,不是 对指针的引用 




	int& zRef{ z };
	zRef = xRef; // Assigns values, not references 
	std::cout << format("会将 第一个引用xRef 执行 第二个引用 zRef指向的变量z吗?\n 一旦引用初始化为  引用特定变量, 就无法将 引用更改为 引用另一变量, 只能更改 引用所指向的变量的值 \n",xRef, x);


	//  const 引用  
	const int& zRef2{ z };
	//  zRef2 = 4; // DOES NOT COMPILE   //  const 应用 于  int& , 阻止对 zRef 的 赋值 
	std::cout << "应用于 引用的const 比 应用于 指针的const容易, 首先 :  引用 默认 是 const  ,所以无法更改 引用的指向, 无需显式笔标记为const;\n其次:  无法创建 对 引用的 引用 ;\n  多个 间接几倍的唯一方法 是创建 对指针的引用 \n";

	std::cout << format("zRef 的值 无法直接修改, 那直接修改被引用的 z的值是否可以, 修改前: zRefs : {}  z {}\n",zRef2, z);
	z = 20; 
	std::cout << format("修改后: zRefs : {}  z {} 验证是 可以修改的 , 表明:  const 只 限制 引用本身, 不会 限制到 被引用的 内容",zRef2, z);


	//  int& unnamedRef1{ 5 };   // DOES NOT COMPILE // 不能 创建  对 未命名值的引用, 例如 整数字面量 , 除非 该引用是const值 ; 
	const int& unnamedRef2{ 5 }; // Works as expected   
	std::cout << "\n 不能创建 对 未命名值的引用,例如 数字字面量. 除非 该引用是const 引用 ";

	// string& string1{ getString() };    // DOES NOT COMPILE
	const string& string2{ getString() }; // Works as expected
	std::cout << "\n 不能创建 对 临时对象的引用, 除非 该引用是const 引用 \n";



	std::cout << "\n 指针的引用   和   引用的指针 \n";    // 可以创建 对任何类型的引用, 包括 指针类型  , 对指针的引用很少见 
	int* intP{ nullptr };
	int*& ptrRef{ intP };   // 对 指针的引用 
	ptrRef = new int;
	*ptrRef = 5;
	delete ptrRef; ptrRef = nullptr;

	int* xPtr{ &xRef }; // address of a reference is pointer to value   对 引用的 指针   
	*xPtr = 100;
	//reinterpret_cast是一种 强制类型转换, 多数是将指针从 一种类型 转换为另一种类型,无类型检查小心使用;   void*  特殊的指针类型,  表示指向某种类型的数据, 但没有特定类型的指针 可以指向任何类型的对象
	// 引用 就是别名,  常来引用就是限制在别名端 不可修改只能读取; 
	std::cout << format("取一个引用的地址 与 取该引用所指向的变量的地址得到的结果是相同的 引用地址 {} , 引用所指向的变量的地址 {}\n",
	reinterpret_cast<void*>(&xRef), reinterpret_cast<void*>(&x)) << std::endl;

	std::cout << "不能声明  对引用的 引用 或  对引用的指针 例如  int&&,  和  int&*  不允许 ! \n"


	/** 结构化绑定  与 引用  ?? 需要复习  结构化绑定部分  */
	pair myPair{ "hello", 5 };
	const auto& [theString, theInt] { myPair };  // Decompose into references-to-const
}

/**  
   C++ 中 广泛  使用引用Reference ;  
   引用是  另一个变量的别名; 
   对 引用的所有修改都会 更改其引用的变量的值. 
   可将 引用 视为 隐式指针.   省去 获取 变量地址 和 解引用的麻烦 
   可以创建 独立的 引用变量; 
   在类中  使用 引用数据成员,   接收 引用作为 函数 和 方法的参数, 并从 函数和方法  返回 引用 


*/