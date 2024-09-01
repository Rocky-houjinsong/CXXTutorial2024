#include <iostream>
#include <vector>

using namespace std;
/**
 * 前缀和 : 重复利用计算过的子数组之和, 降低区间查询需要累加计算的次数
 * 第一行输入为整数数组 Array 的长度 n，接下来 n 行，
 * 每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间，直至文件结束
 * 计算区间和的 问题上  很有用
 * 原数组,  
 * 新数组,  需要 的 某区间 就是 在新数组 上两个元素的 差 , 无需重复计算 
 */
int main() {
    int n, a, b;
    cin >> n;
    vector<int> vec(n);
    vector<int> p(n);
    int presum = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        presum += vec[i];
        p[i] = presum;
    }

    while (cin >> a >> b) {
        int sum;
        if (a == 0) {
            sum = p[b];
        } else {
            sum = p[b] - p[a - 1];
        }
        cout << sum << endl;
    }
}