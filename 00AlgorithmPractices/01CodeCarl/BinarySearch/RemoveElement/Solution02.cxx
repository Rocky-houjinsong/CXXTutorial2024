#include <iostream>
#include <vector>
using  namespace std;
/**
 * 问题: 给定 数组 vector , 删除其中 特定元素值为val的元素, 返回 新数组的长度
 * 循环, 将 待删除元素 借助 选择排序,移动到 末位,统一删除末位即可
 * 左侧 新数组, 右侧 待删除数组 --  实现 有点绕, 且 也存在 循环浪费的问题 
 * 双指针法 很不错哦
 */
class Solution{
public :
    int removeElement(vector<int> &nums, int val){
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if (val != nums[fastIndex]){
                nums[slowIndex++] = nums[fastIndex];
            }   
        }
      
        return slowIndex;
    }
};