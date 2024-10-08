#include <iostream>
#include <vector>
using namespace std;
/**
 * 有序数组的平方
 * 最大值 一定在 数组的两边, 不可能在中间
 */
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);  // 新数组, 默认
        for (int i = 0, j = A.size() - 1; i <= j;) {
            if (A[i] * A[i] < A[j] * A[j]) {
               result[k--] = A[j] * A[j];
               j--;
            }else{
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};