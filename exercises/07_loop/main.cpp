#include "../exercise.h"

// TODO: 改正函数实现，实现正确的缓存优化斐波那契计算
// THINk: 这个函数是一个纯函数（pure function）吗？
// READ: 纯函数 <https://zh.wikipedia.org/wiki/%E7%BA%AF%E5%87%BD%E6%95%B0>
static unsigned long long fibonacci(int i) {
    // TODO: 为缓存设置正确的初始值
    // cache[0] = 0, cache[1] = 1。cached 记录当前已经算到了哪一个下标
    static unsigned long long cache[96] = {0, 1};
    static int cached = 1; 

    // 安全检查：如果请求的下标 i 已经计算过了，直接返回缓存结果
    if (i <= cached) {
        return cache[i];
    }

    // TODO: 设置正确的循环条件
    // 从下一个未计算的位置 (cached + 1) 开始，一直计算到需要的 i
    for (int j = cached + 1; j <= i; ++j) {
        cache[j] = cache[j - 1] + cache[j - 2];
    }
    
    cached = i; // 更新已缓存的最大索引
    return cache[i];
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    ASSERT(fibonacci(0) == 0, "fibonacci(0) should be 0");
    ASSERT(fibonacci(1) == 1, "fibonacci(1) should be 1");
    ASSERT(fibonacci(2) == 1, "fibonacci(2) should be 1");
    ASSERT(fibonacci(3) == 2, "fibonacci(3) should be 2");
    ASSERT(fibonacci(10) == 55, "fibonacci(10) should be 55");

    auto fib90 = fibonacci(90);
    std::cout << "fibonacci(90) = " << fib90 << std::endl;
    ASSERT(fib90 == 2880067194370816120, "fibonacci(90) should be 2880067194370816120");
    return 0;
}
