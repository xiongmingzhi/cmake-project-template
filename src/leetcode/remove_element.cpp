/**
 * @author  Created by xzy on 2024/3/16
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <iostream>
#include <vector>
#include <list>
namespace LEETCODE
{

inline int remove_element(std::list<int>& nums, int val)
{
   for(std::list<int>::iterator it = nums.end(); it != nums.begin();)
   {
       if(*(--it) == val)
       {
           nums.erase(it);
       }
   }
    return nums.size();
}

inline int remove_element(std::vector<int>& nums, int val)
{
    for(std::vector<int>::iterator it = nums.end(); it != nums.begin();)
    {
        if(*(--it) == val)
        {
            nums.erase(it);
        }
    }
    return nums.size();
}


}

int main()
{
//    std::list<int> nums = {5, 12, 2, 3};
//    int value = 3;
//    std::cout << LEETCODE::remove_element(nums, value) << std::endl;
//
//    std::list<int> nums2 =  {0,1,2,2,3,0,4,2};
//    int value2 = 2;
//    std::cout << LEETCODE::remove_element(nums2, value2) << std::endl;

    std::vector<int> nums = {5, 12, 2, 3};
    int value = 3;
    std::cout << LEETCODE::remove_element(nums, value) << std::endl;

    std::vector<int> nums2 =  {0,1,2,2,3,0,4,2};
    int value2 = 2;
    std::cout << LEETCODE::remove_element(nums2, value2) << std::endl;

}
