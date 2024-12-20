#include <cstddef>

void func(int i) { /* ... */ }

int main()
{
	func(NULL);    // 此处 不是 指针,而是常来 0
	//func(nullptr); // Compilation error.   // 引入真正的 空指针常量 nullptr解决  指针含义不明(可视为 常量 0)的问题  若启用此处, 在编译 阶段就直接报错不通过
}


/**

 C++11 之前,  常量 NULL 表示 空指针.   只是简单定义为 常量 0 

*/