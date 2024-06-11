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
inline bool canJump(std::vector<int>& nums)
{
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) return false;
        k = std::max(k, i + nums[i]);
        int a = 0;
    }
    return true;
}

inline int jump(std::vector<int>& nums)
{
    int maxpos = 0, n = nums.size(), end =0, step=0;
    for (int i = 0; i < n-1; ++i) {
        if(maxpos >= i)
            maxpos = std::max(maxpos, i+nums[i]);
        if (i == end)
            end = maxpos;
            ++step;
    }
    return step;
}


}

int main()
{
    std::vector<int>nums = {2,3,1,1,4};
    //std::vector<int>nums = {1};
    bool b = LEETCODE::canJump(nums);
    return 0;
}