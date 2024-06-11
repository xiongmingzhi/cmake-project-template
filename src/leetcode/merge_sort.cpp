/**
 * @author  Created by xzy on 2024/3/15
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <iostream>
#include <vector>
namespace LEETCODE
{

inline void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    for (int i = 0; i != n; ++i) {
        nums1[n + i] = nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}



}

int main()
{
//    std::vector<int>num1 = {1,2,3,0,0,0};
//    std::vector<int>num2 = {2,5,6};
    std::vector<int>num1 = {1};
    std::vector<int>num2 = {};

    int m = num1.size();
    int n = num2.size();
    LEETCODE::merge(num1, m, num2, n);
    for(int i = 0; i<num1.size(); ++i)
    {
        std::cout << num1[i] << ", ";
    }
    std::cout << std::endl;
    return 0;
}