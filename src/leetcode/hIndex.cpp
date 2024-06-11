/**
 * @author  Created by xzy on 2024/3/17
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <iostream>
#include <vector>
namespace LEETCODE
{
inline int hIndex(std::vector<int>& citations)
{
    std::sort(citations.begin(), citations.end());
    int ret = std::lower_bound(citations.begin(), citations.end(), 3) -citations.begin();
    return citations.size() - ret;
}

}

int main()
{
    std::vector<int>num1 = {1,3,1};
    int ret = LEETCODE::hIndex(num1);
    std::cout << ret << std::endl;
    return 0;
}