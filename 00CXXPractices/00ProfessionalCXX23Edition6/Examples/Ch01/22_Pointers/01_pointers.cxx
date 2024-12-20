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
		int* myIntegerPointer{ nullptr };
		if (!myIntegerPointer) { /* myIntegerPointer is a null pointer */ }
		myIntegerPointer = new int;
		*myIntegerPointer = 8;
		delete myIntegerPointer;
		myIntegerPointer = nullptr;
	}

	/**
		 指针 并非 总是指向 自由存储区内存, 让  指针 指向 某个变量,  可使用 取址 & 运算符

	*/

	{
		int i{ 8 };
		int* myIntegerPointer{ &i };  // Points to the variable with the value 8
	}

	/**
		C++ 使用  特殊语法 处理 指向 结构体或 类的指针;  
		* 对指针 解引用 ; 
		. 语法 访问 其中的字段 

	*/

	{
		Employee* anEmployee{ new Employee{ 'J', 'D', 42, 80'000 } };
		
		println("{}", (*anEmployee).salary);      //TODO: 此处存在优先级的问题,  . 大于  * , 但 逻辑上是 需要 对指针解引用,然后 访问字段 ,所以需要在解引用阶段 括号括起来, 提高 优先级
		println("{}", anEmployee->salary);        // 另一种  直观的方式,  ->  运算符 , 允许 同时对指针 解引用并访问字段
		
		bool isValidSalary1{ anEmployee && anEmployee->salary > 0 };   //结合 短路逻辑;   先判断指针是否无效, 再 解引用 访问字段
		bool isValidSalary2{ anEmployee != nullptr && anEmployee->salary > 0 };

		delete anEmployee; anEmployee = nullptr;
	}
}


/**
	
	动态内存  允许所创建的程序 具有 在编译期间 大小可变的数据




*/
