import std;

using namespace std;

void printIntArr(const int arr[], size_t size)
{
	for (size_t i{ 0 }; i < size; ++i) {
		print("{} ", arr[i]);
	}
	println("");
} 
/**

 将一个 整数数组 分为 两个数组的函数 : 分别存放奇数 和 偶数 
*/
void separateOddsAndEvens(const int arr[], size_t size, int** odds,
	size_t* numOdds, int** evens, size_t* numEvens)
{
	// Count the number of odds and evens
	*numOdds = *numEvens = 0;
	for (size_t i = 0; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			++(*numOdds);
		} else {
			++(*numEvens);
		}
	}

	// Allocate two new arrays of the appropriate size.
	*odds = new int[*numOdds];
	*evens = new int[*numEvens];

	// Copy the odds and evens to the new arrays
	size_t oddsPos = 0, evensPos = 0;
	for (size_t i = 0 ; i < size; ++i) {
		if (arr[i] % 2 == 1) {
			(*odds)[oddsPos++] = arr[i];
		} else {
			(*evens)[evensPos++] = arr[i];
		}
	}
}

int main()
{
	int unSplit[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int* oddNums{ nullptr };
	int* evenNums{ nullptr };
	size_t numOdds{ 0 }, numEvens{ 0 };

	separateOddsAndEvens(unSplit, std::size(unSplit), &oddNums, &numOdds, &evenNums, &numEvens);

	printIntArr(oddNums, numOdds);
	printIntArr(evenNums, numEvens);

	delete[] oddNums; oddNums = nullptr;
	delete[] evenNums; evenNums = nullptr;

	//调用方 负责删除 创建的两个 数组
}



/**
			指针 和  引用的 比较 
1. 引用  更简洁, 更易于理解,更安全;  无 空引用, 不需要 显式解引用, 不会遇到与指针相关的任何解引用错误; 


2. 指向对象的指针, 和 指向对象的 引用 都支持  多态性 ;  
3. 某些情况 需要使用指针:  
 00 需要更改其 指向的位置  -->  动态分配内存, 需要 将 指向结果的指针存储在 指针而不是引用中 例如链表;  
 01 指针是 optiona的, 即 当它可以为nullptr时,  需要使用指针; 
 02 将多态类型 存储在容器中 



*/
