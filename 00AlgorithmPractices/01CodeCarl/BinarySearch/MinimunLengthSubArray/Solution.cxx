#include <iostream>
#include <limits>  //std::numeric_limits<int> need
#include <vector>
using namespace std;
/**
 * 给定一个含有n个正整数的数据库和一个正整数s，
 * 确定该数据库满足其和≥s的长度最小的连续子数据库，并返回其长度。
 * 如果不存在符合条件的子数据库，返回0 。 ------------>滑动窗口
 * 两种比较:序列和比较, 序列总数比较
 */
class Solution {
   public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = std::numeric_limits<int>::max();  // INT32_MAX;  最终的结果
        int sum = 0;                                   // 子序列的数值之和
        int subLength = 0;                             // 子序列的长度
        for (int i = 0; i < nums.size(); i++) {         //设置 子序列起点为 i
            sum = 0;
            for (int j = i; i < nums.size(); j++) {     //设置子序列的终止位置 为 j
                sum += nums[j];
                if (sum >= s) {
                    subLength = j - i + 1;
                    result = result < subLength ? result : subLength;
                    break;
                }
            }

            return result == std::numeric_limits<int>::max() ? 0 : result;
        }
    }
};