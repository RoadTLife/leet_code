#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
public:
    // 20241010 leetcode 9
    bool isPalindrome(int x)
    {
        string value = std::to_string(x);
        for (int i = 0, len = value.length(); i < len / 2; i++)
        {
            if (value[i] != value[len - i - 1])
                return false;
        }
        return true;
    }
};