#include <iostream>
#include <algorithm>

using namespace std;
/*[有序区间 , 无序区间 ]

内排序中 默认当前区间首元素为区间最小值, 若 轮询发小更小,则更新最小元素的索引
轮询后, 将  无序区间中最小值 与首元素交换;  
效果等同于  在 有序区间的末尾插入一个 最大的元素, 而 无序区间去除首元素 ;  

选择排序是 位置已定, 但 元素未定 ;
*/
void selectionSort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        /* 寻找[1,n)区间中最小值 */
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            /* 内循环 */
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }

            swap(arr[i], arr[minIndex]);
            
        }
        
    }
    
}

int main(){
    
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(a,10);
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}