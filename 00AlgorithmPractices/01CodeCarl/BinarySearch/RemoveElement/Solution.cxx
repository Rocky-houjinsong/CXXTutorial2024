#include <iostream>
#include <vector>
using  namespace std;
/**
 * 问题: 给定 数组 vector , 删除其中 特定元素值为val的元素, 返回 新数组的长度
 * 暴力循环 效率低下
 */
class Solution{
public :
    int removeElement(vector<int> &nums, int val){
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val){
                //Find 需要移动的元素, 向前集体移动一位
                // 很好的说明: 数组的删除 本质是  覆盖 
                for(int j = i + 1; j < size; j ++){
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
            
        }
        return size;
    }
};