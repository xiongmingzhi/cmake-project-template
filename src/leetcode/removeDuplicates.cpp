/**
 * @author  Created by xzy on 2024/3/16
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <iostream>
#include <vector>
#include <set>
namespace LEETCODE
{
inline int removeDuplicates(std::vector<int>& nums)
{
    std::set<int>s(nums.begin(), nums.end());
    nums.clear();
    nums.assign(s.begin(), s.end());
    return s.size();
}


}

int main()
{
    std::vector<int>nums = {1,1,2};
    int size = LEETCODE::removeDuplicates(nums);
    std::cout << "size is: " << size << "; ";
    for (int i = 0; i < size; i++)
    {
        std::cout << nums[i] << ", ";
    }
    std::cout << std::endl;
    return 0;
}