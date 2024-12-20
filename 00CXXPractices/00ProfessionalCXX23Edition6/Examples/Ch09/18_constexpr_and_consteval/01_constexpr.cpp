import <iostream>; 


using namespace std;

constexpr int getArraySize() 			// 若取消 constexpr 数组定义时报错, 此时编译器 在编译期间不再认定为常量表达式 
{
	return 32;
}


void log(string_view message)
{
	std::cout << format("{}", message);
}

constexpr int computeSomething(bool someFlag)
{
	if (someFlag)
	{
		log("someFlag is true");				// constexpr函数 调用其他constexpr函数, 但不允许调用任何 非constexpr函数
		return 42;
	}
	else
	{
		return 84;
	}
}


int main()
{
	/** C++ 某些情况 必须使用常量表达式, 例如定义数组, 但 可使用 constexpr 关键字 */
	{
		int myArray[getArraySize()];	 // OK
		std::cout << format("Size of array = {}", size(myArray));
	}

	{
		int myArray[getArraySize() + 1]; // OK
		std::cout << format("Size of array = {}", size(myArray));
	}

	{
		constexpr auto value1{ computeSomething(false) };
		//constexpr auto value2{ computeSomething(true) }; // Error: doesn't compile!
		const auto value3{ computeSomething(true) };
	}
}
