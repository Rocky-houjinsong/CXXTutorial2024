import <iostream> ;
import  <limits>;  // numeric_limits<type> 中  模块接口文件

using namespace std;

int main()
{

	cout << "获取数值极限信息的标准方式, 不建议C语言中的宏定义, 推荐使用定义在<limits> 中的类模板std::numeric_limits\n";
	cout << "int:\n";
	cout << format("Max int value: {}\n", numeric_limits<int>::max());
	cout << format("Min int value: {}\n", numeric_limits<int>::min());
	cout << format("Lowest int value: {}\n", numeric_limits<int>::lowest());
	
	cout <<("\ndouble:\n");
	cout << format("Max double value: {}\n", numeric_limits<double>::max());
	cout << format("无穷 double value: {}\n", numeric_limits<double>::infinity());

	cout << format("Min double value: {}\n", numeric_limits<double>::min());
	cout << format("Lowest double value: {}\n", numeric_limits<double>::lowest());

	cout << "\nWarning : min() 和 lowest() 之间的区别:  整数中 最小等于 最低 , 而 浮点类型,  最小值 该类型中的最小正数, 最低值是该类型的最小负数 即 -max()\n";

	cout << "\n浮点型数字:  \n 01 : 使用数量级不同的浮点值计算 可能会导致 错误\n 02: 计算两个 几乎相同的浮点数的差时, 会导致 精度丢失\n, 03: 很多十进制数 不能 精确的表示为 浮点数\n 04: infinity无穷,  NaN 非数字的缩写;\n <cmath> 中 std::isnan() 判断一个给定的 浮点数是否为非数字, std::isinf() 判断是否为 无穷";

	cout << "\n零初始化: 用一个 {0} 的统一初始化器 将变量 初始化为 0  ;  {} 称为 零初始化器.  将 原始的 整数类型 char, int 初始化为 0, 浮点类型 初始化为 0.0, 将指针类型 初始化为 nullptr, 将对象用默认构造函数初始化\n";
}
