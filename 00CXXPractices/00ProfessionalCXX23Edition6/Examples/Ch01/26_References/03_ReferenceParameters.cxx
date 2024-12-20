void addOneA(int i)  // 值传递  整形参数
{
	i++;  // Has no real effect because this is a copy of the original
}

void addOneB(int& i) // 引用传递, 整形引用参数
{
	i++;  // Actually changes the original variable
}

void swap(int& first, int& second)
{
	int temp{ first };
	first = second;
	second = temp;
}

int main()
{
	int myInt{ 7 };
	addOneA(myInt);    // 两种调用上 没有区别
	addOneB(myInt);



	int x{ 5 }, y{ 6 };
	swap(x, y);

	//  swap(3, 4); // DOES NOT COMPILE

	int* xp{ &x }, * yp{ &y };    // 当 只有 指针但函数 只能接收 引用,  通过指针 进行解引用 
	swap(*xp, *yp);
}


/**

	 值传递版本 可接收 字面量 不报错 
	 引用传递版本 无法接收字面量, 除非 通过const 引用  ; 


*/ 