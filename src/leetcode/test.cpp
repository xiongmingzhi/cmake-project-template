/**
 * @author  Created by xzy on 2024/3/18
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <iostream>
#include <vector>
namespace LEEDCODE
{

inline std::vector<std::vector<int>> rotate(std::vector<std::vector<int>>& matrix)
{
    std::vector<std::vector<int>>ret;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j <n; ++j) {
            ret[i][m-j] = matrix[n-i][j];
        }

    }
    return ret;

}


}

int main()
{
    std::vector<std::vector<int>> value ={
            {1,2,3},
            {4,5,6},
            {7,8,9}};
}
