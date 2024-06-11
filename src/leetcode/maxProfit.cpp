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

inline int maxProfit(std::vector<int>& prices)
{
    int profit = 0;
    for (int i = 0; i < prices.size(); ++i)
    {
        int value = prices[i];
        int max_value = *std::max_element(prices.begin()+i, prices.end());
        int max_profit = max_value - value;
        if (max_profit > 0 && max_profit > profit)
            profit = max_profit;
    }
    return profit;
}

inline int maxProfit2(std::vector<int>& prices)
{
    int inf = 1e9;
    int minprice = inf, maxprofit = 0;
    for (int price: prices)
    {
        maxprofit = std::max(maxprofit, price-minprice);
        minprice = std::min(minprice, price);
    }
    return maxprofit;
}

inline int maxProfit3(std::vector<int>& prices)
{
    //贪心算法的核心思想就是局部最优代替全局最优
    int sum = 0;
    for (int i = 1; i < prices.size(); ++i) {
        // 上涨就购买
        if (prices[i] - prices[i - 1] > 0) sum += prices[i] - prices[i - 1];
    }
    return sum;
}


}
int main()
{
    std::vector<int> prices = {7,1,5,3,6,4};
    //std::vector<int> prices = {7,6,4,3,1};
    std::cout << LEETCODE::maxProfit2(prices) << std::endl;
    return 0;

}