		import std;

using namespace std;

int main()
{
	int someInteger{ 256 };
	short someShort;
	long someLong;
	float someFloat;
	double someDouble;

	someInteger++;
	someInteger *= 2;
	// Conversion from larger integer type to smaller integer type
	// can cause a warning or error, hence static_cast() is required.
	someShort = static_cast<short>(someInteger);
	someLong = someShort * 10000;
	someFloat = someLong + 0.785f;
	// To make sure the division is performed with double precision,
	// someFloat is explicitly converted to double first.
	someDouble = static_cast<double>(someFloat) / 100000;

	cout<< format("{}", someDouble);
}


/**

1. 明确 运算符的优先级,  很多 问题出现在  运算符优先级 不明确上 ; 
2. 最好 将  复杂表达式 拆分 短小表达式或 通过 括号明确的划分  


*/