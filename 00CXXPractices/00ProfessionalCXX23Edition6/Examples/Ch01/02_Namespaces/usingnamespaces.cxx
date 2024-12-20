import <iostream>;

namespace mycode {   // 声明 名称空间 
	void foo()
	{
		// std::println("foo() called in the mycode namespace");     // 24年时 该函数在LLVM/Clang中未重写成模块函数
		std::cout << "foo() called in the mycode namespace" << std::endl;
	}
}

namespace MyLibraries :: NetWorking::FTP{   // 名称空间的嵌套
	void Send ()
	{
		std::cout << "Send() called in MyLibraries::NetWorking::FTP" << std::endl;
	}
}

using namespace mycode;    // using指令 显式 指明名称空间, 后续使用无需声明, 直接使用 例如 foo(); 
//using namespace MyLibraries::NetWorking::FTP;

namespace MyFTP = MyLibraries::NetWorking::FTP;   // 名称空间的别名

using namespace MyFTP;
int main()
{
	mycode::foo();	// Calls the "foo" function in the "mycode" namespace
	foo();			// implies mycode::foo();
	Send();
}


/**
	[[00 名称空间的]]

名称空间存在 : 处理不同代码段之间的 名称冲突问题;

当前项目中 引入 两个头文件A 和 B; 均存在 某个常数 C, 导致  命名冲突,是 解决这个问题 ;
注意, 如果  某头文件 重复导入也会报  命名冲突/重复引用错误, 走extern 关键字解决; 

:: 作用域解析运算符; , 在 函数名称使用之前 给出 名称空间  

namespace <namespace-name> {
	// 包裹 该名称空间下的 变量 函数等 ;
}

 同一 名称空间下的任何代码 都可调用该名称空间下的其他代码, 而不需要显式说明该名称空间, 
 隐式的 名称空间 使得代码清晰可读; 

 可使用 using 指令 避免 预先指明 名称空间;  



 一个源文件中  不可过度使用 名称空间,  实际上就是  完全取消名称空间;  


 若使用 两个 同名的 名称空间, 就 再次出现 名称冲突的问题;  

 using  namespace std;   // 引入 std名称空间下所有内容; 

 using namespace std::cout;  // 引入 std名称空间下 特定项;    则 cout 可直接使用, 但 std的其他项目需显式说明 

 所以,  基本要求 不可在  全局作用域的头文件中 使用using 指令或  using声明, 否则  添加此 头文件的每个人都必须使用它;  
 越是底层的 类库, 建议不要使用using 指令 ;  
 将 using指令 放到 模块接口文件中 是 不错的, 但只要不将它 导出 就行 ;   


 名称空间的 嵌套  ;  

 每个名称空间之间 由 双冒号 隔开 

 名称空间的 别名 为 另一个名称空间指定一个更简短的新名称;

*/