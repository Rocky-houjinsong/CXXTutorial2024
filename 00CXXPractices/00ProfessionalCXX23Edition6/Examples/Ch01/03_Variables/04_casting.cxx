import <iostream>; 

using namespace std;

int main()
{

	std::cout << "显示类型转换方法:\n 第一种: 来自C ,广泛使用,但不建议\n 第二种: 更自然,但 很少使用, \n 第三种:  最复杂但最整洁,推荐使用\n" ;
	float myFloat{ 3.14f };
	std::cout << format("The value of myFloat is : {}", myFloat) << std::endl;

	int i1{ (int)myFloat };                // method 1
	int i2{ int(myFloat) };                // method 2
	int i3{ static_cast<int>(myFloat) };   // method 3   

	short someShort{ 16 };
	long someLong{ someShort };          // no explicit cast needed


	std::cout << format("int i1   first method  value is {}   强制转换\n", i1);
	std::cout << format("int i2  second method  value is {} 构造函数 \n", i2);
	std::cout << format("int i3  third method  value is {}  C++语言特性,无需引入特定头文件\n", i3);

	std::cout << "左边类型 与 右边类型 完全兼容, 隐式转换 可用, 否则需强制显式转换,否则编译报错" ;


}