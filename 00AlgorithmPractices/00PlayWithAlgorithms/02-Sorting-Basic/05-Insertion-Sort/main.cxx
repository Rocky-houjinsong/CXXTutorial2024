#include <iostream>
#include <algorithm>
#include "SortTestHelper.hxx"
#include "SelectionSort.hxx"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1 ; i < n ; i ++ ) {

        // 寻找元素arr[i]合适的插入位置
        // 写法1
//        for( int j = i ; j > 0 ; j-- )
//            if( arr[j] < arr[j-1] )
//                swap( arr[j] , arr[j-1] );
//            else
//                break;

        // 写法2
        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
            swap( arr[j] , arr[j-1] );

    }

    return;
}

// 比较SelectionSort和InsertionSort两种排序算法的性能效率
// 此时， 插入排序比选择排序性能略低
int main() {

    int n = 20000;

    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;

    return 0;
}