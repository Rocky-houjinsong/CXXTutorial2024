#include<iostream>
#include<vector>
using namespace std;          // vector need
// 074 二分查找问题  OK 
//版本一
/**提供一个 有序且元素唯一的左闭右闭有限数组, 若 目标值target 若在 返回 数组的下标值, 否则返回 -1
 * 
 * 要点 : 迭代终止条件如何判断, 是否需要 <= 
 *        上次 判断二分后, 下一次的 所有区间临界值 如何设定?  
 * 
 */
class Solution {
public:
    int search(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭区间内
        while(left <= right){ // left == right 区间[left,right] vaild ,所以 <=
            int middle = left + ((right - left) /2 ); // 避免 溢出 等同 (right + left) /2
            
            if (nums[middle] > target){
                right = middle -1;
            }else if(nums[middle]  < target){
                left = middle + 1;
            }else{
                return middle;    // 找到目标值, 返回下标
            }
            
        }
        return -1; // 约定: 未找到目标值 返回  -1
    }
};