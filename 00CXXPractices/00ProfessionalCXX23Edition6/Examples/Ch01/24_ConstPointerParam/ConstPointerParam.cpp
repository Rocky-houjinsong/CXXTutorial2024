
/**  使用 const 保护参数 */
import <string>; 
using namespace std;

void mysteryFunction(const string* someString)
{
	*someString = "Test";  // Will not compile.
}


void func(const int param) { /**  Not allow to change param  */}

int main()
{
	std::string myString{ "The string" };
	mysteryFunction(&myString);  // &myString is a string*
}


/**

	const变量  : 提供 一定程度的保护;  防止其他代码修改变量
	C++ 阻止 无意识的修改 const变量

*/
