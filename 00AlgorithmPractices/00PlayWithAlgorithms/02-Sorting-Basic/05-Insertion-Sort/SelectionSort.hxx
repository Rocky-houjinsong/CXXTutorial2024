//
// Created by liuyubobobo on 7/13/16.
//

#ifndef INC_04_INSERTION_SORT_SELECTIONSORT_H
#define INC_04_INSERTION_SORT_SELECTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;


template<typename T>
void selectionSort(T arr[], int n){
// 这个插入排序不对  应当是 插入后 从后往前 移动, 这个写法就是 选择排序
    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}

#endif //INC_04_INSERTION_SORT_SELECTIONSORT_H
