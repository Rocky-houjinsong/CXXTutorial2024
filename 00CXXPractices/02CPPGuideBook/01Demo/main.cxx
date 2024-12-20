#include <iostream>
#include <immintrin.h>

/**
 *  一次性 处理 多个浮点运算的 小方法
 */
int main()
{
    float A[4] = { 1.0, 2.0, 3.0, 4.0 };
    float B[4] = { 5.0, 6.0, 7.0, 8.0 };
    float C[4]; 
    // SSE (Streaming SIMD Extensions) 流式单指令多数据扩展
    //每次处理4个32位浮点数
    // 在音视频处理  游戏 等 实时性要求较高的领域有 显著优势
    __m128 vecA = _mm_loadu_ps(A);  // __m :SIMD数据类型  128:128位寄存器 
    __m128 vecB = _mm_loadu_ps(B);

    __m128 vecC = _mm_add_ps(vecA, vecB);

    _mm_storeu_ps(C, vecC);
    // AVX 一次能处理  8个32位浮点数的运算
    std::cout << C[0] << std::endl;

    return 0;
}