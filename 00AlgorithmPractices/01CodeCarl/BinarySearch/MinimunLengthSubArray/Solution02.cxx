#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution02 {
   public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = std::numeric_limits<int>::max();
        int sum = 0;        // 滑动窗口数值之和
        int i = 0;          // 滑动窗口起始位置
        int subLength = 0;  // 滑动窗口长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 每次更新 i(起始位置) 不断 比较 子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1);        //当前子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++];       // Core: 不断变更 子序列的起始位置
            }
        }
        return result == std::numeric_limits<int>::max() ? 0 : result;
    }
};