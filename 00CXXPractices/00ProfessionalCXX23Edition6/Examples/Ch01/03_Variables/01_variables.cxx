// NOTE: Most compilers will issue a warning or an error
// when code is using uninitialized variables. Some compilers
// will generate code that will report an error at run time.

import <iostream>;

using namespace std;

int main()
{
	int uninitializedInt;   // 未初始化
	int initializedInt{ 7 };   //  统一初始化语法

	//变量必须在 声明之后才能使用
	cout << format("{} is a random value", uninitializedInt) << endl;    // 赋予 半随机值 
	cout << format("{} was assigned an intial value" , initializedInt) << endl;


	return 0;
}

/**

	00:  变量 先声明 , 才能使用  
	01: 变量 建议先初始化,  然后使用, 否则会赋予半随机值, 往往是 Bug 来源
	02: 变量初始化,  统一初始化语法
*/
