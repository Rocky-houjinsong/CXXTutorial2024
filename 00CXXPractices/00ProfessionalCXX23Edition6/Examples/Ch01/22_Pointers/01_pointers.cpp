import std;

using namespace std;

struct Employee {
	char firstInitial;
	char lastInitial;
	int  employeeNumber;
	int  salary{ 75'000 };
};

int main()
{
	{
		int* myIntegerPointer{ nullptr };    //  将一个 整数放到自由存储区, 需要为其分配内存, 首先需要 声明一个 指针   ; 
											// * 表示 所声明的变量引用/指向 某个整数内存.   可将指针 视为 指向 动态分配自由存储区内存的一个箭头; 
											// 未经过初始化的指针会指向 内存中的某个随机位置,  可能会使程序崩溃.  基本上都是 同时 声明 和 初始化指针的原因;
											// 所以 , 不希望 理解分配内存, 初始化 是 置为 空指针 nullptr 
		if (!myIntegerPointer) { /* myIntegerPointer is a null pointer */ }   // 空指针 特殊, 在布尔表达式 中  被转化为 false
		myIntegerPointer = new int;     // new操作符 分配内存  ;  指针 指向 一个整数值的地址. 为 访问 这个值,  需要对 指针 解引用.  
										// 解引用:  沿着 指针箭头 寻找自由存储区中 实际的值
		*myIntegerPointer = 8;			// 给 自由存储区中 新分配的整数 赋值  8  ; 此处  并非将 myIntegerPointer 的值 设为 8 , 并没有改变指针, 而是 改变指针所指向的内存;
		delete myIntegerPointer;		// 使用完  动态分配的内存后,  delete 释放内存 同时 将 指针设置为 nullptr 
										// *myIntegerPointer  就是 指针 解引用; 为访问这个值, 需要 指针解引用, 前提是 该指针 必须初始化, 否则 程序可能崩溃  也可能继续运行, 但会给出奇怪的结果 
		myIntegerPointer = nullptr;
	}


	{
		int i{ 8 };
		int* myIntegerPointer{ &i };  // Points to the variable with the value 8
	}


	{
		Employee* anEmployee{ new Employee{ 'J', 'D', 42, 80'000 } };
		
		println("{}", (*anEmployee).salary);
		println("{}", anEmployee->salary);
		
		bool isValidSalary1{ anEmployee && anEmployee->salary > 0 };
		bool isValidSalary2{ anEmployee != nullptr && anEmployee->salary > 0 };

		delete anEmployee; anEmployee = nullptr;
	}
}


/**
	
	动态内存  允许所创建的程序 具有 在编译期间 大小可变的数据 ;  大多复杂程序都会 以某种方式 使用动态内存 ;


	1. 栈 和 自由存储区 
	C++ 程序 中的内存 分为 2部分 : 栈Stack  , 自由存储区 free store 

	栈 为 每个函数 提供独立的存储空间;  在 栈上分配的内存 不需要手动释放内存, 自动完成;  

	自由存储区 是 与 当前 函数或 栈帧 完全独立的内存区域, 若在函数调用结束后 仍然保存其中的声明的变量, 可以将 变量放到 自由存储区中  ;
	自由存储区 不如 栈 复杂,  可以将它 当做  有一堆位,  程序可在任何时候 向 其中添加 新的位或  修改已有的位;  
	必须确保 释放(删除) 在自由存储区上分配的任何内存 , 这个过程不是自动完成,除非使用 智能指针;    


	通过  显示分配内存的方式, 将 任何东西 放到 自由存储区;   




*/
