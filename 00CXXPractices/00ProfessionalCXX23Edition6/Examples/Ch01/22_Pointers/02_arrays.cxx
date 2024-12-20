int main()
{
	int arraySize{ 8 };
	int* myVariableSizedArray{ new int[arraySize] };    //  指针变量 仍在栈中, 但动态创建到数组在 自由存储区中   
	myVariableSizedArray[3] = 2;			// 已分配内存后, 可将 该变量 当做 基于栈的普通数组使用 
	delete[] myVariableSizedArray;         // delete 操作是 删除 在自由存储区中 开辟的内存  ; 
	myVariableSizedArray = nullptr;
}

/**
	动态 分配的数组   
	自由存储区 可用于 动态分配数组, 使用new[] 操作符可给数组 分配内存

	 避免 使用C中的 malloc 和 free 函数, 优先使用C++ 中的 new , new[] delete, delete[] ;  


	 C++中 每次调用 new时, 都必须相应的调用 delete; 每次调用new[]时,. 都必须相应的调用delete[];  
	 避免内存泄漏 ;  
	 new是 在 自由存储区中开辟 内存区域, 指针指向它 ;  
	 后续不用, 先释放  内存,后 重置 指针;  

	 流程上 :创指针,  创内存,  操作指针, 操作内存 ;  删内存, 删指针 ; 

*/ 