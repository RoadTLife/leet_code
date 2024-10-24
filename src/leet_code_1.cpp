/**
 * @file leet_code_1.cpp
 * @author your name (you@domain.com)
 * @brief linked https://leetcode.cn/problems/two-sum/description/
 * @version 0.1
 * @date 2024-10-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /**
         * 思路一： 对集合进行排序，然后循环每个元素item_1 ，获取sum - item_1 ,找出另外一个元素item_2大于这个跳了
         */

        map<int, int> input;
        int left, right;

        for (int i = 0, len = nums.size(); i < len; i++)
        {
            input[nums[i]] = i;
        }

        for (int i = 0, len = nums.size(); i < len; i++)
        {
            int item = target - nums[i];
            if (input.find(item) != input.end())
            {
                //两元素不能相同
                if (input[item] != i)
                {
                    right = input[item];
                    left = i;
                    break;
                }
               
            }
        }

        /**
         * 思路二：两层循环遍历硬找
         *
         */

        // int left, right;
        // for(int i = 0, len = nums.size(); i < len; i++) {
        //     int item_1 = nums[i];

        //     int item_2 = target - item_1;

        //     for(int j = 0; j < len; j++)  {
        //         if(i != j && nums[j] == item_2) {
        //             left = i;
        //             right = j;
        //         }
        //     }
        // }

        return vector<int>({left, right});
    }
};

int main()
{
    Solution s;
    vector<int> input = vector<int>({3, 2, 4});
    vector<int> res = s.twoSum(input, 6);
    std::cout << res[0] << " " << res[1] << std::endl;
    return 0;
}