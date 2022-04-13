#include <iostream>
#include "Solution.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution * solution = new Solution();
//    std::cout << 0b1100;
    char  s1[] = "ni严 my name is 陳 宇 風 だ ù ";
    std::cout << solution->count(s1)->toString();

    return 0;
}
