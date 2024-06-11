/**
 * @author  Created by xzy on 2024/3/16
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <iostream>
#include <vector>

namespace LEETCODE {

inline void rotate(std::vector<int> &nums, int k) {
    int n = nums.size();
    std::vector<int> newArr(n);
    for (int i = 0; i < n; ++i) {
        newArr[(i + k) % n] = nums[i];
    }
    nums.assign(newArr.begin(), newArr.end());
}
}

int main()
{
    //std::vector<int>nums = {1,2,3,4,5,6,7};
//    LEETCODE::rotate(nums, 3);
    std::vector<int>nums = {-1,-100,3,99};
    LEETCODE::rotate(nums, 2);
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i]<<", ";
    }
    std::cout << std::endl;

}