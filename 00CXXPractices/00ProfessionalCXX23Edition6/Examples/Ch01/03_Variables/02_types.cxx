import <iostream>;
import <cstddef>;
import <cuchar>;

using namespace std;

// 介绍统一初始化语法
int main()
{
	//正整数/负整数,  范围取决编译器, 一般是 4字节
	int i1{ -7 };
	signed int i2{ -6 };
	signed i3{ -5 };

	int izero {}; 
	std::cout << format (" int 类型的零初始化 {}, ", izero) << std::endl;
	std::cout << format (" int {}, signed int {}, signed {} 三者 一致", i1, i2, i3) << std::endl;

	//短整形 一般是 2字节
	short s1{ 13 };
	short int s2{ 14 };
	signed short s3{ 15 };
	signed short int s4{ 16 };

	std::cout << format("short {}, signed short {},  signed short int {}, short in {} short 必须有,  前 signed 后 int 可选", s1, s2, s3, s4) << std::endl; 


	// 长整型  一般是 4字节 
	long l{ -7L }; 

	std::cout << format("long {} , long 必须有, 前signed, 后int 可选", l) << std::endl;
	// 超长整型  范围取决于编译器, 但不低于 长整型一般是 8字节 
	long long ll{ 14LL };
	std::cout << format("long long {} , long long 必须有, 前signed, 后int 可选", ll) << std::endl;


	//对 上述类型限制,  使其值 大于等于 0 
	unsigned int ui{ 2U };
	unsigned uj{ 5U };
	unsigned short us{ 23U };
	unsigned long ul{ 5400UL };
	unsigned long long ull{ 140ULL };

	std::cout << format("unsigned int {} , unsigned {}, unsigned short {}, unsigned long {}, unsigned long long {} ", ui, uj, us, ul, ull) << std::endl;

	float f{ 7.2f };
	std::cout << format("float {} , 浮点型数字", f) << std::endl;

	double d{ 7.2 };
	std::cout << format("long long {} , 双精度数字, 精度不低于float", d) << std::endl;

	long double ld{ 16.98L };
	std::cout << format("double {} , 长双精度数字, 精度不低于double", ld) << std::endl;

	char ch{ 'm' };
	unsigned char unchar { 'm'};
	signed char signchar {'m'};

	std::cout << format("char {}, unsigned char {}, signed char {},  单个 n位 UTF-n编码的Unicode字符, n 可以是 8, 16,32", ch, unchar,signchar) << std::endl;



	char8_t c8{ u8'm' };
	char16_t c16{ u'm' };
	char32_t c32{ U'm' };
	// TODO: 此处似乎无法使用format 进行输出 
	//std::cout << format("char8_t {}, char16_t {}, char32_t {}, char类型 与 signed char 和 unsigned char 类型是 完全不同的类型, char 只应该用来表示字符,  根据编译器不同, 有可能有符号,或者无符号", c8,c16,c32) << std::endl;

	wchar_t w{ L'm' };
	//std::cout << vformat("wchar_t {} , 单个宽字符, 大小取决于 编译器", std::make_wformat_args(w)) << std::endl;
	std::wcout << "宽字符暂时这么输出 Ninja:" <<  w << std::endl;
	bool b1{ true };
	std::cout << format("b1 {} , 布尔类型, 取值为true 或  false", b1) << std::endl;
	

	std::byte b2{ 42 };
	//std::cout << format("std::byte{} , 内存中的 单个字节 <cstddef> 提供 std::type 类型 ;  C++17 之前是 通过char 或 unsigned char 来表示一个字节", b2) << std::endl;













}
