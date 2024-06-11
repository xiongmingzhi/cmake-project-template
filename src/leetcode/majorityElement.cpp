/**
 * @author  Created by xzy on 2024/3/16
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <iostream>
#include <vector>
namespace LEETCODE
{
int mooreVoting(std::vector<int>& nums)
{
    int candidate = -1;
    int count = 0;
    for (int num : nums) {
        if (num == candidate)
            ++count;
        else if (--count < 0) {
            candidate = num;
            count = 1;
        }
    }
    return candidate;
}

}


int main() {
    std::vector<int> nums = {2, 2, 3, 4, 7, 6};
    int result = LEETCODE::mooreVoting(nums);
    if (result != -1) {
        std::cout << "出现次数超过一半的元素是: " << result << std::endl;
    } else {
        std::cout << "没有元素出现次数超过一半" << std::endl;
    }

    return 0;
}
